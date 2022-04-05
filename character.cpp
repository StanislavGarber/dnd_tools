#include "character.h"
#include <iostream>
#include "race_data.cpp"
#include "utils.h"

using namespace std;
using namespace random_utils;


Character::Character() {
    set_random_race();
    set_random_subrace();
    set_random_age();
    set_random_size();
    set_random_sex();
}


void Character::set_random_race() {
    int race_index = random_utils::random_index(random_utils::generator(), races().size());
    race = races()[race_index];
}


void Character::set_random_subrace() {
    if (race == "dwarf") subrace = dwarf_subraces()[random_utils::random_index(
                random_utils::generator(), dwarf_subraces().size())];
    else if (race == "elf") subrace = elf_subraces()[random_utils::random_index(
                random_utils::generator(), elf_subraces().size())];
    else if (race == "human") subrace = human_subraces()[::random_index(generator(), human_subraces().size())];
    else if (race == "gnome") subrace = gnome_subraces()[::random_index(generator(), gnome_subraces().size())];
    else subrace = race;
}


void Character::set_random_age() {
    if (race == "dwarf") age = random_int(generator(), int(Dwarf::min_age), int(Dwarf::max_age));
    else if (race == "elf") age = random_int(generator(), int(Elf::min_age), int(Elf::max_age));
    else if (race == "halfing") age = random_int(generator(), int(Halfing::min_age), int(Halfing::max_age));
    else if (race == "human") age = random_int(generator(), int(Human::min_age), int(Human::max_age));
    else if (race == "dragonborn") age = random_int(generator(), int(Dragonborn::min_age), int(Dragonborn::max_age));
    else if (race == "gnome") age = random_int(generator(), int(Gnome::min_age), int(Gnome::max_age));
    else if (race == "half-elf") age = random_int(generator(), int(Half_elf::min_age), int(Half_elf::max_age));
    else if (race == "half-ork") age = random_int(generator(), int(Half_ork::min_age), int(Half_ork::max_age));
    else if (race == "tiefling") age = random_int(generator(), int(Tiefling::min_age), int(Tiefling::max_age));
}


void Character::set_random_size() {
    if (race == "dwarf") {
        height = random_float(generator(), int(Dwarf::min_height), int(Dwarf::max_height));
        weight = int(Dwarf::average_weight) / ((int(Dwarf::min_height) + int(Dwarf::max_height)) / 2) * height;
    }
    if (race == "elf") {
        height = random_float(generator(), int(Elf::min_height), int(Elf::max_height));
        weight = int(Elf::average_weight) / ((int(Elf::min_height) + int(Elf::max_height)) / 2) * height;
    }
    if (race == "halfing") {
        height = random_float(generator(), int(Halfing::min_height), int(Halfing::max_height));
        weight = int(Halfing::average_weight) / ((int(Halfing::min_height) + int(Halfing::max_height)) / 2) * height;
    }
    if (race == "human") {
        height = random_float(generator(), int(Human::min_height), int(Human::max_height));
        weight = int(Human::average_weight) / ((int(Human::min_height) + int(Human::max_height)) / 2) * height;
    }
    if (race == "dragonborn") {
        height = random_float(generator(), int(Dragonborn::min_height), int(Dragonborn::max_height));
        weight = int(Dragonborn::average_weight) / ((int(Dragonborn::min_height) + int(Dragonborn::max_height)) / 2) * height;
    }
    if (race == "gnome") {
        height = random_float(generator(), int(Gnome::min_height), int(Gnome::max_height));
        weight = int(Gnome::average_weight) / ((int(Gnome::min_height) + int(Gnome::max_height)) / 2) * height;
    }
    if (race == "half-elf") {
        height = random_float(generator(), int(Half_elf::min_height), int(Half_elf::max_height));
        weight = int(Half_elf::average_weight) / ((int(Half_elf::min_height) + int(Half_elf::max_height)) / 2) * height;
    }
    if (race == "half-ork") {
        height = random_float(generator(), int(Half_ork::min_height), int(Half_ork::max_height));
        weight = int(Half_ork::average_weight) / ((int(Half_ork::min_height) + int(Half_ork::max_height)) / 2) * height;
    }
    if (race == "tiefling") {
        height = random_float(generator(), int(Tiefling::min_height), int(Tiefling::max_height));
        weight = int(Tiefling::average_weight) / ((int(Tiefling::min_height) + int(Tiefling::max_height)) / 2) * height;
    }
}


void Character::set_random_sex() {
    int sex_index = random_int(generator(), 0, 1);
    switch(sex_index) {
    case 1: sex = 'm';
    case 0: sex = 'f';
    }
}


void Character::about() {
    cout << "\nrace: " << get_race() << endl;
    cout << "subrace: " << get_subrace() << endl;
    cout << "age: " << get_age() << endl;
    cout << "height: " << get_height() << endl;
    cout << "weight: " << get_weight() << endl;
    cout << "sex: " << get_sex() << endl;

}
