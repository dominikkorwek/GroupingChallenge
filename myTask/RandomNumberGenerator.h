#ifndef RANDOMNUMBERGENERATOR_H
#define RANDOMNUMBERGENERATOR_H
#include <random>

#define MAX_PERCENT 100
#define DIVIDE_BASE 100.0

class RandomNumberGenerator {
public:
    RandomNumberGenerator(int lower,int upper, int pointSize);
    ~RandomNumberGenerator();
    int generateGene() const;
    double generateProbability() const;
    int getRandomCrossingPoint() const;
    int getRandomIndividualIndex(int populationSize) const;

private:
    mutable std::mt19937 gen;
    mutable std::uniform_int_distribution<> distribGene;
    mutable std::uniform_int_distribution<> distribCrossingPoint;
};


#endif //RANDOMNUMBERGENERATOR_H
