#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "room.h"

// initializes an unconnected room with a random monster and chest value
Room::Room() {

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
int Room::getTopDoor() const { return topDoor; }
int Room::getRightDoor() const { return rightDoor; }
int Room::getDownDoor() const { return downDoor; }
int Room::getLeftDoor() const { return leftDoor; }
bool Room::getChest() const { return chest; }
bool Room::getMonster() const { return monster; }

// setters
void Room::setTopDoor(int door) { topDoor = door; }
void Room::setRightDoor(int door) { rightDoor = door; }
void Room::setDownDoor(int door) { downDoor = door; }
void Room::setLeftDoor(int door) { leftDoor = door; }
void Room::setChest(bool c) { chest = c; }
void Room::setMonster(bool m) { monster = m;}