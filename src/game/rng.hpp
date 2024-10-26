#pragma once

#include <random>

using namespace std;

struct RNG {
    static unsigned int randRange(const unsigned int &a, const unsigned int &b) {
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> dis(a, b);
        return dis(gen);
    }
};