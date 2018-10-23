---
title: Data Locality
layout: main
category: memory
---


To see the effect of data locality on the performance of algorithms we can start from atypical data structure
as in

[Data.h]({{site.exercises_repo}}/hands-on/memory/Data.h)

Once filled, try to write and run some simple algorithms such as
   + compute the "average" z on all "valid" (or "strict") elements
   + find the nearest "tight" (or "strict") neighbour in x-y for all "tight" elements

using the various type of data representations AOS, vector-of-pointers, SOA.

in [SOAvsAOS.cpp]({{site.exercises_repo}}/hands-on/memory/SOAvsAOS.cpp)

there is a simple random generator of "Datas" and empty functions to implement the algorithms to "profile"
the Generator is implemented for a AOS, modify it to populate alternative representations.

Try also any other algorithm: it is not excluded that you will find some that are faster with a AOS or even with a
vector-of-pointers...

Note that for some algorithims using a local ad-hoc data structure may even be more profitable.

Try using multi-threading and/or on GPU.
