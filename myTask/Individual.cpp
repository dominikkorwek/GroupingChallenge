#include "Individual.h"

#include <cfloat>


class RandomNumberGenerator;

Individual::Individual():
fitness(DBL_MAX){}

Individual::Individual(const Individual &individual) = default;

Individual::~Individual() = default;

bool Individual::operator==(const Individual &individual) const {
    return genotype == individual.genotype;
}

Individual& Individual::operator=(const Individual &other) {
    if (this != &other) {
        genotype = other.genotype;
        fitness = other.fitness;
    }
    return *this;
}

void Individual::mutate(const RandomNumberGenerator& rng, double mutationProbability) {
    for (int & i : genotype)
        if (rng.generateProbability() < mutationProbability)
            i = rng.generateGene();
}

pair<Individual*, Individual*> Individual::crossover(const Individual &other, const RandomNumberGenerator& rng) const {
    if (this ==  &other)
        return {new Individual(*this), new Individual(other)};

    const int splitIndex = rng.getRandomCrossingPoint();
    auto* first = new Individual();
    auto second = new Individual();

    splitGenotype(splitIndex,*first,*second,other);

    return {first,second};
}

void Individual::countFitness(const NGroupingChallenge::CGroupingEvaluator &evaluator) {
    fitness = evaluator.dEvaluate(genotype);
}

double Individual::getFitness() const {
    return fitness;
}

void Individual::splitGenotype(const int splitIndex, Individual &first, Individual &second, const Individual &other) const {
    first.genotype.reserve(genotype.size());
    second.genotype.reserve(genotype.size());

    for (int i = 0; i < genotype.size(); ++i)
        if (i < splitIndex) {
            first.genotype.push_back(genotype[i]);
            second.genotype.push_back(other.genotype[i]);
        }
        else {
            first.genotype.push_back(other.genotype[i]);
            second.genotype.push_back(genotype[i]);
        }
}

void Individual::generate(const NGroupingChallenge::CGroupingEvaluator& evaluator,const RandomNumberGenerator& rng) {
    genotype.reserve(evaluator.iGetNumberOfPoints());

    for (int i = 0; i < evaluator.iGetNumberOfPoints(); ++i) {
        int gene = rng.generateGene();
        genotype.push_back(gene);
    }
}
