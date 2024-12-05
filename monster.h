#ifndef MONSTER_H
#define MONSTER_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

#include "player.h"
#include "mnames.h"

class Monster
{
    public:
        // init
        Monster(int lvl, bool isboss);

        // getters
        string getName() const;
        int getHP() const;
        int getATK() const;
        int getGold() const;
        int getItem() const;
        bool isBoss() const;

        // setters
        void setName(string in);
        void setHP(int num);
        void setATK(int num);
        void setGold(int num);
        void setItem(bool i);
        void setBoss(bool b);

        // fighting
        void takeHit(int dmg);
        int fightMonster(Monster m, Player p, int lvl);
    private:
        string name;
        int HP;
        int ATK;
        int gold;
        bool item;
        bool boss;
};

#endif
