#include "Matrix.h"

using namespace std;

void print_matrix(vector<vector<float> > &matrix) {

  int dimensions = matrix.size();

  for (int i = 0; i < dimensions; i++) {
    for (int j = 0; j < dimensions; j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
}

void init_matrix(vector<vector<float> > &matrix, int dimensions) {
  for (int i = 0; i < dimensions; i++){
    vector<float> row;
    for (int j = 0; j < dimensions; j++){
      row.push_back(0);
    }
    matrix.push_back(row);
  }
}

vector<vector<float> > matrix_multiply(vector<vector<float> > &A,
                                       vector<vector<float> > &B) {
  vector<vector<float> > result;
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

vector<vector<float> > matrix_transpose(vector<vector<float> > &matrix) {

  vector<vector<float> > transpose;
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

vector<float> get_column_vector(vector<vector<float> > &matrix, int column) {
  assert (column < matrix[0].size());

  int dimensions = matrix.size();

  vector<float> columnVector;

  for (int i = 0; i < dimensions; i++){
    columnVector.push_back(matrix[i][column]);
  }

  return columnVector;
}

vector<float> get_row_vector(vector<vector<float> > &matrix, int row) {
  assert (row < matrix.size());

  int dimensions = matrix.size();

  vector<float> rowVector;

  for (int i = 0; i < dimensions; i++) {
    rowVector.push_back(matrix[row][i]);
  }

  return rowVector;
}
