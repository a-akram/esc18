---
title: floating point representation
layout: main
section: floatingpoint
---

In this exercises you will familiarize with basic properties of floating point represantation

1. count the number of floating points between two of them
2. extract the exponent of a float
3. produce NaN and inf, verify the value of their exponent

       #include<iostream>
       #include<iomanip>
       #include<cmath>
       #include<limits>
       #include<cstdio>
       #include<cstring>
       
       int count(float x, float e) {
              // fill in
       } 
       int exponent(float x) {
              // fill in
       }

       int main() {

         std::cout << count(.1f,1.f) << std::endl;
         std::cout << count(2.f,3.f) << std::endl;
         return 0;

       }
