---
title: vectorize binning
layout: main
section: vectorization
---

In this exercises you will vectorize the filling of an histogram in cartesian coordinates starting from points in polar coordinates

1. start from the code in [`binning.cpp`]({{site.exercises_repo}}/hands-on/vectorization/binning.cpp)

2. modify it to use `sin` and `cos` from [`simpleSinCos.h`]({{site.exercises_repo}}/hands-on/vectorization/simpleSinCos.h)

3. optimize it to run faster in scalar mode

4. modify the code to enable auto-vectorization

5. Change the code to use gcc native-vectors

for each version compile with

* c++ -O2 -Wall -fopt-info-vec -march=native binning.cpp

* c++ -O3 -Wall -fopt-info-vec -march=native binning.cpp

* c++ -Ofast -Wall -fopt-info-vec -march=native binning.cpp

* try -funroll-loops

in case you decide to further optimize _simpleSinCos_ make sure it reproduces the results.


For a full discussion of the optimization techniques that can be used in the solution
look at the [paper by Colfax](Colfax_Optimization_Techniques_2_of_3.pdf)


Bonus: add thread parallelization with TBB


More Bonuses:
new compilers try harder: https://godbolt.org/g/1D8U2V
