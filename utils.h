#ifndef UTILS_H
#define UTILS_H

#include <random>

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

#endif // UTILS_H
