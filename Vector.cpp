#include "Vector.h"

using namespace std;

void print_vector(vector<double> &vec) {
  cout << "(";
  for (int i = 0; i < vec.size(); i++) {
    i != vec.size() - 1? cout << vec[i] << ", " : cout << vec[i];
  }
  cout << ")" << endl;
}


double vector_magnitude(vector<double> &vec) {
  int dimensions = vec.size();
  double norm;

  for (int i = 0; i < dimensions; i++) {
    norm += vec[i] * vec[i];
  }

  return sqrt(norm);
}

float vector_dot_product(vector<double> &vecA, vector<double> &vecB) {
  assert (vecA.size() == vecB.size());

  int dimensions = vecA.size();
  float dp = 0;

  for (int i = 0; i < dimensions; i++) {
    dp += (vecA[i] * vecB[i]);
  }

  return dp;
}

vector<double> vector_add(vector<double> &vecA, vector<double> &vecB) {
  assert (vecA.size() == vecB.size());

  vector<double> result;
  int dimensions = vecA.size();

  for (int i = 0; i < dimensions; i++) {
    result.push_back(vecA[i] + vecB[i]);
  }

  return result;
}

vector<double> vector_sub(vector<double> &vecA, vector<double> &vecB) {
  assert (vecA.size() == vecB.size());

  vector<double> negatedVecB;
  int dimensions = vecA.size();

  for (int i = 0; i < dimensions; i++) {
    negatedVecB.push_back(-1 * vecB[i]);
  }

  return vector_add(vecA, negatedVecB);
}

vector<double> vector_mul_scalar(vector<double> &vec, double scalar) {
  vector<double> result;

  for (int i = 0; i < vec.size(); i++) {
    result.push_back(scalar * vec[i]);
  }

  return result;
}

vector<double> vector_div_scalar(vector<double> &vec, double scalar) {
  return vector_mul_scalar(vec, (1 / scalar));
}
