#ifndef RACE_H
#define RACE_H

#include <string>
#include <vector>
#include <iostream>
#include <filesystem>
#include <map>


using  namespace std;

class Race
{
public:

    string race_name;

    vector<string> subraces {};
    vector<string> male_names {};
    vector<string> female_names {};
    vector<string> clan_names {};
    vector<string> child_names {};
    vector<string> family_names {};
    vector<string> nicknames {};
    vector<string> virtue_names {};

    map<string, vector<string>> human_names;

    int min_age;
    int adult_age;
    int max_age;
    int min_height;
    int max_height;
    int average_weight;

    Race(string s) {
        race_name = s;
    };

    // printing class info

    void print_int_parameter(string name, int& parameter);
    void print_string_vector_data(string name, vector<string>& parameter);

    void print_min_age();
    void print_adult_age();
    void print_max_age();
    void print_min_height();
    void print_max_height();
    void print_average_weight();

    void print_subraces();
    void print_male_names();
    void print_female_names();
    void print_clan_names();
    void print_child_names();
    void print_family_names();
    void print_human_names();
    void print_nicknames();
    void print_virtue_names();

    void print_data(); // prints all data about race


    friend istream& operator >> (istream& is, Race& rd);
    void static read_int(istream& is, int& param, string target);
    void static read_strings(istream& is, vector<string>& param, string target);
    void static read_human_names(istream& is, map<string, vector<string>>& param, string target);

};



#endif // RACE_H
