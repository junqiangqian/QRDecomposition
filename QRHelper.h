#ifndef QR_HELPER_H_
#define QR_HELPER_H_

#include <vector>
#include "Vector.h"
#include "Matrix.h"
#include "input_output.h"
#include <assert.h>

void qr_decompose(std::vector<std::vector<double> > &u,
                  std::vector<std::vector<double> > &q,
                  std::vector<std::vector<double> > &r);

void perform_QR(std::vector<std::vector<double> > &matrix,
                std::vector<std::vector<double> > &Q,
                std::vector<std::vector<double> > &R, int dimensions);
bool compare_matrices(std::vector<std::vector<double> > &before,
                      std::vector<std::vector<double> > &after,
                      double threshold);
void qr_iterate(std::vector<std::vector<double> > &Q,
                std::vector<std::vector<double> > &R, double threshold,
                int max_iterations);

#endif
