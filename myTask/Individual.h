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
    Individual(Individual&& other) noexcept ;
    ~Individual();

    Individual& operator=(const Individual &other);
    Individual& operator=(Individual&& other) noexcept;

    bool operator==(const Individual& individual) const;

    void generate(const NGroupingChallenge::CGroupingEvaluator& evaluator,const RandomNumberGenerator& rng);
    void mutate(const RandomNumberGenerator& rng, double mutationProbability);
    pair<Individual*, Individual*> crossover(const Individual &other,const RandomNumberGenerator &rng) const;

    void countFitness(const NGroupingChallenge::CGroupingEvaluator& evaluator);

    double getFitness() const;
    vector<int> getGenotype() const;
private:
    vector<int> genotype;
    double fitness{};

    void splitGenotype(int splitIndex, Individual &first, Individual &second, const Individual &other) const;
    void moveData(Individual &other);
};

#endif //INDIVIDUAL_H
