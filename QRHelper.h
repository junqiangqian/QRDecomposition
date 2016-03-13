#ifndef QR_HELPER_H_
#define QR_HELPER_H_

#include <vector>
#include "Vector.h"
#include "Matrix.h"
#include "input_output.h"
#include <assert.h>

/* Returns true iff matrix is symmetric */
bool check_symmetric(std::vector<std::vector<double> > &matrix);

/* Given the matrix reference u (the matrix you wish to QR decompose), performs
   QR decomposition and stores Q into q and R into r. */
void qr_decompose(std::vector<std::vector<double> > &u,
                  std::vector<std::vector<double> > &q,
                  std::vector<std::vector<double> > &r);

/* Wrapper function to setup matrices required for QR decomposition */
void perform_QR(std::vector<std::vector<double> > &matrix,
                std::vector<std::vector<double> > &Q,
                std::vector<std::vector<double> > &R, int dimensions);

/* Compares two matrices and checks if values (at the same position) change
   signficantly, if they do not differ in value greater than the threshold,
   returns true and thus no more iterations are required */                
bool compare_matrices(std::vector<std::vector<double> > &before,
                      std::vector<std::vector<double> > &after,
                      double threshold);

/* Performs QR iteration, using Q, R generated from qr_decompose, takes in
   a threshold which is used in compare_matrices and a maximum number of
   iterations to do, terminates when either iterations has passed or further
   iterations do not make a significant change (that is > threshold) to the
   matrix */
void qr_iterate(std::vector<std::vector<double> > &Q,
                std::vector<std::vector<double> > &R, double threshold,
                int max_iterations);

#endif
