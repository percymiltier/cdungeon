#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <windows.h>

#include "player.h"
#include "room.h"
#include "monster.h"
#include "dungeon.h"
#include "mnames.h"

using namespace std;

// game over screen
static void gameover(Player* p, Dungeon* d) {
    cout << "+---------- GAME OVER ----------+\n";
    cout << "  Last room explored: " << d->getCurrRoom() << "\n";
    cout << "  Total gold collected: " << p->getGold() << "\n\n";
    cout << "  Thanks for playing, " << p->getName() << "!\n";
    cout << "+-------------------------------+\n";
    exit(0);
}

// main menu
static void menu(Player* p, Dungeon* d) {
    Names names = Names();
    int in;
    Room room = d->getRoom(d->getCurrRoom());

    // check if the new room has a monster to fight
    if (room.getMonster()) {
        room.setMonster(false);
        d->setRoom(room, d->getCurrRoom());
        Monster mon = Monster(room.getRoomNum(), room.isBossRoom());
        names.printMon(mon.getName());
        if (mon.fightMonster(mon, p, room.getRoomNum()) == -1) {
            gameover(p, d);
        }
        p->pStat();
    }

    // Check if player has reached the end of the dungeon yet
    if (room.isFinal()) {
        // reached the end
        Sleep(250);
        cout << "\n\nCongratulations! You reached the last room... there's a ladder at the end of this hallway that looks like a way out. \nYou're free now!\n";
        cout << "\nFINAL STATS:\n";
        p->pStat();
        cout << "\n\nThanks for playing!\n";
    }
    else {
        Sleep(250);
        cout << "\nWhat will you do? \n";
        cout << "     0: Explore the room \n     1: Heal \n     2: Check Stats \n     3: Quit game\n";
        cin >> in;

        if (in == 0) {

            // explore room
            Sleep(250);
            int value = d->inspectRoom(room, p, d);
            if (value >= 0) {
                // if we moved, move the pointer too
                d->setCurrRoom(value);
            }
            else if (value == -2) {
                // remove chest from room if opened
                room.setChest(false);
                d->setRoom(room, d->getCurrRoom());
            }
            else if (value == -4) {
                value = d->inspectRoom(room, p, d);
            }
            menu(p, d);

        }
        else if (in == 1) {

            // heal
            Sleep(250);
            cout << "Use a potion? (Restores HP by 50)\nREMAINING POTIONS: " << p->getHeal() << "\n\n     0: Yes \n     1: No\n";
            cin >> in;

            if (in == 0) {
                int i = p->useHeal();
                if (i == -1) {
                    Sleep(250);
                    cout << "No healing items left...\n";
                }
                else if (i == -2) {
                    Sleep(250);
                    cout << "HP already full!\n";
                }
                else {
                    Sleep(250);
                    cout << "Healed " << i << "HP points.\n";
                }
            }
            else {
                Sleep(250);
                cout << "Didn't use a potion.(Current HP: " << p->getCurrHP() << ")\n";
            }

            menu(p, d);

        }
        else if (in == 2) {

            // check stats
            Sleep(250);
            p->pStat();
            menu(p, d);

        }
        else if (in == 3) {

            // quit game
            Sleep(250);
            cout << "\nAre you sure you want to quit? \n(Your progress will NOT be saved!) \n     0: I'm not sure... \n     1: Yes, quit.\n\n";
            cin >> in;
            if (in == 0) {
                // return to menu
                Sleep(250);
                menu(p, d);
            }
            else {
                // close the game
                Sleep(250);
                cout << "Goodbye, " << p->getName() << "\n";
                exit(0);
            }
        }
    }
}

// begins a game
static int engine() {
    int inNUM;
    string inSTR;
    Sleep(250);
    cout << "\nStart a new game?\n     0: YES\n     1: QUIT\n";
    cin >> inNUM;
    if (inNUM == 0) {
        // starts a new game

        // dungeon length
        cout << "\nChoose a game length:\n     0: Short\n     1: Medium\n     2: Long\n";
        cin >> inNUM;
        while (inNUM != 0 && inNUM != 1 && inNUM != 2) {
            cout << "Please enter a valid number.";
            cin >> inNUM;
        }

        // creates a new player
        Sleep(250);
        cout << "\nWhat is your name, hero? \n";
        cin >> inSTR;
        Player* p = new Player(inSTR);
        cout << "\n" << inSTR;
        Sleep(250);
        cout << ".";
        Sleep(250);
        cout << ".";
        Sleep(250);
        cout << ".\n";
        Sleep(500);
        cout << "You've woken up in this dungeon with no memory of how you got here";
        Sleep(250);
        cout << ".";
        Sleep(250);
        cout << ".";
        Sleep(250);
        cout << ".\n";
        Sleep(500);
        cout << "You must escape!\n";
        Sleep(500);

        // initializes the dungeon
        int r;
        if (inNUM == 0) {
            // short length
            r = rand() % 10 + 5;
        }
        else if (inNUM == 1) {
            // medium length
            r = rand() % 25 + 10;
        }
        else if (inNUM == 2) {
            // long length
            r = rand() % 50 + 25;

        }
        r = rand() % 21;
        if (r < 10) {
            r += 5;
        }
        Dungeon* d = new Dungeon(r);

        Sleep(250);
        menu(p, d);
    } else {
        // quits the game
        Sleep(250);
        cout << "So long, traveller.\n";
        Sleep(250);
        exit(0);
    }
    return inNUM;
}

// main
int main() {
    // program introduction
    cout << "------------------------------\n";
    cout << "+ Final Project for CPSC 370 +\n";
    cout << "------------------------------\n";
    cout << "+      By Percy Miltier      +\n";
    cout << "+    Text-Based Adventure    +\n";
    cout << "+        Dungeon Game        +\n";
    cout << "------------------------------\n\n";

    // loop the game as long as the player wants to keep playing
    while (1) {
        engine();
    }

}
