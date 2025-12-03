#include "../include/BackendMain.hpp"
#include <iostream>
#include <vector>
#include <array>
#include <fstream>
#include <system.cuh>

namespace Backend{

    int generateAttractor(
        const double* a,
        double h,
        int iterations,
        const double* initialState,
        const int* output_dimension,
        double* output_buffer,
        int buffer_size) {

        if (!a || !initialState || !output_buffer || iterations <= 0)
            return -1;
        if (buffer_size < iterations * 3)
            return -1;

        double x[3] = { initialState[0], initialState[1], initialState[2] };

        for (int i = 0; i < iterations; ++i) {
            output_buffer[i * 3 + 0] = x[0];
            output_buffer[i * 3 + 1] = x[1];
            output_buffer[i * 3 + 2] = x[2];

            calcDiscreteModel(x, a, h);

        }

        return iterations;
    }

    void saveAttractor(std::vector<std::array<double, 3> > points)
    {
        std::string filename = OUTPUT_PATH;
        filename += "Attractor.csv";
        std::ofstream file(filename);

        if (!file.is_open()) {
            std::cerr << "Error opening file: " << filename << std::endl;
            return;
        }

        for (const auto& point : points) {
            file << point[0] << "," << point[1] << "," << point[2] << "\n";
        }

        file.close();
        std::cout << "Attractor saved to " << filename << std::endl;
    }


}

