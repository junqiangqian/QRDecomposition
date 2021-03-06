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

  /* Assign values to symmetrical positions in the matrix */
  for (int i = 0; i < dimensions; i++){
    for (int j = 0; j < dimensions; j++) {
      matrix[i][j] = random_double(limit);
      matrix[j][i] = matrix[i][j];
    }
  }
}

vector<vector<double> > matrix_multiply(vector<vector<double> > &A,
                                       vector<vector<double> > &B) {
  assert(A[0].size() == B.size()); /* Columns of A = Rows of B */
  vector<vector<double> > result;

  /* Product of A and B will have same number of rows as A and same number of
     columns as B */
  int rows = A.size();
  int columns = B[0].size();

  init_matrix(result, rows, columns);

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

  /* Transpose will have "columns" rows and "rows" columns*/
  init_matrix(transpose, columns, rows);

  /* Set transpose's element with its symmetrical element in the original
     matrix */
  for (int i = 0; i < columns; i++) {
    for (int j = 0; j < rows; j++) {
      transpose[i][j] = matrix[j][i];
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
