#include <iostream>
#include <stdlib.h>
#include <random>
#include <ctime>
#include <cassert>
#include <string>
#include <vector>
#include "dicebox.h"
#include "utils.h"
#include "character.h"



using namespace std;
using namespace random_utils;

int main()
{
    Generator(generator());
    Character character{};
    //cout << character.get_race() << endl;
    character.set_random_age();
    character.about();
}
