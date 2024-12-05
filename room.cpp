#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

#include "room.h"
#include "player.h"

// initializes an unconnected room with a random monster and chest value
Room::Room(int num) {
    roomNum = num;
    topDoor = -1;
    downDoor = -1;
    rightDoor = -1;
    leftDoor = -1;
    bossRoom = false;
    branch = false;
    final = false;
    chestlock = false;

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

    i = rand() % 9;
    if (i < 3) {
        trapRoom = true;
    }
    else {
        trapRoom = false;
    }

    if (chest) {
        i = rand() % 5;
        if (i < 2) {
            chestlock = true;
        }
    }
}


// getters
int Room::getRoomNum() const { return roomNum; }
int Room::getTopDoor() const { return topDoor; }
int Room::getRightDoor() const { return rightDoor; }
int Room::getDownDoor() const { return downDoor; }
int Room::getLeftDoor() const { return leftDoor; }
bool Room::hasChest() const { return chest; }
bool Room::getMonster() const { return monster; }
bool Room::isTrapRoom() const { return trapRoom; }
bool Room::isBossRoom() const { return bossRoom; }
bool Room::isBranch() const { return branch; }
bool Room::isFinal() const { return final; }
bool Room::isChestLocked() const { return chestlock; }

// setters
void Room::setRoomNum(int num) { roomNum = num; }
void Room::setTopDoor(int room) { topDoor = room; }
void Room::setRightDoor(int room) { rightDoor = room; }
void Room::setDownDoor(int room) { downDoor = room; }
void Room::setLeftDoor(int room) { leftDoor = room; }
void Room::setChest(bool c) { chest = c; }
void Room::setMonster(bool m) { monster = m;}
void Room::setTrapRoom(bool t) { trapRoom = t; }
void Room::setBossRoom(bool b) { bossRoom = b; }
void Room::setBranch(bool b) { branch = b; }
void Room::setFinal(bool f) { final = f; }
void Room::setChestlock(bool c) { chestlock = c; }

