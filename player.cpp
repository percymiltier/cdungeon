#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "player.h"
#include "main.cpp"

// init
Player::Player(string givenName) {
    name = givenName;
    LVL = 1;
    maxHP = 50;
    currHP = 50;
    ATK = 10;
    EXP = 0;
    nextLVL = 50;
    gold = 0;
    lockP = 3;
    heal = 2;
    pts = 0;
}

// getters
string Player::getName() const { return name; }
int Player::getLVL() const { return LVL; }
int Player::getMaxHP() const { return maxHP; }
int Player::getCurrHP() const { return currHP; }
int Player::getATK() const { return ATK; }
int Player::getEXP() const { return EXP; }
int Player::getNextLVL() const { return nextLVL; }
int Player::getGold() const { return gold; }
int Player::getLockP() const { return lockP; }
int Player::getHeal() const { return heal; }
int Player::getpts() const { return pts; }


// adds EXP to the player
void Player::addEXP(int amt) {
    EXP += amt;
    if (EXP >= nextLVL) {
        LVL++;
        EXP -= nextLVL;
        nextLVL = nextLVL * 1.25;
    }
}

// damages the player
void Player::takeHit(int dmg) {
    currHP -= dmg;
}

// uses a lockpick and returns whether it worked or not
bool Player::usePick() {
    lockP--;
    int i = rand() % 100+1;
    if (i <= 75) {
        return true;
    }
    return false;
}

// uses a potion, returns true if successful
bool Player::useHeal() {
    if (heal != 0) {
        heal--;
        currHP += 50;
        if (currHP > maxHP) {
            currHP = maxHP;
        }
        return true;
    }
    return false;
}


// prints the players stats to the screen
void Player::pStat(Player p) {
    usleep(1000);
    cout << "\n" << p.getName() << ":\n";
    cout << "+ ---------- STATS ---------- +\n";
    cout << "LVL: " << p.getLVL() << "\n";
    cout << "To next level: " << p.getEXP() << "/" << p.getNextLVL() << "\n";
    cout << "ATK: " << p.getATK() << "\n";
    cout << "HP: " << p.getCurrHP() << "/" << p.getMaxHP() << "\n";
    cout << "+ ---------- ITEMS ---------- + \n";
    cout << "Gold: " << p.getGold() << "\n";
    cout << "Lockpicks: " << p.getLockP() << "\n";
    cout << "Potions: " << p.getHeal() << "\n";
    cout << "+ --------------------------- + \n";
    cout << "CURRENT POINTS: " << p.getpts() << "\n";
    menu(p);
}