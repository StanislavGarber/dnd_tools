#ifndef UTILS_H
#define UTILS_H

#include <random>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <exception>

using std::vector; using std::string;
using std::ifstream; using std::runtime_error;


namespace random_utils {

struct PRNG {
    std::mt19937 engine;
};

PRNG& generator();

void Generator(PRNG& generator);
unsigned random_int(PRNG& generator, unsigned min, unsigned max);
float random_float(PRNG& generator, float min, float max);
size_t random_index(PRNG& generator, size_t size);

}

namespace file_handling {

void names_to_vector(vector<string> & names, string iname);

}

#endif // UTILS_H
