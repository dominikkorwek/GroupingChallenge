#include "GaussianGroupingEvaluatorFactory.h"
#include "GroupingEvaluator.h"
#include "Optimizer.h"
#include "myTask/GeneticAlgorithm.h"

using namespace NGroupingChallenge;

int main(){
	CGaussianGroupingEvaluatorFactory c_evaluator_factory(50, 100);

	c_evaluator_factory
		.cAddDimension(-100, 100, 1.0, 1.0)
		.cAddDimension(-100, 100, 1.0, 1.0)
		.cAddDimension(-100, 100, 1.0, 1.0)
		.cAddDimension(-100, 100, 1.0, 1.0)
		.cAddDimension(-100, 100, 1.0, 1.0)
		.cAddDimension(-100, 100, 1.0, 1.0)
		.cAddDimension(-100, 100, 1.0, 1.0)
		.cAddDimension(-100, 100, 1.0, 1.0)
		.cAddDimension(-100, 100, 1.0, 1.0)
		.cAddDimension(-100, 100, 1.0, 1.0);

	CGroupingEvaluator* pc_evaluator = c_evaluator_factory.pcCreateEvaluator(0);

	COptimizer c_optimizer(*pc_evaluator);

    GeneticAlgorithm* gn = new GeneticAlgorithm(100, 0.1, 0.1, 5000, *pc_evaluator);
	gn->run();
    cout<<pc_evaluator->dEvaluate(gn->getBestResult());

	delete pc_evaluator;
    delete gn;

	return 0;
}