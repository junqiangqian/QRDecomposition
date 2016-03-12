#include <iostream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <cstdlib>

/* Returns a random double between -limit and limit */
static double random_double(int limit){
  int a = -limit;
  double random = ((double) rand()) / (double) RAND_MAX;
  double diff = limit - a;
  double r = random * diff;
  return a + r;
}
