#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
#include <cstdlib>
#include <cstdio>

/* MATRIX HELPER FUNCTIONS */
void print_matrix(std::vector<std::vector<double> > &matrix);
void init_matrix(std::vector<std::vector<double> > &matrix, int dimensions);
void generate_symmetric_matrix(std::vector<std::vector<double> > &matrix,
                               int limit);
std::vector<std::vector<double> > matrix_multiply(
                                 std::vector<std::vector<double> > &A,
                                 std::vector<std::vector<double> > &B);
std::vector<std::vector<double> > matrix_transpose(
                                  std::vector<std::vector<double> > &matrix);
std::vector<double> get_column_vector(
                    std::vector<std::vector<double> > &matrix, int column);
std::vector<double> get_row_vector(
                    std::vector<std::vector<double> > &matrix, int row);
/* MATRIX HELPER FUNCTIONS END*/



#endif
