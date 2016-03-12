#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>

/* VECTOR HELPER FUNCTIONS */
void print_vector(std::vector<double> &vec);
double vector_magnitude(std::vector<double> &vec);
float vector_dot_product(std::vector<double> &vecA, std::vector<double> &vecB);
std::vector<double> vector_add(std::vector<double> &vecA,
                               std::vector<double> &vecB);
std::vector<double> vector_sub(std::vector<double> &vecA,
                               std::vector<double> &vecB);
std::vector<double> vector_mul_scalar(std::vector<double> &vec, double scalar);
std::vector<double> vector_div_scalar(std::vector<double> &vec, double scalar);
/* VECTOR HELPER FUNCTIONS END */

#endif
