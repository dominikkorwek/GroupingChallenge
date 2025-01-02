
#include "RandomNumberGenerator.h"

RandomNumberGenerator::RandomNumberGenerator(const int lower, const int upper,const int pointSize):
gen(std::random_device{}()),
distribGene(lower, upper),
distribCrossingPoint(1, pointSize - 1) {}

RandomNumberGenerator::~RandomNumberGenerator() = default;

int RandomNumberGenerator::generateGene() const {
    return distribGene(gen);
}

double RandomNumberGenerator::generateProbability() const {
    std::uniform_int_distribution<> distribProbability(0, 100);
    return distribProbability(gen)/100.0;
}

int RandomNumberGenerator::getRandomCrossingPoint() const{
    return distribCrossingPoint(gen);
}

int RandomNumberGenerator::getRandomIndividualIndex(int populationSize) const {
    std::uniform_int_distribution<> distribIndividualIndex(0, populationSize - 1);
    return distribIndividualIndex(gen);
}
