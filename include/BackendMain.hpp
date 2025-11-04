#pragma once

#ifdef ATTRACTOR_EXPORTS
#define ATTRACTOR_API __declspec(dllexport)
#else
#define ATTRACTOR_API __declspec(dllimport)
#endif

#include <vector>

namespace Backend
{
    extern "C" __declspec(dllexport)
    int generateAttractor(
        const double* a,
        double h,
        int iterations,
        const double* initialState,
        double* output_buffer,
        int buffer_size);

    void saveAttractor(std::vector<std::array<double, 3>> points);







}
