#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <assert.h>
#include "random.cpp"
#include "Vector.h"
#include "Matrix.h"

using namespace std;

// #define RANDOM 1
#define MAX_RAND 100
#define ITERATION_MAX 1000

void generate_symmetric_matrix(vector<vector<double> > &matrix);

/* QR FUNCTIONS */
void qr_decompose(vector<vector<double> > &u, vector<vector<double> > &q,
                                             vector<vector<double> > &r);
/* QR FUNCTIONS END */

int main(){
  cout << "QR Decomposition" << endl;
  cout << "Enter 0 for random matrix, 1 for file\n";
  int n;
  cin >> n;

  while (n > 1) {
    cout << "Enter a valid number" << endl;
    cin >> n;
  }

  srand(time(NULL));
  int dimensions;
  #ifdef RANDOM
  dimensions = rand() % 10 + 2;
  #endif

  dimensions = 3;

  // cout << dimensions << endl;

  if (n == 0) {
    vector<vector<double> > matrix;
    init_matrix(matrix, dimensions);
    generate_symmetric_matrix(matrix);
    /*vector<double> a;
    vector<double> b;
    vector<double> c;

    a.push_back(1);
    a.push_back(2);
    a.push_back(4);

    b.push_back(0);
    b.push_back(0);
    b.push_back(5);

    c.push_back(0);
    c.push_back(3);
    c.push_back(6);

    matrix.push_back(a);
    matrix.push_back(b);
    matrix.push_back(c);*/
    /*a.push_back(7);
    a.push_back(2);
    b.push_back(2);
    b.push_back(4);
    matrix.push_back(a);
    matrix.push_back(b); */
    print_matrix(matrix);
    cout << endl;
    /* vector<double> column1 = get_column_vector(matrix, 0);
    vector<double> column2 = get_column_vector(matrix, 1);
    vector<double> column3 = get_column_vector(matrix, 2);
    print_vector(column1);
    print_vector(column2);
    print_vector(column3); */
    vector<vector<double> > Q;
    vector<vector<double> > R;
    init_matrix(Q, dimensions);
    init_matrix(R, dimensions);
    qr_decompose(matrix, Q, R);
    cout << "Matrix Q is..." << endl;
    print_matrix(Q);
    cout << "Matrix R is..." << endl;
    print_matrix(R);

    cout << "=======QR ITERATION TEST =========" << endl;
    vector<vector<double> > A_i;
    vector<vector<double> > Q_i = Q;


    int iterations = 0;

    while (iterations < ITERATION_MAX /* && within_tolerance() */) {
      A_i = matrix_multiply(R, Q);
      qr_decompose(A_i, Q, R);
      Q_i = matrix_multiply(Q_i, Q);
      iterations++;
    }

    print_matrix(A_i);
    print_matrix(Q_i);

    cout << "==================================" << endl;
  }
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
