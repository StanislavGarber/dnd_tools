#pragma once
#include <random>
#include <cassert>
#include "utils.h"
#include <iostream>



namespace random_utils {

PRNG& generator() {
    static PRNG generator;
    return generator;
}


void Generator(PRNG& generator) {
    std::random_device device;
    generator.engine.seed(device());
}

unsigned random_int(PRNG& generator, unsigned min, unsigned max) {
    assert(min < max);
    std::uniform_int_distribution<unsigned> distribution(min, max);
    return distribution(generator.engine);
}

float random_float(PRNG& generator, float min, float max) {
    assert(min < max);
    std::uniform_real_distribution<float> distribution(min, max);
    return distribution(generator.engine);
}

size_t random_index(PRNG& generator, size_t size) {
    std::uniform_int_distribution<size_t> distribution(0, size - 1);
    return distribution(generator.engine);
}
}

namespace file_handling {

void names_to_vector(vector<string> & names, string iname) {
    ifstream ist(iname);
    if (!ist) throw runtime_error("can't open the file");

    for (string s; ist >> s;) names.push_back(s);
    if (ist.eof()) return;
}

}
