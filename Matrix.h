#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
#include <cstdlib>

using namespace std;

/* Generates random floats */
float random_float(int limit);

/* MATRIX HELPER FUNCTIONS */
void print_matrix(vector<vector<float> > &matrix);
void init_matrix(vector<vector<float> > &matrix, int dimensions);
vector<vector<float> > matrix_multiply(vector<vector<float> > &A,
                                       vector<vector<float> > &B);
vector<vector<float> > matrix_transpose(vector<vector<float> > &matrix);
vector<float> get_column_vector(vector<vector<float> > &matrix, int column);
vector<float> get_row_vector(vector<vector<float> > &matrix, int row);
/* MATRIX HELPER FUNCTIONS END*/



#endif
