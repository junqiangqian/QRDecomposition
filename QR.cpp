#include <iostream>
#include <cstdlib>
#include <vector>
#include <cmath>
#include <assert.h>
#include "random.cpp"

using namespace std;

// #define RANDOM 1
#define MAX_RAND 100

/* MATRIX HELPER FUNCTIONS */
void print_matrix(vector<vector<float> > &matrix);
void init_matrix(vector<vector<float> > &matrix, int dimensions);
void generate_symmetric_matrix(vector<vector<float> > &matrix);
vector<vector<float> > matrix_multiply(vector<vector<float> > &A,
                                       vector<vector<float> > &B);
vector<vector<float> > matrix_transpose(vector<vector<float> > &matrix);
/* MATRIX HELPER FUNCTIONS END*/

/* VECTOR HELPER FUNCTIONS */
void print_vector(vector<float> &vec);
float vector_magnitude(vector<float> &vec);
float vector_dot_product(vector<float> &vecA, vector<float> &vecB);
vector<float> vector_add(vector<float> &vecA, vector<float> &vecB);
vector<float> vector_sub(vector<float> &vecA, vector<float> &vecB);
/* VECTOR HELPER FUNCTIONS END */

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
    init_matrix(matrix, dimensions);
    generate_symmetric_matrix(matrix);
    print_matrix(matrix);
    cout << endl;
  }
}

void print_matrix(vector<vector<float> > &matrix) {

  int dimensions = matrix.size();

  for (int i = 0; i < dimensions; i++) {
    for (int j = 0; j < dimensions; j++) {
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
  }
  cout << endl;
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

vector<vector<float> > matrix_transpose(vector<vector<float> > &matrix) {

  vector<vector<float> > transpose;
  int dimensions = matrix.size();
  init_matrix(transpose, dimensions);

  /* Leading diagonal is preserved */
  for (int i = 0; i < dimensions; i++){
    transpose[i][i] = matrix[i][i];
  }

  /* Swap remaining elements with the elements in "mirrored" position with
     respect to the leading diagonal */
  for (int i = 0; i < dimensions / 2 + 1; i++) {
    for (int j = i + 1; j < dimensions; j++) {
      transpose[i][j] = matrix[j][i];
      transpose[j][i] = matrix[i][j];
    }
  }

  return transpose;
}


void print_vector(vector<float> &vec) {
  cout << "(";
  for (int i = 0; i < vec.size(); i++) {
    i != vec.size() - 1? cout << vec[i] << ", " : cout << vec[i];
  }
  cout << ")" << endl;
}


float vector_magnitude(vector<float> &vec) {
  int dimensions = vec.size();
  float norm;

  for (int i = 0; i < dimensions; i++) {
    norm += vec[i] * vec[i];
  }

  return sqrt(norm);
}

float vector_dot_product(vector<float> &vecA, vector<float> &vecB) {
  assert (vecA.size() == vecB.size());

  int dimensions = vecA.size();
  float dp;

  for (int i = 0; i < dimensions; i++) {
    dp += vecA[i] * vecB[i];
  }

  return dp;
}

vector<float> vector_add(vector<float> &vecA, vector<float> &vecB) {
  assert (vecA.size() == vecB.size());

  vector<float> result;
  int dimensions = vecA.size();

  for (int i = 0; i < dimensions; i++) {
    result.push_back(vecA[i] + vecB[i]);
  }

  return result;
}

vector<float> vector_sub(vector<float> &vecA, vector<float> &vecB) {
  assert (vecA.size() == vecB.size());

  vector<float> negatedVecB;
  int dimensions = vecA.size();

  for (int i = 0; i < dimensions; i++) {
    negatedVecB.push_back(-1 * vecB[i]);
  }

  return vector_add(vecA, negatedVecB);
}
