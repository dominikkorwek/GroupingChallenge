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

	GeneticAlgorithm* gn = new GeneticAlgorithm(600, 0.1, 0.1, 5000, 12, 50, *pc_evaluator);

	// c_optimizer.vInitialize();
	//
	// for (int i = 0; i < 10; i++){
	// 	c_optimizer.vRunIteration();
	// }

	gn->run();

	delete pc_evaluator;

	return 0;
}