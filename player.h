#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Player
{
    public:
        // initializer
        Player(string name);

        // getters
        string getName() const;
        int getLVL() const;
        int getMaxHP() const;
        int getCurrHP() const;
        int getATK() const;
        int getEXP() const;
        int getNextLVL() const;
        int getGold() const;
        int getLockP() const;
        int getHeal() const;
        int getpts() const;

        // adds exp to the player and levels them up if necessary
        void addEXP(int amt);

        // damages the player
        void takeHit(int dmg);

        // uses a lockpick and returns whether it worked or not
        bool usePick(); 
        
        // uses a potion
        bool useHeal();

        // prints the players stats to the screen
        void pStat(Player p);
    private:
        string name;
        int LVL;
        int maxHP;
        int currHP;
        int ATK;
        int EXP;
        int nextLVL;
        int gold;
        int lockP;
        int heal;
        int pts;
};

#endif