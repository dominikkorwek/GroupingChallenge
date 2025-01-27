#include "GeneticAlgorithm.h"

#include <cfloat>
#include <iostream>
#include <utility>
///                          public methods
GeneticAlgorithm::GeneticAlgorithm(const int populationSize,
    const double crossProbability,
    const double mutationProbability,
    const int methodIterations,
    const NGroupingChallenge::CGroupingEvaluator& evaluator) :
methodIterations(methodIterations),
populationSize(populationSize),
mutationProbability(mutationProbability),
crossProbability(crossProbability),
evaluator(&evaluator){
    rng = new RandomNumberGenerator(evaluator.iGetLowerBound(), evaluator.iGetUpperBound(), evaluator.iGetNumberOfPoints());
    generatePopulation();
}

GeneticAlgorithm::~GeneticAlgorithm() {
    deletePopulation();
    delete rng;
}

void GeneticAlgorithm::findBestResult() {
    auto best = bestGenotype.empty() ? DBL_MAX : evaluator->dEvaluate(bestGenotype);
    for (const Individual* individual : population) {
        const double candidate = individual->getFitness();
        if (candidate < best) {
            best = candidate;
            bestGenotype = individual->getGenotype();
        }
    }
}

void GeneticAlgorithm::run() {
    countFitness();
    while (methodIterations > 0) {
        crossPopulation();
        mutatePopulation();
        countFitness();
        findBestResult();
        --methodIterations;
    }
}

///                 private methods
void GeneticAlgorithm::generatePopulation() {
    for (int i = 0; i < populationSize; ++i) {
        auto* individual = new Individual();
        individual->generate(*evaluator, *rng);
        population.push_back(individual);
    }
}

void GeneticAlgorithm::countFitness() const{
    for (int i = 0; i < populationSize; ++i)
        population[i]->countFitness(*evaluator);
}

void GeneticAlgorithm::crossPopulation() {
    vector<Individual*> newPopulation;

    if (populationSize%2 == 1)
        newPopulation.push_back(new Individual(*population[getBestParent()]));

    for (int i = 0; i < populationSize/2; ++i ) {
        const int first = getBestParent();
        const int second = getBestParent();

        pair<Individual*, Individual*> individualsForNewPopulation = getNewIndividuals(*population[first], *population[second]);

        newPopulation.push_back(individualsForNewPopulation.second);
        newPopulation.push_back(individualsForNewPopulation.first);
    }

    deletePopulation();
    population = std::move(newPopulation);
}

void GeneticAlgorithm::mutatePopulation() const {
    for (int i = 0; i < populationSize; ++i)
        if ( rng->generateProbability() < mutationProbability)
            population[i]->mutate(*rng, mutationProbability);
}

///             private helping methods
pair<Individual*, Individual*> GeneticAlgorithm::getNewIndividuals(const Individual &first, const Individual &second) const {
    const double probability = rng->generateProbability();
    if (probability < crossProbability)
        return first.crossover(second, *rng);

    return {new Individual(first), new Individual(second)};
}

void GeneticAlgorithm::deletePopulation() {
    for (const auto & it : population)
        delete it;

    population.clear();
}

int GeneticAlgorithm::getBestParent() const {
    const int first = rng->getRandomIndividualIndex(populationSize);
    const int second = rng->getRandomIndividualIndex(populationSize);

    return population[first]->getFitness() < population[second]->getFitness() ? first : second;
}

vector<int> GeneticAlgorithm::getBestResult() const {
    return bestGenotype;
}
