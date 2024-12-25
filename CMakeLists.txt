cmake_minimum_required(VERSION 3.26)
project(GroupingChallenge)

set(CMAKE_CXX_STANDARD 14)

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
        Point.h)
