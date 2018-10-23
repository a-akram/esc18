---
title: Avoid memory abuse
layout: main
category: memory
---

There are two main memory abuses:
   + using to much memory (even for a very short time)
   + performing too many allocations/deallocations (memory churn)

In addition the use of "sparse" data structures may imply
   + pointer chasing (which may become computation intensive)
   + data not locality

Open [grouping.cpp]({{site.exercises_repo}}/hands-on/memory/grouping.cpp)

The exercise consists in building the relationship between elements and groups
(as in cluster algorithm for instance) so that one can find in which group an element belongs to
and can perform operations such as "compute the sum/average.." over some features of the elements in each group
(find the total charge/mass, the baricenter etc)

Only the total number of elements is given (elements numbered from 0 to N-1).
The assumption is that the groups shall be discovered in the exercise even if the "grouping" algorithm is left undefined and is FAKED by some simple assignment.

There is an assumption that the algorithm is in two steps: first it find protoGroups and then it spits (some of them) in two


Bonus:
As I coded it for test purpose, just compare the performance of "map" vs "unordered_map"
