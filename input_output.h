#ifndef INPUT_OUTPUT_H_
#define INPUT_OUTPUT_H_

#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <string>
#include <sstream>

/* Loads the file provided and returns the matrix the file contains */
std::vector<std::vector<double> > load_matrix(const char *fileName);
/* Parses one line of the file and converts it to a vector of doubles assuming
   the seperator between individual elements is a space and returns this vector
   of doubles */
std::vector<double> parseLine(std::string line);

#endif
