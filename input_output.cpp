#include "input_output.h"

using namespace std;

vector<vector<double> > load_matrix(const char *fileName) {
  vector<vector<double> > result;
  ifstream file(fileName);

  if (!file) {
    cout << "Error, could not find the file " << fileName << endl;
    exit(-1);
  }

  string line;

  if (file.is_open()) {
    while (getline(file, line)) {
      result.push_back(parseLine(line));
    }
  } else {
    cout << "Error, could not open the file" << endl;
  }

  return result;
}

vector<double> parseLine(string line) {

  vector<double> result;

  string buffer;
  /* Use a stringstream to parse the line */
  stringstream ss(line);

  /* ss will the split the line using the space as a delimiter until the
     line has been completely parsed in which case the loop condition will
     fail */
  while (ss >> buffer) {
    /* Convert the string to a double and append to result */
    result.push_back(atof(buffer.c_str()));
  }

  return result;
}
