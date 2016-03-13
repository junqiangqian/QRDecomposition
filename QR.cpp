#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <assert.h>
#include "Vector.h"
#include "Matrix.h"
#include "input_output.h"
#include "QRHelper.h"

using namespace std;

#define MAX_RAND 50
#define MAX_DIMENSION 10
#define ITERATION_MAX 10000
#define THRESHOLD 1e-5

int main(int argc, char *argv[]){

  cout << "QR Decomposition" << endl;

  vector<vector<double> > matrix;
  int dimensions = 0;

  if (argc == 1) {
    cout << "Generating random symmetric matrix..." << endl;
    /* Set random seed to the current time */
    srand(time(NULL));
    dimensions = rand() % MAX_DIMENSION + 2;
    init_matrix(matrix, dimensions);
    generate_symmetric_matrix(matrix, MAX_RAND);
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
  perform_QR(matrix, Q, R, dimensions);
  qr_iterate(Q, R, THRESHOLD, ITERATION_MAX);
}
