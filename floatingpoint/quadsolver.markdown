---
title: quadratic equation solver
layout: main
section: floatingpoint
---

In this exercises you will experiment catastrofic cancellations and verify the accuracy of the solution of a quadratic equation

1. here are two of the possible implementations of the solution of the quadratic equation
       
        #include<cmath>
        #include<tuple>
        #include<limits>
       
        template<typename T>
        inline T det(T a, T b, T c) {
          // compute determinant for equation ax^2 + 2bx + c= 0
          return std::sqrt(b*b-a*c);
        }

        template<typename T>
        inline std::tuple<T,T> quadSolverNaive(T a, T b, T c) {
          // solve equation ax^2 + 2bx + c= 0
          // using naive solution (as at college)
          auto d = -T(1)/a;
          return std::make_tuple(d*(b-det(a,b,c)),d*(b+det(a,b,c)));  
        }


        template<typename T>
        inline std::tuple<T,T> quadSolverOpt(T a, T b, T c) {
          // solve equation ax^2 + 2bx + c= 0
          // using stable algorithm
          auto q = -(std::copysign(det(a,b,c),b)+b);
          return std::make_tuple(q/a,c/q);
        }
        

2. compute radius and center for a circle given chord and sagitta (simplify orientation as in the slides so y0=0)
3. use standard circle equation to recompute the value of `xt`. See for which value of the sagitta the equation _breaks-down_
4. use above solutions to recompute the value of `xt` using the "local" circle equation. See for which value of the sagitta the equation _breaks-down_

        #include<iostream>
        #include<iomanip>

        template<typename T> 
        void print(T x) {
          std::cout<< std::hexfloat << x <<' ' <<  std::scientific
          << std::setprecision(std::numeric_limits<T>::digits10+3) << x << std::endl;
        }

        template<typename T>
        void circle() {
          std::cout <<' '<< std::endl;

          constexpr T micron = 1.e-3;
          constexpr T meter = 1000.;
          constexpr T halfChord = meter/2;
 
   
          T xt = std::sqrt(T(77.));
          std::cout << "xt "; print(xt);
 
          auto sagitta = T(10.);  // make it smaller and smaller...
          auto yt=halfChord;
          // compute xm, radius and x0
	  
          // recompute xt
          // y0 = 0
          
          // standard circle eq. (x-x0)^2 +(yt-y0)^2 = r^2 ->  x = x0 - sqrt(r^2-yt^2)
          // print(xt-x);  // compare solution with actual value to get the accuracy

          // circle w/r/t local point (x-xm)^2 + (y-ym)^2  -2ar(x-xm) -2br(y-ym) = 0 ->
          // (x-xm)^2  - 2(x-xm)r + yt^2  = 0  -> x = xm + ....
          
          // print(xt-(xm+std::get<1>(solution)));  // compare solution with actual value to get the accuracy
        }

        int main() {
          
          std::cout << "\nfloat\n" << std::endl;
          circle<float>();
          std::cout << "\ndouble\n" << std::endl;
          circle<double>();
          
          return 0;
        }
