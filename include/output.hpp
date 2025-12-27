#pragma once

#include <string>
#include <vector>
#include <fstream>
#include "body.hpp"

class Output {
public:
    Output(const std::string& filename);
    ~Output();

    void writeHeader();
    void writeStep(double time, const std::vector<Body>& bodies);

private:
    std::string filename;
    std::ofstream file;
};
