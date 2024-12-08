#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <windows.h>

using namespace std;

#include "player.h"

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

// setters
void Player::setLVL(int num) { LVL = num; }
void Player::setMaxHP(int num) { maxHP = num; }
void Player::setCurrHP(int num) { currHP = num; }
void Player::setATK(int num) { ATK = num; }
void Player::setEXP(int num) { EXP = num; }
void Player::setNextLVL(int num) { nextLVL = num; }
void Player::setGold(int num) { gold = num; }
void Player::setLockP(int num) { lockP = num; }
void Player::setHeal(int num) { heal = num; }
void Player::setpts(int num) { pts = num; }

// adds EXP to the player
void Player::addEXP(int amt) {
    EXP += amt;
    while (EXP >= nextLVL) {
        LVL++;
        EXP -= nextLVL;
        nextLVL = nextLVL * 1.25;

        // add to players stats after leveling up + restore HP as a bonus
        ATK += 10;
        maxHP += 15;
        currHP = maxHP;
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

// uses a potion, returns -1 if failed, returns amount of HP restored if successful, returns -2 if HP is already full
int Player::useHeal() {
    if (heal != 0 && currHP != maxHP) {
        int restore = currHP;
        heal--;
        currHP += 50;
        if (currHP > maxHP) {
            currHP = maxHP;
        }
        return currHP - restore;
    }
    else if (currHP == maxHP) {
        return -2;
    }
    return -1;
}

// adds points for defeating monsters and getting items
void Player::addPts(int num) {
    pts += num;
}

// prints the players stats to the screen
void Player::pStat() {
    Sleep(500);
    cout << "\n" << name << ":\n";
    cout << "+ ---------- STATS ---------- +\n";
    cout << "  LVL: " << LVL << "\n";
    cout << "  To next level: " << EXP << "/" << nextLVL << "\n";
    cout << "  ATK: " << ATK << "\n";
    cout << "  HP: " << currHP << "/" << maxHP << "\n";
    cout << "+ ---------- ITEMS ---------- + \n";
    cout << "  Gold: " << gold << "\n";
    cout << "  Lockpicks: " << lockP << "\n";
    cout << "  Potions: " << heal << "\n";
    cout << "+ --------------------------- + \n";
    cout << "CURRENT POINTS: " << pts << "\n";
}