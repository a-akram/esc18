---
title: Memory issues
layout: main
category: cpp
---

The goal of this exercise is to understand what are the main issues when dealing
with _owning_ raw pointers and how tools like `valgrind` or an _Address
sanitizer_ can help identify them.

# Exercise: Valgrind

[Valgrind](http://valgrind.org/) is an instrumentation framework
for dynamic analysis tools. At this school we use the tools for checking
memory management bugs, but it includes many other tools such as for
finding threading bugs and analysing cache access patterns. This
exercise will introduce you to the basic mechanics of using Valgrind.

Build [`memerrors.cpp`]({{site.exercises_repo}}/hands-on/cpp/memerrors.cpp):

    [student@esc ~]$ cd esc18/hands-on/cpp
    [student@esc cpp]$ g++ -g -o memerrors memerrors.cpp

Run the test program under valgrind:

    [student@esc cpp]$ valgrind ./memerrors

Note how `valgrind` points to the source code when it finds some anomaly.
Re-build the executable without using the `-g` option and check the
consequences in the valgrind output.

Did `valgrind` identify all the errors?

The compiler can sometimes warn us about problems in our code:

    [student@esc cpp]$ g++ -g -Wall -Wextra -o memerrors memerrors.cpp

# Exercise: memory sanitizers

The compiler can instrument the code so that at run-time a number of checks can
be performed and, in case an anomaly is detected, a diagnostic can be issued.

Here we introduce just the currently available memory sanitizers.

    [student@esc cpp]$ g++ -fsanitize=address -g -Wall -Wextra -o memerrors memerrors.cpp
    [student@esc cpp]$ ./memerrors
    [student@esc cpp]$ g++ -fsanitize=leak -g -Wall -Wextra -o memerrors memerrors.cpp
    [student@esc cpp]$ ./memerrors

Note how the sanitizers report fewer errors than `valgrind`.`

# Exercise: memory issues

Build and run, directly and through `valgrind`/_memory sanitizers_, the
following small programs:

* [`non_owning_pointer.cpp`]({{site.exercises_repo}}/hands-on/cpp/non_owning_pointer.cpp). Uncomment the lines containing calls to
  `free` or `delete` and see what the consequences are at run-time
* [`array_too_small.cpp`]({{site.exercises_repo}}/hands-on/cpp/array_too_small.cpp)
* [`leak.cpp`]({{site.exercises_repo}}/hands-on/cpp/leak.cpp). Comment the allocations and see what the consequences
  are at run-time
* [`double_delete.cpp`]({{site.exercises_repo}}/hands-on/cpp/double_delete.cpp)
* [`missed_delete.cpp`]({{site.exercises_repo}}/hands-on/cpp/missed_delete.cpp). Uncomment the lines about the `try`/`catch`
  block and position them in different places; see what the
  consequences are at run-time

Try and fix the problems.

# Exercise: fix issues with resource-managing types

Adapt `non_owning_pointer.cpp`, `array_too_small.cpp`, `leak.cpp`,
`double_delete.cpp` and `missed_delete` to use resource-managing types, such as
smart pointers, to fix the memory issues.
