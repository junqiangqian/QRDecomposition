#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
#include <cstdlib>
#include <cstdio>

/* Prints the matrix using spaces to separate elements and a new line to
   separate rows */
void print_matrix(std::vector<std::vector<double> > &matrix);

/* Initialises an all zero matrix with given rows and cols*/
void init_matrix(std::vector<std::vector<double> > &matrix, int rows, int cols);

/* Given a matrix, generates a symmetric matrix where every element is in
   between -limit and limit */
void generate_symmetric_matrix(std::vector<std::vector<double> > &matrix,
                               int limit);

/* Returns the matrix product of matrix A and B */
std::vector<std::vector<double> > matrix_multiply(
                                 std::vector<std::vector<double> > &A,
                                 std::vector<std::vector<double> > &B);

/* Returns the matrix transpose of the given matrix */
std::vector<std::vector<double> > matrix_transpose(
                                  std::vector<std::vector<double> > &matrix);

/* Returns the "column" column vector of the matrix */
std::vector<double> get_column_vector(
                    std::vector<std::vector<double> > &matrix, int column);

/* Returns the "row" row vector of the matrix */
std::vector<double> get_row_vector(
                    std::vector<std::vector<double> > &matrix, int row);

#endif
