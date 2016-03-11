#ifndef MATRIX_H_
#define MATRIX_H_

#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
#include <cstdlib>

using namespace std;

/* Generates random doubles */
double random_double(int limit);

/* MATRIX HELPER FUNCTIONS */
void print_matrix(vector<vector<double> > &matrix);
void init_matrix(vector<vector<double> > &matrix, int dimensions);
vector<vector<double> > matrix_multiply(vector<vector<double> > &A,
                                       vector<vector<double> > &B);
vector<vector<double> > matrix_transpose(vector<vector<double> > &matrix);
vector<double> get_column_vector(vector<vector<double> > &matrix, int column);
vector<double> get_row_vector(vector<vector<double> > &matrix, int row);
/* MATRIX HELPER FUNCTIONS END*/



#endif
