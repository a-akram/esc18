#include "Data.h"
#include<random>
#include<vector>
#include<cstdint>
#include<algorithm>
#include<iostream>
#include<cassert>

#include<chrono>

#include "memory_usage.h"

auto start = std::chrono::high_resolution_clock::now();

uint64_t maxLive=0;

void stop(const char * m) {
  auto delta = std::chrono::high_resolution_clock::now()-start;
  maxLive= std::max( maxLive, memory_usage::totlive() );
  std::cout << m;
  std::cout << " elapsted time (ms) " << std::chrono::duration_cast<std::chrono::milliseconds>(delta).count() << std::endl;
  std::cout << "allocated so far " << memory_usage::allocated();
  std::cout << " deallocated so far " << memory_usage::deallocated() << std::endl;
  std::cout << "total / max live " << memory_usage::totlive() << ' ' << maxLive << std::endl;
  
  start = std::chrono::high_resolution_clock::now();
}


void computeMeanZ(AOS const & v){}
void computeNN(AOS const & v){}


constexpr int N=200000;

std::mt19937 reng;
std::poisson_distribution<int> aGen(N);
std::uniform_real_distribution<float> ugen(-1.f,1.f);
std::uniform_int_distribution<int> igen(1,10);


void one(bool doprint) {
  
  // generate
  auto ntot = aGen(reng);
  AOS v(ntot);
  // VSOA vsoa(ntot);
  for ( auto & d : v) {
    d.x =  ugen(reng);
    d.y =  ugen(reng);
    d.z =  ugen(reng);
    d.vx =  ugen(reng);
    d.vy =  ugen(reng);
    d.vz =  ugen(reng);
    auto r = igen(reng);
    d.quality = r==0 ? bad : (r>5 ? strict : loose); // strict 50%
    if (r>=9) d.quality=tight; // 20%
    d.isValid = bad!=d.quality;  // 10%  (one can add some extra bad but valid...)
  }


  if(doprint) stop("after generation");

  // compute the "average" z on all "valid" elements
  computeMeanZ(v);
  if(doprint) stop("after average z");

  // compute nearest "tight" (or "strict") neighbour in x-y for all "tight" elements
  computeNN(v);
  if(doprint) stop("after NN");

  
  
}



int main() {

  one(true);
  stop("\nafter call: ");
  
  for (int i=0; i<20; ++i) {
    one(false);
    // stop("after call");
  }
  stop("\nafter loop in main: ");
  
  one(true);
  
  stop("\nat the end: ");

  
  return 0;

}

