#ifndef ROOM_H
#define ROOM_H

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

        // setters
        void setTopDoor(Door door);
        void setRightDoor(Door door);
        void setDownDoor(Door door);
        void setLeftDoor(Door door);
        void setChest(bool c);
        void setMonster(bool m);
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