#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>

using namespace std;

/* VECTOR HELPER FUNCTIONS */
void print_vector(vector<double> &vec);
double vector_magnitude(vector<double> &vec);
double vector_dot_product(vector<double> &vecA, vector<double> &vecB);
vector<double> vector_add(vector<double> &vecA, vector<double> &vecB);
vector<double> vector_sub(vector<double> &vecA, vector<double> &vecB);
vector<double> vector_mul_scalar(vector<double> &vec, double scalar);
vector<double> vector_div_scalar(vector<double> &vec, double scalar);
/* VECTOR HELPER FUNCTIONS END */

#endif
