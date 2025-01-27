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
        const NGroupingChallenge::CGroupingEvaluator&  evaluator);
    ~GeneticAlgorithm();

    GeneticAlgorithm(const GeneticAlgorithm&) = delete;
    GeneticAlgorithm& operator=(const GeneticAlgorithm&) = delete;

    void run();
    vector<int> getBestResult() const;
private:
    int methodIterations;

    int populationSize;
    double mutationProbability;
    double crossProbability;

    const NGroupingChallenge::CGroupingEvaluator* evaluator;
    const RandomNumberGenerator* rng;

    vector<Individual*> population;
    vector<int> bestGenotype;

    void generatePopulation();
    void countFitness() const;
    void crossPopulation();
    void mutatePopulation() const;
    pair<Individual*, Individual*> getNewIndividuals(const Individual& first, const Individual& second) const;
    void deletePopulation();
    int getBestParent() const;
    void findBestResult();
};



#endif //GENETICALGORITHM_H
