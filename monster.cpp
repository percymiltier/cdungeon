#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "monster.h"

// init
Monster::Monster(int lvl) {
    HP = 50 * lvl;
    ATK = 10 * lvl;
    
    int i = rand() % 50;
    gold = (5*lvl) + i;

    i = rand() % 2;
    if (i == 1) {
        item = true;
    }
}

void Monster::takeHit(int dmg) {
    ATK -= dmg;
}