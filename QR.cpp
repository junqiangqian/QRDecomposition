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

void generate_symmetric_matrix(vector<vector<float> > &matrix);

/* QR FUNCTIONS */
void qr_decompose(vector<vector<float> > &u, vector<vector<float> > &q,
                                             vector<vector<float> > &r);
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
    vector<vector<float> > matrix;
    init_matrix(matrix, dimensions);
    generate_symmetric_matrix(matrix);
    /*vector<float> a;
    vector<float> b;
    vector<float> c;

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
    matrix.push_back(c); */
    print_matrix(matrix);
    cout << endl;
    /* vector<float> column1 = get_column_vector(matrix, 0);
    vector<float> column2 = get_column_vector(matrix, 1);
    vector<float> column3 = get_column_vector(matrix, 2);
    print_vector(column1);
    print_vector(column2);
    print_vector(column3); */
    vector<vector<float> > Q;
    vector<vector<float> > R;
    init_matrix(Q, dimensions);
    init_matrix(R, dimensions);
    qr_decompose(matrix, Q, R);
    print_matrix(Q);
    print_matrix(R);
  }
}

void generate_symmetric_matrix(vector<vector<float> > &matrix) {

  int dimensions = matrix.size();

  /* Assign random values to leading diagonal */
  for (int i = 0; i < dimensions; i++){
    matrix[i][i] = random_float(MAX_RAND);
  }

  for (int i = 0; i < dimensions / 2 + 1; i++){
    for (int j = i + 1; j < dimensions; j++){
      matrix[i][j] = random_float(MAX_RAND);
      matrix[j][i] = matrix[i][j];
    }
  }
}



void qr_decompose(vector<vector<float> > &u, vector<vector<float> > &q,
                                             vector<vector<float> > &r) {
  int dimensions = u.size();

  for (int i = 0; i < dimensions; i++) {
    vector<float> u_i = get_column_vector(u, i);
    vector<float> q_i = u_i;
    for (int j = 0; j < i; j++) {
      vector<float> q_j = get_row_vector(q, j);
      r[j][i] = vector_dot_product(q_j, u_i);
      vector<float> temp = vector_mul_scalar(q_j, r[j][i]);
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
