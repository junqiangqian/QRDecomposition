#include "Vector.h"

using namespace std;

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
    dp += (vecA[i] * vecB[i]);
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

vector<float> vector_mul_scalar(vector<float> &vec, float scalar) {
  vector<float> result;

  for (int i = 0; i < vec.size(); i++) {
    result.push_back(scalar * vec[i]);
  }

  return result;
}

vector<float> vector_div_scalar(vector<float> &vec, float scalar) {
  return vector_mul_scalar(vec, (1 / scalar));
}
