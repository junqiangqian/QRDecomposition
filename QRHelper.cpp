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

/* Given a threshold, if a non-diagonal element is between the negative of the
   threshold and the threshold, then round that element to zero */
void converge_to_zero(vector<vector<double> > &matrix, double threshold) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = i + 1; j < matrix[0].size(); j++) {
      if (abs(matrix[i][j]) < threshold) matrix[i][j] = 0;
    }
  }
}

/* Returns true iff all non diagonal elements are zero hence no more iterations
   are required since the matrix is already diagonal */
bool all_nd_zero(vector<vector<double> > &matrix) {
  for (int i = 0; i < matrix.size(); i++) {
    for (int j = i + 1; j < matrix[0].size(); j++) {
      if (matrix[i][j] != 0) return false;
    }
  }
  return true;
}
