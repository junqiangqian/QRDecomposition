#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <assert.h>
#include "random.cpp"
#include "Vector.h"
#include "Matrix.h"
#include "input_output.h"

using namespace std;

// #define RANDOM 1
#define MAX_RAND 1000
#define ITERATION_MAX 10

void generate_symmetric_matrix(vector<vector<double> > &matrix);

/* QR FUNCTIONS */
void qr_decompose(vector<vector<double> > &u, vector<vector<double> > &q,
                                             vector<vector<double> > &r);
/* QR FUNCTIONS END */

int main(int argc, char *argv[]){

  cout << "QR Decomposition" << endl;

  vector<vector<double> > matrix;
  int dimensions = 0;

  if (argc == 1) {
    cout << "Generating random symmetric matrix..." << endl;
    /* Set random seed to the current time */
    /*srand(time(NULL));
    dimensions = 3;
    init_matrix(matrix, dimensions);
    generate_symmetric_matrix(matrix); */

    dimensions = 2;

    vector<double> a;
    vector<double> b;

    a.push_back(7);
    a.push_back(2);

    matrix.push_back(a);

    b.push_back(2);
    b.push_back(4);

    matrix.push_back(b); 
  } else if (argc == 2) {
    cout << "Using the .txt provided to produce matrix..." << endl;
    matrix = load_matrix(argv[1]);
    dimensions = matrix.size();
  } else {
    cout << "ERROR : Invalid number of arguments, refer to README" << endl;
    exit(EXIT_FAILURE);
  }

  print_matrix(matrix);
  vector<vector<double> > Q;
  vector<vector<double> > R;
  init_matrix(Q, dimensions);
  init_matrix(R, dimensions);
  qr_decompose(matrix, Q, R);
  cout << "Matrix Q is..." << endl;
  print_matrix(Q);
  cout << "Matrix R is..." << endl;
  print_matrix(R);

  cout << "======= QR ITERATION TEST =========" << endl;
  vector<vector<double> > A_i;
  vector<vector<double> > Q_i = Q;

  int iterations = 0;

  while (iterations < ITERATION_MAX /* && within_tolerance() */ ) {
    A_i = matrix_multiply(R, Q);
    qr_decompose(A_i, Q, R);
    Q_i = matrix_multiply(Q_i, Q);
    iterations++;
  }

  print_matrix(A_i);
  print_matrix(Q_i);

  cout << "==================================" << endl;
}

void generate_symmetric_matrix(vector<vector<double> > &matrix) {

  int dimensions = matrix.size();

  /* Assign random values to leading diagonal */
  for (int i = 0; i < dimensions; i++){
    matrix[i][i] = random_double(MAX_RAND);
  }

  for (int i = 0; i < dimensions / 2 + 1; i++){
    for (int j = i + 1; j < dimensions; j++){
      matrix[i][j] = random_double(MAX_RAND);
      matrix[j][i] = matrix[i][j];
    }
  }
}



void qr_decompose(vector<vector<double> > &u, vector<vector<double> > &q,
                                             vector<vector<double> > &r) {
  int dimensions = u.size();

  for (int i = 0; i < dimensions; i++) {
    vector<double> u_i = get_column_vector(u, i);
    vector<double> q_i = u_i;
    for (int j = 0; j < i; j++) {
      vector<double> q_j = get_row_vector(q, j);
      r[j][i] = vector_dot_product(q_j, u_i);
      vector<double> temp = vector_mul_scalar(q_j, r[j][i]);
      q_i = vector_sub(q_i, temp);
    }
    r[i][i] = vector_magnitude(q_i);
    q_i = vector_div_scalar(q_i, r[i][i]);
    q[i] = q_i;
  }
  /* Transpose to transform the orthonormal row vectors to orthonormal column
     vectors */
  q = matrix_transpose(q);
}
