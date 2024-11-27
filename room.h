#ifndef ROOM_H
#define ROOM_H

#include <stdlib.h>
#include <stdio.h>

using namespace std;


// Rooms are segments of a dungeon that hold monsters and loot
class Room
{
    public:
        // init
        Room();

        // getters
        int getTopDoor() const;
        int getRightDoor() const;
        int getDownDoor() const;
        int getLeftDoor() const;
        bool getChest() const;
        bool getMonster() const;

        // setters
        void setTopDoor(int door);
        void setRightDoor(int door);
        void setDownDoor(int door);
        void setLeftDoor(int door);
        void setChest(bool c);
        void setMonster(bool m);
    private:
        //room id
        int roomNum;

        // if the room has a door on each wall
        int topDoor;
        int rightDoor;
        int downDoor;
        int leftDoor;

        // things that can appear in the room
        bool chest;
        bool monster;
};

#endif
