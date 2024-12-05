#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>

#include "player.h"
#include "room.h"
#include "monster.h"
#include "dungeon.h"

using namespace std;

// game over screen
void gameover(Player p, Dungeon d) {
    cout << "+---------- GAME OVER ----------+";
    cout << "  Last room explored: " << d.getCurrRoom() << "\n";
    cout << "  Total gold collected: " << p.getGold() << "\n\n";
    cout << "  Thanks for playing, " << p.getName() << "!\n";
    cout << "+-------------------------------+\n";
    exit(0);
}

// main menu
void menu(Player p, Dungeon d) {
    int in;
    Room room = d.getRoom(d.getCurrRoom());

    // check if the new room has a monster to fight
    if (room.getMonster()) {
        room.setMonster(false);
        Monster mon = Monster(room.getRoomNum(), room.isBossRoom());
        if (mon.fightMonster(mon, p, room.getRoomNum()) == -1) {
            gameover(p, d);
        }
    }

    // Check if player has reached the end of the dungeon yet
    if (d.getNumrooms() == room.getRoomNum() - 1) {
        // reached the end
        cout << "Congratulations! You reached the last room... there's a ladder at the end of this hallway that looks like a way out. \nYou're free now!\n";
        cout << "\nFINAL STATS:\n";
        p.pStat(p);
        cout << "\n\nThanks for playing!\n";
    }
    else {

        cout << "\nWhat will you do? \n";
        cout << "     0: Explore the room \n     1: Heal \n     2: Check Stats \n     3: Quit game\n";
        cin >> in;

        if (in == 0) {

            // explore room
            int value = d.inspectRoom(room, p, d);
            if (value >= 0) {
                // if we moved, move the pointer too
                d.setCurrRoom(value);
            }
            else if (value == -4) {
                value = d.inspectRoom(room, p, d);
            }
            menu(p, d);

        }
        else if (in == 1) {

            // heal
            cout << "Use a potion? (Restores HP by 50)\nREMAINING POTIONS: " << p.getHeal() << "\n\n     0: Yes \n     1: No\n";
            cin >> in;

            if (in == 0) {
                int i = p.useHeal();
                if (i == -1) {
                    cout << "No healing items left...\n";
                }
                else if (i == -2) {
                    cout << "HP already full!\n";
                }
                else {
                    cout << "Healed " << i << "HP points.\n";
                }
            }
            else {
                cout << "Didn't use a potion.(Current HP: " << p.getCurrHP() << ")\n";
            }

            menu(p, d);

        }
        else if (in == 2) {

            // check stats
            p.pStat(p);
            menu(p, d);

        }
        else if (in == 3) {

            // quit game
            cout << "\nAre you sure you want to quit? \n(Your progress will NOT be saved!) \n     0: I'm not sure... \n     1: Yes, quit.\n\n";
            cin >> in;
            if (in == 0) {
                // return to menu
                menu(p, d);
            }
            else {
                // close the game
                cout << "Goodbye, " << p.getName() << "\n";
                exit(0);
            }
        }
    }
}

// begins a game
int engine() {
    int inNUM;
    string inSTR;
    cout << "\nStart a new game?\n     0: YES\n     1: QUIT\n";
    cin >> inNUM;
    if (inNUM == 0) {
        // starts a new game

        // creates a new player
        cout << "\nWhat is your name, hero? \n";
        cin >> inSTR;
        Player p = Player(inSTR);
        cout << "\n" << inSTR << "...";
        cout << "You've woken up in this dungeon with no memory of how you got here...\n";
        cout << "You must escape!\n";

        // initializes the dungeon
        int r = rand() % 21;
        if (r < 10) {
            r += 5;
        }
        Dungeon d = Dungeon(r);

        menu(p, d);
    } else {
        // quits the game
        cout << "So long, traveller.\n";
        exit(0);
    }
    return inNUM;
}

// main
int main() {
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
