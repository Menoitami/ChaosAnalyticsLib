#pragma once

#include <vector>

namespace Backend
{
    __declspec(dllexport) void generateAttractor(const double* a, double h, int iterations,const double* initialState);

    __declspec(dllexport) void saveAttractor(std::vector<std::array<double, 3>> points);







}
extern "C" __declspec(dllexport) void createPlugin();
extern "C" __declspec(dllexport) void destroyPlugin();
