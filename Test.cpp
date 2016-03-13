#include <iostream>
#include "Matrix.h"
#include "Vector.h"

using namespace std;

int main() {
  vector<vector<double> > A;
  vector<vector<double> > B;

  vector<double> c1;
  c1.push_back(1);
  c1.push_back(2);
  A.push_back(c1);
  vector<double> c2;
  c2.push_back(2);
  c2.push_back(3);
  A.push_back(c2);
  vector<double> c3;
  c3.push_back(3);
  c3.push_back(4);
  A.push_back(c3);

  for (int i = 0; i < 2; i++) {
    vector<double> row;
    for (int j = 0; j < 4; j++) {
      row.push_back(j + 1);
    }
    B.push_back(row);
  }

  print_matrix(A);
  print_matrix(B);
  vector<vector<double> > result = matrix_multiply(A, B);
  print_matrix(result);
  vector<vector<double> > transposeA = matrix_transpose(A);
  print_matrix(transposeA);
  vector<vector<double> > transposeB = matrix_transpose(B);
  print_matrix(transposeB);
  vector<vector<double> > transposeR = matrix_transpose(result);
  print_matrix(transposeR);
}
