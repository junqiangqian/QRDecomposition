#include <iostream>
#include <cstdlib>
#include <vector>
#include "random.cpp"

using namespace std;

// #define RANDOM 1
#define MAX_RAND 100

/* Helper functions */
void init_matrix(vector<vector<float> > &matrix, int dimensions);
void generate_random_matrix(vector<vector<float> > &matrix, int dimensions);
void print_matrix(vector<vector<float> > &matrix, int dimensions);
vector<vector<float> > matrix_multiply(vector<vector<float> > &A,
                                       vector<vector<float> > &B);

/* Helper functions end */

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

  cout << dimensions << endl;

  if (n == 0) {
    vector<vector<float> > matrix;
    vector<vector<float> > matrix2;
    init_matrix(matrix, dimensions);
    init_matrix(matrix2, dimensions);
    generate_random_matrix(matrix, dimensions);
    generate_random_matrix(matrix2, dimensions);
    vector<vector<float> > result = matrix_multiply(matrix, matrix2);
    print_matrix(matrix, dimensions);
    cout << endl;
    print_matrix(matrix2, dimensions);
    cout << endl;
    print_matrix(result, dimensions);
  }
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

void print_matrix(vector<vector<float> > &matrix, int dimensions) {
  for (int i = 0; i < dimensions; i++) {
    for (int j = 0; j < dimensions; j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
}

void generate_random_matrix(vector<vector<float> > &matrix, int dimensions) {

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
