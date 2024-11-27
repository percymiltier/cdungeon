#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "door.h"

class Room
{
    public:
        // init
        Room();

        // getters
        Door getTopDoor() const;
        Door getRightDoor() const;
        Door getDownDoor() const;
        Door getLeftDoor() const;
        bool getChest() const;
        bool getMonster() const;

        //
    private:
        int roomNum;

        // if the room has a door on each wall
        Door topDoor;
        Door rightDoor;
        Door downDoor;
        Door leftDoor;

        // things that can appear in the room
        bool chest;
        bool monster;
};

#endif