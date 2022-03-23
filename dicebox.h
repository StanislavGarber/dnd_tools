#ifndef DICEBOX_H
#define DICEBOX_H

class Dicebox {

public:
    int roll_dice(int facets);
    int roll_dices(int dices, int facets);
    int* get_standart_facets();
    int standart_facets[7] = {4, 6, 8, 10, 12, 20, 100};
};


#endif // DICEBOX_H
