#pragma once

#include <string>
#include <vector>
#include "body.hpp"

class ConfigLoader {
public:
    static std::vector<Body> loadBodies(const std::string& filename);
};
