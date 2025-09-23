///
/// PLC.hh creat a cellular plc object
///

#pragma once

#include <cmath>
#include <fstream>
#include <iostream>
#include <memory>
#include <vector>
// #include <nlohmann/json.hpp>

namespace PLC
{
    class PLC
    {
        public:
            PLC() = default;
            ~PLC() = default;
    };

    inline double gauss(double x, double mu, double sigma)
    {
        return std::exp(-0.5 * std::pow((x - mu) / sigma, 2));
    }
}; // namespace PLC
