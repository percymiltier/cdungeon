#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include <cerrno>

#include "player.h"
#include "room.h"
#include "monster.h"

using namespace std;

// main menu
static void menu(Player p) {
    int in;
    cout << "\nWhat will you do? \n";
    cout << "0: Explore the room \n1:Use Item \n2:Check Stats \n3: Inspect Room \n4:Quit game\n";
    cin >> in;
    if (in == 0) {
        // explore room

    } else if (in == 1) {
        // use an item

    } else if (in == 2) {
        // check stats
        p.pStat(p);
        menu(p);

    } else if (in == 3) {
        // inspect room

    } else if (in == 4) {
        // quit game
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
static int engine() {
    int inNUM;
    string inSTR;
    cout << "\nStart a new game?\n 0: YES\n1: QUIT\n";
    cin >> inNUM;
    if (inNUM == 0) {
        // starts a new game

        cout << "\nWhat is your name, hero? \n";
        cin >> inSTR;
        Player p = Player(inSTR);
        cout << "\n" << inSTR << "...";
        cout << "You've woken up in this dungeon with no memory of how you got here...\n";
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
