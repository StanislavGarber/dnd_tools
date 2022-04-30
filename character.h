#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>

using namespace std;

class Character
{
private:
    string race;
    string subrace;
    char sex;
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
    char get_sex() { return sex; };

    void set_random_race();
    void set_random_subrace();
    void set_random_age();
    void set_random_size();
    void set_random_sex();
    void about();

};


#endif // CHARACTER_H
