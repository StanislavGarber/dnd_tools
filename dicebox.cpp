#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "dicebox.h"

int Dicebox::roll_dice(int facets){
    return rand() % facets + 1;
}

int Dicebox::roll_dices(int dices, int facets){
    int result = 0;
    for (int i = 0; i < dices; i++){
        result += roll_dice(facets);
    }
    return result;
}
