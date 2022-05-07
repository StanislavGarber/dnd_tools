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
#include "race.h"


using namespace std;
using namespace random_utils;
using namespace file_handling;


void test_random_character_creation() {
    Generator(generator());
    Character character{};
    //cout << character.get_race() << endl;
    character.set_random_age();
    character.about();
}

void test_names_file_reading() {
    vector<string> dwarf_names = {};
    string path = "";
    //file_handling::names_to_vector(dwarf_names, path);
    //for (string s: dwarf_names) cout << s << endl;
}


void skip_to_int()
{
    if(cin.fail()) { // not an int
        cin.clear(); // clear before checking the characters
        for (char ch; cin >> ch;) { // remove non digits
            if(isdigit(ch) || ch=='-'){  // cycle until first digit
                cin.unget();  // put the digit back
                return;
            }
            cout << "Sorry, that was not a number; please try again" << endl;
        }
    }
    runtime_error("no input");
}

int get_int() {
    int n = 0;
    while(true) {
        if (cin >> n) return n;
        skip_to_int();
    }
};

void menu(int n) {
    if(n == 1) {
        test_random_character_creation();
    }
    else if (n == 2) {
        cout << "manual character creation is not available yet" << endl;
    }
    else {
    }
}


int get_int(int low, int high, string menu_text) {
    cout << "what would you like to do?" << endl;
    cout << "1: create random character" << endl;
    cout << "2: manually build character" << endl;
    cout << "3: exit" << endl;
    while(true) {
        int n = get_int();
        if (low<=n && n<=high) {  // we're in range
            menu(n);
            break;
        };
        cout << "Sorry " << n << "is not in the [1:3] range; please try again" << endl;
    };
}


void read_race_data(Race& race) {
    string iname = "";
    ifstream ist {iname};
    ist >> race;
}

int main()
{
    // string menu_text = "what would you like to do?\n1: create random character\n2: manually build character \n3 exit";
    // get_int(1, 3, menu_text);
    Race dwarf("dwarf");
    Race elf("elf");
    Race halfing("halfing");
    Race human("human");
    Race dragonborn("dragonborn");
    Race gnome("gnome");
    Race half_elf("half_elf");
    Race half_ork("half_ork");
    Race tiefling("tiefling");
}
