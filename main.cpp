#include <iostream>
#include <stdlib.h>
#include <random>
#include <ctime>
#include <cassert>
#include <string>
#include <vector>
#include <filesystem>
#include "dicebox.h"
#include "utils.h"
#include "character.h"



using namespace std;
using namespace random_utils;
using namespace file_handling;

int main()
{
    Generator(generator());
    Character character{};
    //cout << character.get_race() << endl;
    character.set_random_age();
    character.about();

    vector<string> dwarf_names = {};
    string path = "";
    //file_handling::names_to_vector(dwarf_names, path);
    //for (string s: dwarf_names) cout << s << endl;

}
