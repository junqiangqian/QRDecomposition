#include "QRHelper.h"

using namespace std;

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

void perform_QR(vector<vector<double> > &matrix, vector<vector<double> > &Q,
                vector<vector<double> > &R, int dimensions) {
  init_matrix(Q, dimensions);
  init_matrix(R, dimensions);
  qr_decompose(matrix, Q, R);
  cout << "Matrix Q is..." << endl;
  print_matrix(Q);
  cout << "Matrix R is..." << endl;
  print_matrix(R);
}


/* Compares two matrices and checks if values change signficantly, if they do
   not returns true and thus no more iterations are required */
bool compare_matrices(vector<vector<double> > &before,
                      vector<vector<double> > &after, double threshold) {
  if (before.size() == 0) return false;
  assert (before.size() == after.size());
  assert (before[0].size() == after[0].size());

  for (int i = 0; i < before.size(); i++) {
    for (int j = 0; j < before[0].size(); j++) {
      double difference = abs(after[i][j] - before[i][j]);
      if (difference > threshold) {
        return false;
      }
    }
  }
  return true;
}

void qr_iterate(vector<vector<double> > &Q, vector<vector<double> > &R,
                double threshold, int max_iterations) {
  cout << "======= QR ITERATIONS=========" << endl;

  vector<vector<double> > A_i;
  vector<vector<double> > Q_i = Q;

  vector<vector<double> > prev;

  int iterations = 0;

  do {
    prev = A_i;
    A_i = matrix_multiply(R, Q);
    qr_decompose(A_i, Q, R);
    Q_i = matrix_multiply(Q_i, Q);
    iterations++;
  } while (iterations < max_iterations && !compare_matrices(prev, A_i,
                                                            threshold));
  print_matrix(A_i);
  print_matrix(Q_i);

  cout << "Computation finished after " << iterations << " iterations" << endl;

  cout << "==================================" << endl;

  bool success = write_to_file(A_i, Q_i);
  if (!success) {
    cout << "Error in writing to file" << endl;
  }
}
