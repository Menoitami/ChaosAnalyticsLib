#pragma once

#include <iostream>
#include <cuda_runtime.h>
#include <math.h>

 __device__ inline void calcDiscreteModel(double* X, const double* a, double h) {
double h1 = 0.5 * h + a[0];
    double h2 = 0.5 * h - a[0];
    X[0] = h1 * (-X[1] - X[2]) + X[0];
    X[1] = h1 * (X[0] + a[1] * X[1]) + X[1];
    X[2] = h1 * (a[2] + X[2] * (X[0] - a[3])) + X[2];
    double temp = -h2 * (X[0] - a[3]) + 1.0;
    X[2] = (h2 * a[2] + X[2]) / temp;
    temp = -h2 * a[1] + 1.0;
    X[1] = (h2 * X[0] + X[1]) / temp;
    X[0] = h2 * (-X[1] - X[2]) + X[0];
}
#define SIZE_A 32
#define SIZE_X 32
