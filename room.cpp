#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "room.h"

// initializes an unconnected room with a random monster and chest value
Room::Room() {
    topDoor = nullptr;
    rightDoor = nullptr;
    downDoor = nullptr;
    leftDoor = nullptr;

    int i = rand() % 5;
    if (i < 2) {
        chest = true;
    } else {
        chest = false;
    }

    i = rand() % 5;
    if (i < 2) {
        monster = false;
    } else {
        monster = true;
    }
}


// getters
Door getTopDoor() const { return topDoor; }
Door getRightDoor() const { return rightDoor; }
Door getDownDoor() const { return downDoor; }
Door getLeftDoor() const { return leftDoor; }
bool getChest() const { return chest; }
bool getMonster() const { return monster; }

// setters
void setTopDoor(Door door) { topDoor = door; }
void setRightDoor(Door door) { rightDoor = door; }
void setDownDoor(Door door) { downDoor = door; }
void setLeftDoor(Door door) { leftDoor = door; }
void setChest(bool c) { chest = c; }
void setMonster(bool m) { monster = m;}