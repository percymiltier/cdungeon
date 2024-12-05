#ifndef ROOM_H
#define ROOM_H

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#include "player.h"


// Rooms are segments of a dungeon that hold monsters and loot
class Room
{
    public:
        // init
        Room(int num);

        // getters
        int getRoomNum() const;
        int getTopDoor() const;
        int getRightDoor() const;
        int getDownDoor() const;
        int getLeftDoor() const;
        bool hasChest() const;
        bool getMonster() const;
        bool isTrapRoom() const;
        bool isBossRoom() const;
        bool isBranch() const;
        bool isFinal() const;
        bool isChestLocked() const;

        // setters
        void setRoomNum(int num);
        void setTopDoor(int room);
        void setRightDoor(int room);
        void setDownDoor(int room);
        void setLeftDoor(int room);
        void setChest(bool c);
        void setMonster(bool m);
        void setTrapRoom(bool t);
        void setBossRoom(bool b);
        void setBranch(bool b);
        void setFinal(bool f);
        void setChestlock(bool c);

        // exploration

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
        bool chestlock;
        bool monster;

        // extras
        bool branch;
        bool trapRoom;
        bool bossRoom;
        bool final;
};

#endif
