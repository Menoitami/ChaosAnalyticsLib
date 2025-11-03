#pragma once

#include <iostream>
#include <cuda_runtime.h>
#include <math.h>

 __device__ inline void calcDiscreteModel(double* X, const double* a, double h) {
float h1 = h * a[0];
float h2 = h * (1 - a[0]);
    
X[0] = X[0] + h1 * (-X[1]);
X[1] = X[1] + h1 * (a[1] * X[0] + sin(X[1]));
    
float z = X[1];
    
X[1] = z + h2 * (a[1] * X[0] + sin(X[1]));
X[0] = X[0] + h2 * (-X[1]);
}
#define SIZE_A 32
#define SIZE_X 32
