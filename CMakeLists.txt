cmake_minimum_required(VERSION 3.26)
project(GroupingChallenge)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(
        GroupingChallenge
        GaussianGroupingEvaluatorFactory.cpp
        GaussianGroupingEvaluatorFactory.h
        GroupingChallenge.cpp
        GroupingEvaluator.cpp
        GroupingEvaluator.h
        Optimizer.cpp
        Optimizer.h
        Point.cpp
        Point.h
        myTask/GeneticAlgorithm.cpp
        myTask/GeneticAlgorithm.h
        myTask/Individual.cpp
        myTask/Individual.h
        myTask/RandomNumberGenerator.cpp
        myTask/RandomNumberGenerator.h)
