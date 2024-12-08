#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <windows.h>

using namespace std;

#include "monster.h"
#include "mnames.h"
#include "player.h"

// init
Monster::Monster(int lvl, bool isboss) {
    Names names = Names();
    if (isboss) {
        HP = 10 * lvl * 1.6;
        ATK = 2.5 * lvl;

        int i = rand() % 500;
        gold = (200) + i;

        item = true;
        boss = true;
        name = names.getName("b");
    }
    else {
        HP = 10 * lvl * 1.25;
        ATK = 1.25 * lvl;

        int i = rand() % 50;
        gold = (2 * lvl) + i;

        i = rand() % 2;
        if (i == 1) {
            item = true;
        }
        else {
            item = false;
        }
        boss = false;
        name = names.getName("n");
    }
}

// getters
string Monster::getName() const { return name; }
int Monster::getHP() const { return HP; }
int Monster::getATK() const { return ATK; }
int Monster::getGold() const { return gold; }
int Monster::getItem() const { return item; }
bool Monster::isBoss() const { return boss; }

// setters
void Monster::setName(string in) { name = in; }
void Monster::setHP(int num) { HP = num; }
void Monster::setATK(int num) { ATK = num; }
void Monster::setGold(int num) { gold = num; }
void Monster::setItem(bool i) { item = i; }
void Monster::setBoss(bool b) { boss = b; }

// fighting
void Monster::takeHit(int dmg) {
    HP -= dmg;
}

int Monster::fightMonster(Monster m, Player* p, int lvl) {

    // return codes
    //  0: player won
    // -1: monster won

    bool fighting = true;
    int r;
    string turn = "m";
    int in;
    int DMG;
    int playerHP;

    cout << m.name << " attacks!\n";

    while (fighting) {
        if (m.getHP() <= 0 || p->getCurrHP() <= 0) {
            // done fighting
            fighting = false;
        }
        else {
            if (turn == "m") {
                // monsters turn
                // determine DMG
                if (m.isBoss()) {
                    r = rand() % 50 + 20;
                }
                else {
                    r = rand() % 10;
                }
                DMG = m.getATK() + r;
                
                // determine if it hits or misses
                r = rand() % 50;
                if (r > 35) {
                    // miss
                    cout << m.getName() << " took a swing at you, but missed!\n\n";
                }
                else {
                    // hit
                    p->takeHit(DMG);
                    cout << m.getName() << " swings at you. Ouch! Took " << DMG << " damage!\n\n";
                }

                cout << "CURRENT HP: " << p->getCurrHP() << "\n\n";

                turn = "p";
            }
            else if (turn == "p") {
                // players turn
                cout << "What will you do?\n     0: Attack\n     1: Heal\n     2: Try to run\n\n";
                cin >> in;

                if (in == 0) {
                    // attack
                    r = rand() % 35 + 10;
                    DMG = p->getATK() + (r * (p->getLVL() / 2));

                    // determine if it hits or misses
                    r = rand() % 50;
                    if (r > 40) {
                        // miss
                        cout << "You tried to swing at the monster, but you missed!\n";
                    }
                    else {
                        // hit
                        m.takeHit(DMG);
                        cout << "You swung at the monster! It took " << DMG << " damage!\n";
                    }

                    turn = "m";
                }
                else if (in == 1) {
                    // heal
                    if (p->getHeal() > 0) {
                        // heal player
                        playerHP = p->getCurrHP();
                        p->useHeal();
                        cout << "Healed " << (p->getCurrHP() - playerHP) << " HP!\n";
                        turn = "m";
                    }
                    else {
                        // not enough healing items
                        cout << "Out of healing items!\n";
                    }
                }
                else if (in == 2) {
                    // try to run
                    r = rand() % 101;
                    if (r > 75) {
                        // success!
                        cout << "Got away successfully!\n (NO EXP GAINED)\n";
                        return 0;
                    }
                    else {
                        // failure
                        cout << "Couldn't get away!\n";
                        turn = "m";
                    }
                }
                else {
                    // wrong input
                    cout << "Please input a real value.\n";
                }
            }
        }
    }

    // end of battle
    if (p->getCurrHP() > 0) {
        p->setGold(p->getGold() + m.getGold());
        p->addPts(lvl * 10 + 5);
        r = rand() % 20 + 10;
        p->addEXP(lvl * r * 0.75);
        cout << m.getName() << " was defeated!\n";
        return 0;
    }
    
    return -1;
}