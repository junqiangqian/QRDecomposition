#include "Matrix.h"

using namespace std;

void print_matrix(vector<vector<double> > &matrix) {

  int dimensions = matrix.size();

  for (int i = 0; i < dimensions; i++) {
    for (int j = 0; j < dimensions; j++) {
      printf("%.5f ", matrix[i][j]);
      //cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
}

void init_matrix(vector<vector<double> > &matrix, int dimensions) {
  for (int i = 0; i < dimensions; i++){
    vector<double> row;
    for (int j = 0; j < dimensions; j++){
      row.push_back(0);
    }
    matrix.push_back(row);
  }
}

vector<vector<double> > matrix_multiply(vector<vector<double> > &A,
                                       vector<vector<double> > &B) {
  vector<vector<double> > result;
  init_matrix(result, A.size());

  for (int i = 0; i < A.size(); i++){
    for (int j = 0; j < A[0].size(); j++) {
      for (int inner = 0; inner < A.size(); inner++){
        result[i][j] += A[i][inner] * B[inner][j];
      }
    }
  }
  return result;
}

vector<vector<double> > matrix_transpose(vector<vector<double> > &matrix) {

  vector<vector<double> > transpose;
  int dimensions = matrix.size();
  init_matrix(transpose, dimensions);

  /* Leading diagonal is preserved */
  for (int i = 0; i < dimensions; i++){
    transpose[i][i] = matrix[i][i];
  }

  /* Swap remaining elements with the elements in "mirrored" position with
     respect to the leading diagonal */
  for (int i = 0; i < dimensions / 2 + 1; i++) {
    for (int j = i + 1; j < dimensions; j++) {
      transpose[i][j] = matrix[j][i];
      transpose[j][i] = matrix[i][j];
    }
  }
  return transpose;
}

vector<double> get_column_vector(vector<vector<double> > &matrix, int column) {
  assert (column < matrix[0].size());

  int dimensions = matrix.size();

  vector<double> columnVector;

  for (int i = 0; i < dimensions; i++){
    columnVector.push_back(matrix[i][column]);
  }

  return columnVector;
}

vector<double> get_row_vector(vector<vector<double> > &matrix, int row) {
  assert (row < matrix.size());

  int dimensions = matrix.size();

  vector<double> rowVector;

  for (int i = 0; i < dimensions; i++) {
    rowVector.push_back(matrix[row][i]);
  }

  return rowVector;
}
