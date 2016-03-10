#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>

using namespace std;

/* VECTOR HELPER FUNCTIONS */
void print_vector(vector<float> &vec);
float vector_magnitude(vector<float> &vec);
float vector_dot_product(vector<float> &vecA, vector<float> &vecB);
vector<float> vector_add(vector<float> &vecA, vector<float> &vecB);
vector<float> vector_sub(vector<float> &vecA, vector<float> &vecB);
vector<float> vector_mul_scalar(vector<float> &vec, float scalar);
vector<float> vector_div_scalar(vector<float> &vec, float scalar);
/* VECTOR HELPER FUNCTIONS END */

#endif
