#include <stdlib.h>
#include <string>
#include <vector>



using namespace std;



const vector<string> &races() {
    static vector<string> races = { "dwarf", "elf", "halfing", "human", "dragonborn",
                             "gnome", "half-elf", "half-ork", "tiefling" };
    return races;
}

const vector<string> &dwarf_subraces() {
    static vector<string> dwarf_subraces = { "hill dwarf", "mountain dwarf" };
    return dwarf_subraces;
}

const vector<string> &elf_subraces() {
    static vector<string> elf_subraces = { "high elf", "dark elf", "wood elf" };
    return elf_subraces;
}

const vector<string> &human_subraces() {
    static vector<string> human_subraces = { "damaran", "illuskan", "mulan", "rashemi",
                                      "calishite", "chondatan", "shou", "tethyrian",
                                      "turami" };
    return human_subraces;
}

const vector<string> &gnome_subraces() {
    static vector<string> gnome_subraces = { "forest gnome", "rock gnome" };
    return gnome_subraces;
}



enum class Dwarf {
    min_age = 16,
    adult_age = 50,
    max_age = 350,
    min_height = 4,
    max_height = 5,
    average_weight = 150,
};

enum class Elf {
    min_age = 16,
    adult_age = 100,
    max_age = 700,
    min_height = 5,
    max_height = 6,
    average_weight = 123,
};

enum class Halfing {
    min_age = 16,
    adult_age = 20,
    max_age = 250,
    min_height = 3,
    max_height = 4,
    average_weight = 187,
};

enum class Human {
    min_age = 16,
    adult_age = 20,
    max_age = 80,
    min_height = 5,
    max_height = 6,
    average_weight = 40,
};

enum class Dragonborn {
    min_age = 15,
    adult_age = 15,
    max_age = 80,
    min_height = 6,
    max_height = 7,
    average_weight = 250,
};

enum class Gnome {
    min_age = 16,
    adult_age = 80,
    max_age = 500,
    min_height = 3,
    max_height = 4,
    average_weight = 42,
};

enum class Half_elf {
    min_age = 16,
    adult_age = 20,
    max_age = 180,
    min_height = 5,
    max_height = 6,
    average_weight = 140,
};

enum class Half_ork {
    min_age = 16,   //check
    adult_age = 20, //check
    max_age = 180,  //check
    min_height = 6,
    max_height = 7,
    average_weight = 215,
};

enum class Tiefling {  // check
    min_age = 16,
    adult_age = 20,
    max_age = 100,
    min_height = 5,
    max_height = 6,
    average_weight = 40,
};
