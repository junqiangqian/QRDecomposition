#include "Matrix.h"

using namespace std;

/* Returns a random double between -limit and limit */
static double random_double(int limit){
  int a = -limit;
  double random = ((double) rand()) / (double) RAND_MAX;
  double diff = limit - a;
  double r = random * diff;
  return a + r;
}

void print_matrix(vector<vector<double> > &matrix) {

  int rows = matrix.size();
  int cols = matrix[0].size();

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      printf("%.5f ", matrix[i][j]);
    }
    cout << endl;
  }
  cout << endl;
}

void init_matrix(vector<vector<double> > &matrix, int rows, int cols) {
  for (int i = 0; i < rows; i++){
    vector<double> row;
    for (int j = 0; j < cols; j++){
      row.push_back(0);
    }
    matrix.push_back(row);
  }
}

void generate_symmetric_matrix(vector<vector<double> > &matrix, int limit) {

  int dimensions = matrix.size();

  /* Assign random values to leading diagonal */
  for (int i = 0; i < dimensions; i++){
    matrix[i][i] = random_double(limit);
  }

  for (int i = 0; i < dimensions / 2 + 1; i++){
    for (int j = i + 1; j < dimensions; j++){
      matrix[i][j] = random_double(limit);
      matrix[j][i] = matrix[i][j];
    }
  }
}

vector<vector<double> > matrix_multiply(vector<vector<double> > &A,
                                       vector<vector<double> > &B) {
  assert(A[0].size() == B.size()); /* Columns of A = Rows of B */
  vector<vector<double> > result;
  init_matrix(result, A.size(), B[0].size());

  int rows = A.size();
  int columns = B[0].size();

  for (int i = 0; i < rows; i++){
    for (int j = 0; j < columns; j++) {
      for (int k = 0; k < B.size(); k++){
        result[i][j] += A[i][k] * B[k][j];
      }
    }
  }
  return result;
}

vector<vector<double> > matrix_transpose(vector<vector<double> > &matrix) {

  vector<vector<double> > transpose;
  int rows = matrix.size();
  int columns = matrix[0].size();
  cout << rows << ", " << columns << endl;
  init_matrix(transpose, rows, columns);

  /* Leading diagonal is preserved */
  /*for (int i = 0; i < dimensions; i++){
    transpose[i][i] = matrix[i][i];
  }*/

  /* Swap remaining elements with the elements in "mirrored" position with
     respect to the leading diagonal */
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      transpose[i][j] = matrix[j][i];
      transpose[j][i] = matrix[i][j];
    }
  }
  return transpose;
}

vector<double> get_column_vector(vector<vector<double> > &matrix, int column) {
  assert (column < matrix[0].size());

  int rows = matrix.size();

  vector<double> columnVector;

  for (int i = 0; i < rows; i++){
    columnVector.push_back(matrix[i][column]);
  }

  return columnVector;
}

vector<double> get_row_vector(vector<vector<double> > &matrix, int row) {
  assert (row < matrix.size());

  int columns = matrix[0].size();

  vector<double> rowVector;

  for (int i = 0; i < columns; i++) {
    rowVector.push_back(matrix[row][i]);
  }

  return rowVector;
}
