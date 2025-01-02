//
// Created by user on 25.12.2024.
//

#ifndef GENETICALGORITHM_H
#define GENETICALGORITHM_H
#include <vector>

#include "GroupingEvaluator.h"
#include "Individual.h"
#include "RandomNumberGenerator.h"

using namespace std;

class GeneticAlgorithm {
public:
    GeneticAlgorithm(int populationSize, double crossProbability,
        double mutationProbability, int methodIterations,
        double calculationTimeInSeconds, int countingFitnessMethodIterations,
        const NGroupingChallenge::CGroupingEvaluator&  evaluator);
    ~GeneticAlgorithm();

    GeneticAlgorithm(const GeneticAlgorithm&) = delete;
    GeneticAlgorithm& operator=(const GeneticAlgorithm&) = delete;

    double getBestResult() const;
    void run();

private:
    int methodIterations;
    double calculationTimeInSeconds;
    int countingFitnessMethodIterations;

    int populationSize;
    double mutationProbability;
    double crossProbability;

    const NGroupingChallenge::CGroupingEvaluator* evaluator;
    const RandomNumberGenerator* rng;

    vector<Individual*> population;

    void generatePopulation();

    void countFitness() const;

    void crossPopulation();
    void mutatePopulation() const;

    pair<Individual*, Individual*> getNewIndividuals(const Individual& first, const Individual& second) const;
    void deletePopulation();
    int getBestParent() const;
    
};



#endif //GENETICALGORITHM_H
