#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "room.h"

// initializes an unconnected room with a random monster and chest value
Room Room::Room() {
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