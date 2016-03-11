#include <iostream>
#include <vector>
#include <cstdlib>

#include <iostream>
#include <cstdlib>

static double random_double(int limit){
	double ret = static_cast <double> (rand()) / (static_cast <double> (RAND_MAX /
    limit));
	return ret;
}
