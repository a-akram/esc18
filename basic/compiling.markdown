---
title: How to compile
category: basic
layout: main
---

The goal of this exercise is to understand how to compile and run test programs
on `esc`. The default C++ compiler is 64-bit g++ v. 7.3.1, which by defaults
compiles in C++14 mode. To enable C++17, pass the `-std=c++17` option to the
compiler. It's also good practice to enable a high level of warnings.

Build [pi_time.cpp]({{site.exercises_repo}}/hands-on/basic/pi_time.cpp):

    [student@esc ~]$ cd esc18/hands-on/basic
    [student@esc basic]$ g++ -Wall -Wextra -std=c++17 -o pi_time pi_time.cpp
    [student@esc basic]$ ./pi_time 1000
    pi = 3.14159 for 1000 iterations in 4.6336e-05 s

Run the code multiple times with different arguments.

Compile the code with different optimization levels (`-O0` to `-O3` and
`-Ofast`) and see if the execution time changes.

Look at the code and see how `std::chrono` is used to do some basic
time measurements, thanks to its `high_resolution_clock`.

Try also to compile with `clang`:

    [student@esc basic]$ clang++ -Wall -Wextra -std=c++17 -o pi_time pi_time.cpp

and compare the results with those obtained using `g++`.
