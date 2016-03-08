#include <iostream>
#include <vector>
#include <cstdlib>

#include <iostream>
#include <cstdlib>

static float random_float(int limit){
	float ret = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX /
    limit));
	return ret;
}
