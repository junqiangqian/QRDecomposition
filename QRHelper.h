#ifndef QR_HELPER_H_
#define QR_HELPER_H_

#include <vector>
#include "Vector.h"
#include "Matrix.h"

void qr_decompose(std::vector<std::vector<double> > &u,
                  std::vector<std::vector<double> > &q,
                  std::vector<std::vector<double> > &r);
void converge_to_zero(std::vector<std::vector<double> > &matrix,
                      double threshold);
bool all_nd_zero(std::vector<std::vector<double> > &matrix);

#endif
