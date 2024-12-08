#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <windows.h>

using namespace std;

class Player
{
    public:
        // initializer
        Player(string givenName);

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

        // setters
        void setLVL(int num);
        void setMaxHP(int num);
        void setCurrHP(int num);
        void setATK(int num);
        void setEXP(int num);
        void setNextLVL(int num);
        void setGold(int num);
        void setLockP(int num);
        void setHeal(int num);
        void setpts(int num);

        // adds exp to the player and levels them up if necessary
        void addEXP(int amt);

        // damages the player
        void takeHit(int dmg);

        // uses a lockpick and returns whether it worked or not
        bool usePick(); 
        
        // uses a potion
        int useHeal();

        // prints the players stats to the screen
        void pStat();

        // adds points for defeating monsters and getting items
        void addPts(int num);
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
