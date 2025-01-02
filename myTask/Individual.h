

#ifndef INDIVIDUAL_H
#define INDIVIDUAL_H
#include <vector>

#include "GroupingEvaluator.h"
#include "RandomNumberGenerator.h"


using namespace std;

class Individual {
public:
    explicit Individual();
    Individual(const Individual& individual);
    ~Individual();

    bool operator==(const Individual& individual) const;
    Individual& operator=(const Individual &other);

    void generate(const NGroupingChallenge::CGroupingEvaluator& evaluator,const RandomNumberGenerator& rng);
    void mutate(const RandomNumberGenerator& rng, double mutationProbability);
    pair<Individual*, Individual*> crossover(const Individual &other,const RandomNumberGenerator &rng) const;

    void countFitness(const NGroupingChallenge::CGroupingEvaluator& evaluator);

    double getFitness() const;
private:
    vector<int> genotype;
    double fitness;

    void splitGenotype(int splitIndex, Individual &first, Individual &second, const Individual &other) const;
};

#endif //INDIVIDUAL_H
