#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <random>
#include <ctime>
#include <cassert>
#include "dicebox.h"
#include "informaltesting.h"

using namespace std;

// data

vector<string> races = {"dwarf", "elf", "halfing", "human", "dragonborn", "gnome", "half-elf", "half-ork", "tiefling"};
vector<string> dwarf_subraces = {"hill dwarf", "mountain dwarf"};
vector<string> elf_subraces = {"high elf", "dark elf", "wood elf"};
vector<string> human_subraces = {"damaran", "illuskan", "mulan", "rashemi", "calishite", "chondatan", "shou", "tethyrian", "turami"};
vector<string> gnome_subraces = {"forest gnome", "rock gnome"};


enum class Dwarf {
  min_age = 16,
  adult_age = 50,
  max_age = 350,
  min_height = 4,
  max_height = 5,
  average_weight = 150,
};


// random utils

struct PRNG {
    std::mt19937 engine;
};

void Generator(PRNG& generator) {
    std::random_device device;
    generator.engine.seed(device());
}

PRNG generator;

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
    std::uniform_int_distribution<size_t> distribution(0, size-1);
    return distribution(generator.engine);
}

// character

class Character
{
private:
    string race;
    string subrace;
    int age;
    float height;
    float weight;
public:

    Character();

    string get_race() { return race; };
    string get_subrace() { return subrace; };
    int get_age() { return age; };
    int get_height() { return height; };
    int get_weight() { return weight; };

    void set_random_race();
    void set_random_subrace();
    void set_random_age();
    void set_random_size();
};


Character::Character() {
    set_random_race();
    set_random_subrace();
    set_random_age();
    set_random_size();
}

void Character::set_random_race() {
    int race_index = ::random_index(generator, races.size());
    race = races[race_index];
}

void Character::set_random_subrace() {
    if(race == "dwarf") subrace = dwarf_subraces[::random_index(generator, dwarf_subraces.size())];
    else if(race == "elf") subrace = elf_subraces[::random_index(generator, elf_subraces.size())];
    else if(race == "human") subrace = human_subraces[::random_index(generator, human_subraces.size())];
    else if(race == "gnome") subrace = gnome_subraces[::random_index(generator, gnome_subraces.size())];
    else subrace = race;
}

void Character::set_random_age() {
    if(race == "dwarf") age = ::random_int(generator, int(Dwarf::min_age), int(Dwarf::max_age));

}

void Character::set_random_size() {
    if(race == "dwarf") {
        height = ::random_float(generator, int(Dwarf::min_height), int(Dwarf::max_height));

    }
}


int main()
{
    Generator(generator);
    Character character{};
    cout << character.get_race() << endl;
}
