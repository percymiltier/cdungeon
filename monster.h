#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;


class Monster
{
    public:
        // init
        Monster(int lvl);

        // getters
        string getName() const;
        int getHP() const;
        int getATK() const;
        int getGold() const;
        int getItem() const;

        // takes a hit
        void takeHit(int dmg);
    private:
        string name;
        int HP;
        int ATK;
        int gold;
        bool item;
};

#endif
