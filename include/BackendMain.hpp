#pragma once

#include <vector>

namespace Backend
{
    __declspec(dllexport) std::vector<std::array<double, 3>> generateAttractor(const double* a, double h, int iterations,const double* initialState);

    extern "C" __declspec(dllexport) void saveAttractor(std::vector<std::array<double, 3>> points);







}
