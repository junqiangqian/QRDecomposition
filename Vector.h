#ifndef VECTOR_H_
#define VECTOR_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>

/* Prints the given vector in the form of (x1, x2, ... xn) where n is the
   number of dimensions */
void print_vector(std::vector<double> &vec);

/* Returns the Euclidean norm of the given vector */
double vector_magnitude(std::vector<double> &vec);

/* Returns the dot product of two vectors, vecA and vecB, returns a float to
   prevent underflow */
float vector_dot_product(std::vector<double> &vecA, std::vector<double> &vecB);

/* Returns a new vector which is the addition of vecA and vecB */
std::vector<double> vector_add(std::vector<double> &vecA,
                               std::vector<double> &vecB);

/* Returns a new vector which is the subtraction of vecB from vecA */
std::vector<double> vector_sub(std::vector<double> &vecA,
                               std::vector<double> &vecB);

/* Returns a new vector in which each component of the vector is multipled by
   the scalar */
std::vector<double> vector_mul_scalar(std::vector<double> &vec, double scalar);

/* Returns a new vector in which each component of the vector is divided by
   the scalar */
std::vector<double> vector_div_scalar(std::vector<double> &vec, double scalar);

#endif
