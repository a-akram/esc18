---
title: Use of algorithms and function objects
layout: main
category: cpp
---

The goal of these exercises is to get some confidence with the C++ entities that
are _callable_: functions, function objects and lambdas. You will use them to
customize the behaviour of some of the algorithms provided by the C++ standard
library.

# Exercise 1

The program [`algo.cpp`]({{site.exercises_repo}}/hands-on/cpp/algo.cpp)
generates and prints a vector of randomly-chosen integer numbers.

Build it and run it a few times to verify that it works as
expected:

    [student@esc ~]$ cd esc18/hands-on/cpp
    [student@esc cpp]$ g++ -O3 -Wall -Wextra -o algo algo.cpp
    [student@esc cpp]$ ./algo
    [student@esc cpp]$ ./algo

Then extend the program in order to:

* sum all the elements of the vector
* compute the average of the first half and of the second half of the vector
* move the three central numbers to the beginning
* remove duplicate elements

The source code contains some hints about what algorithms can be used
to implement the requested functionality.
[cppreference.com](http://en.cppreference.com/w/) is an excellent source of
documentation for the algorithms (and C++ in general).

# Exercise 2

Modify the program [`algo_functions.cpp`]({{site.exercises_repo}}/hands-on/cpp/algo_functions.cpp) to:

* multiply all the elements of the vector
* sort the vector in descending order
* move the even numbers to the beginning
* create another vector with the squares of the numbers in the first vector
* find the first multiple of 3 or 7
* erase from the vector all the multiples of 3 or 7

For the implementation follow the hints in the source code.
