#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <cerrno>
#include <unistd.h>

#include "player.h"
#include "room.h"
#include "monster.h"
#include "door.h"

using namespace std;

// main menu
void menu(Player p) {
    int in;
    cout << "\nWhat will you do? \n";
    usleep(1000);
    cout << "0: Explore the room \n1:Use Item \n2:Check Stats \n3: Inspect Room \n4:Quit game\n";
    cin >> in;
    if (in == 0) {
        // explore room

    } else if (in == 1) {
        // use an item

    } else if (in == 2) {
        // check stats

        pStat(p);
    } else if (in == 3) {
        // inspect room

    } else if (in == 4) {
        // quit game
        usleep(1000);
        cout << "\nAre you sure you want to quit? \n(Your progress will NOT be saved!) \n0: I'm not sure... \n1: Yes, quit.";
        cin >> in;
        if (in == 0) {
            // return to menu
            menu(p);
        } else {
            // close the game
            cout << "Goodbye, " << p.getName() << "\n";
            exit(0);
        }
    }
}

// begins a game
int engine() {
    int inNUM;
    string inSTR;
    cout << "\nStart a new game?\n 0: YES\n1: QUIT\n";
    cin >> inNUM;
    if (inNUM == 0) {
        // starts a new game
        cout << "\nWhat is your name, hero? \n";
        cin >> inSTR;
        Player p(inSTR);
        cout << "\n" << inSTR << "...";
        usleep(1000);
        cout << "You've woken up in this dungeon with no memory of how you got here...\n";
        usleep(1000);
        cout << " You must escape!\n";
        menu(p);
    } else {
        // quits the game
        cout << "So long, traveller.\n";
        exit(0);
    }
    return inNUM;
}

// main
int main() {
    // loop the game as long as the player wants to keep playing
    while (1) {
        engine();
    }
}