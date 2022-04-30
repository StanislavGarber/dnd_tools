#include "race.h"

using namespace std;

// general prints

void Race::print_int_parameter(string name, int& parameter){
    cout << endl << name << ':' << ' ' << parameter << endl;
}

void Race::print_string_vector_data(string name, vector<string>& data) {
    cout << endl << name << ':' << endl;
    for (string s : data) cout << s << ' ';
    cout << endl;
}

// int parameter prints

void Race::print_min_age() {
    print_int_parameter("min age", min_age);
}

void Race::print_adult_age() {
    print_int_parameter("adult_age", adult_age);
}

void Race::print_max_age() {
    print_int_parameter("max_age", max_age);
}

void Race::print_min_height() {
    print_int_parameter("min height", min_height);
}

void Race::print_max_height() {
    print_int_parameter("max_height", max_height);
}

void Race::print_average_weight() {
    print_int_parameter("average_weight", average_weight);
}

// string vector prints

void Race::print_subraces() {
    print_string_vector_data("subraces", subraces);
}

void Race::print_male_names() {
    print_string_vector_data("male names", male_names);
}

void Race::print_female_names() {
    print_string_vector_data("female names", female_names);
}

void Race::print_clan_names() {
    print_string_vector_data("clan names", clan_names);
}

void Race::print_child_names() {
    print_string_vector_data("child names", child_names);
}

void Race::print_family_names() {
    print_string_vector_data("family_names", family_names);
}

void Race::print_human_names() {
    for (const auto &item : human_names) {
        vector<string> names = item.second;
        print_string_vector_data(item.first, names);

    }
}

void Race::print_nicknames() {
    print_string_vector_data("nicknames", nicknames);
}

void Race::print_data() {
    cout << race_name << endl;

    print_min_age();
    print_adult_age();
    print_max_age();
    print_min_height();
    print_max_height();
    print_average_weight();

    if (race_name == "dwarf" || race_name == "elf" || race_name == "gnome") print_subraces();
    if (race_name != "human") print_male_names();
    if (race_name != "human") print_female_names();
    if(race_name == "dwarf" || race_name == "dragonborn" || race_name == "gnome") print_clan_names();
    if(race_name == "elf" || race_name == "halfing") print_family_names();
    if(race_name == "elf" || race_name == "dragonborn") print_child_names();
    if (race_name == "human") print_human_names();
    if (race_name == "gnome") print_nicknames();

}


// file readers

void Race::read_int(istream& is, int& param, string target) {

    string marker;
    is >> marker;
    int number;
    is >> number;
    param = number;
}

void Race::read_strings(istream& is, vector<string>& param, string target) {
    string marker;
    is >> marker;
    char ch;
    is >> ch;
    if (ch!='{') {
        is.unget();
        is.clear(ios::failbit);
        // some handling or break go here
    }
    while(true) {
        string item;
        if(!(is >> item) || item == "}") break;
        param.push_back(item);
    }

}

void Race::read_human_names(istream& is, map<string, vector<string>>& param, string target) {

    vector<string> human_name_types = {"damaran_male_names", "damaran_female_names", "damaran_family_names"
                                      "illuskan_male_names", "illuskan_female_names", "illuskan_family_names",
                                      "mulan_male_names", "mulan_female_names", "mulan_family_names",
                                      "rashemi_male_names", "rashemi_female_names", "rashemi_family_names",
                                      "shou_male_names", "shou_female_names", "shou_family_names",
                                      "turami_male_names", "turami_female_names", "turami_family_names"};
    for(string s: human_name_types) {
        string marker;
        is >> marker;
        char ch;
        is >> ch;
        if (ch!='{') {
            is.unget();
            is.clear(ios::failbit);
            // some handling or break go here
        }
        while(true) {
            string item;
            if(!(is >> item) || item == "}") break;
            param[s].push_back(item);
        }

    }
}

istream& operator >> (istream& is, Race& rd)
{

    // todo: wrong input handle, seek for parameter marker to avoid order of parameters mistakes,
    //       skip line, clear strings from commas

    if ((rd.race_name == "elf") || (rd.race_name == "dwarf") || (rd.race_name == "human") || rd.race_name == "gnome")
        Race::read_strings(is, rd.subraces, "subraces");

    Race::read_int(is ,rd.min_age, "min_age");
    Race::read_int(is, rd.adult_age, "adult_age");
    Race::read_int(is, rd.max_age, "max_age");
    Race::read_int(is, rd.min_height, "min_height");
    Race::read_int(is, rd.max_height, "max_height");
    Race::read_int(is, rd.average_weight, "average_weight");

    if(rd.race_name == "human") Race::read_human_names(is, rd.human_names, "human_names");
    if(rd.race_name == "elf" || rd.race_name == "dragonborn") Race::read_strings(is, rd.child_names, "child_names");
    if (rd.race_name != "human") Race::read_strings(is, rd.male_names, "male_names");
    if (rd.race_name != "human") Race::read_strings(is, rd.female_names, "female_names");
    if(rd.race_name == "dwarf" || rd.race_name == "dragonborn" || rd.race_name == "gnome") Race::read_strings(is, rd.clan_names, "clan_names");
    if(rd.race_name == "elf" || rd.race_name == "halfing") Race::read_strings(is, rd.family_names, "family_names");
    if(rd.race_name == "gnome") Race::read_strings(is, rd.nicknames, "nicknames");
}


