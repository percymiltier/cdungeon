#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <windows.h>

using namespace std;

#include "room.h"
#include "dungeon.h"


// make a dungeon
Dungeon::Dungeon(int num) {
    numrooms = num;
    currRoom = 0;
    int r;

    // generate a list of rooms
    for (int i = 0; i < num; i++) {
        rooms.push_back(Room(i));
    }

    // link them together
    for (int i = 1; i < num; i++) {
        int last = i - 1;
        r = rand() % 101;

        // prevent branching too hard, we want a mostly linear path
        if (!(rooms.at(last).isBranch()) && r < 35 && i != num - 1) {
            rooms.at(i).setBranch(true);
            r = rand() % 2;
            if (r == 1) {
                // room is attached at the last rooms right side
                rooms.at(last).setRightDoor(i);
                rooms.at(i).setLeftDoor(last);
            }
            else {
                // room is attached at the last rooms left side
                rooms.at(last).setLeftDoor(i);
                rooms.at(i).setRightDoor(last);
            }
        }

        else {
            // if the last room was a branch, link it to the non-branch room before it
            if (rooms.at(last).isBranch()) {
                rooms.at(last - 1).setTopDoor(i);
                rooms.at(i).setDownDoor(last - 1);
            }
            else {
                // link rooms together normally
                rooms.at(last).setTopDoor(i);
                rooms.at(i).setDownDoor(last);
            }
        }
    }

    // make a boss room at the middle and end of dungeon + set end of dungeon
    rooms.at(num - 1).setBossRoom(true);
    rooms.at(num - 1).setFinal(true);
    rooms.at(num - 1).setMonster(true);
    rooms.at(num / 2).setBossRoom(true);
    rooms.at(num / 2).setMonster(true);

    // monsters cannot spawn in the first room
    rooms.at(0).setMonster(false);
}

// getters
vector<Room> Dungeon::getRooms() const { return rooms; }
int Dungeon::getNumrooms() const { return numrooms; }
int Dungeon::getCurrRoom() const { return currRoom; }
Room Dungeon::getRoom(int num) const { return rooms.at(num); }

// setters
void Dungeon::setRooms(vector<Room> newRooms) { rooms = newRooms;  }
void Dungeon::setRoom(Room r, int num) { rooms.at(num) = r; }
void Dungeon::setNumrooms(int num) { numrooms = num; }
void Dungeon::setCurrRoom(int num) { currRoom = num; }

// extras
int Dungeon::inspectRoom(Room room, Player* p, Dungeon* d) {

    // return codes
    // -4:  player input an invalid value
    // -3:  chest open failure
    // -2:  opened a chest, got an item
    // -1:  did not move
    // >-1: changed rooms (returned number will be the new room number)

    int inINT;
    string inSTR;
    int count = 0;
    int r;

    // command codes might vary, so we need to record them
    int goback = 0;
    int goleft = -1;
    int goright = -1;
    int goup = -1;
    int godown = -1;
    int openchest = -1;

    cout << "\nYou look around...\n";
    Sleep(500);

    // doors
    if (room.getTopDoor() != -1) {
        cout << "There is a door at the end of the room.\n";
    }
    if (room.getLeftDoor() != -1) {
        cout << "There is a door to your left.\n";
    }
    if (room.getRightDoor() != -1) {
        cout << "There is a door to your right.\n\n";
    }
    if (room.getDownDoor() != -1) {
        cout << "There is a door behind you as well.\n";
    }

    // chest
    if (room.hasChest()) {
        cout << "There is a chest here.\n";
    }

    Sleep(250);
    cout << "\nWhat will you do?\n     " << count << ": Back to menu\n";
    count++;
    if (room.getLeftDoor() != -1) {
        cout << "     " << count << ": Go left\n";
        goleft = count;
        count++;
    }
    if (room.getRightDoor() != -1) {
        cout << "     " << count << ": Go right\n";
        goright = count;
        count++;
    }
    if (room.getTopDoor() != -1) {
        cout << "     " << count << ": Go forward\n";
        goup = count;
        count++;
    }
    if (room.getRoomNum() != 0 && room.getDownDoor() != -1) {
        cout << "     " << count << ": Go backward\n";
        godown = count;
        count++;
    }
    if (room.hasChest()) {
        cout << "     " << count << ": Open chest\n";
        openchest = count;
        count++;
    }

    cout << "\n";

    cin >> inINT;

    cout << "\n";

    // selection here
    if (inINT == goback) {
        // do nothing, go back to main menu
        Sleep(250);
        return -1;
    }
    else if (inINT == goleft) {
        // go to the left room
        Sleep(250);
        cout << "\n";
        cout << "  +---+          +---+\n";
        cout << "  |   |   <---   |   |\n";
        cout << "  +---+          +---+\n\n";
        cout << "You enter the room to the left.\n\n";
        return room.getLeftDoor();
    }
    else if (inINT == goright) {
        // go to the right room
        Sleep(250);
        cout << "\n";
        cout << "  +---+          +---+\n";
        cout << "  |   |   --->   |   |\n";
        cout << "  +---+          +---+\n\n";
        cout << "You enter the room to the right.\n";
        return room.getRightDoor();
    }
    else if (inINT == goup) {
        // go to the upper room
        Sleep(250);
        cout << "\n";
        cout << "  +---+\n";
        cout << "  |   |\n";
        cout << "  +---+\n\n";
        cout << "    ^  \n";
        cout << "    |  \n\n";
        cout << "  +---+\n";
        cout << "  |   |\n";
        cout << "  +---+\n\n";
        cout << "You move forward.\n";
        return room.getTopDoor();
    }
    else if (inINT == godown) {
        // go back to the last room
        Sleep(250);
        cout << "\n";
        cout << "  +---+\n";
        cout << "  |   |\n";
        cout << "  +---+\n\n";
        cout << "    |  \n";
        cout << "    V  \n\n";
        cout << "  +---+\n";
        cout << "  |   |\n";
        cout << "  +---+\n\n";
        cout << "You decide to go back to the previous room.\n";
        return room.getDownDoor();
    }
    else if (inINT == openchest) {
        // try to open the chest
        Sleep(250);
        if (!(room.isChestLocked())) {
            // chest isnt locked
            r = rand() % 5;
            if (r < 3) {
                // get potions
                r = rand() % 3 + 1;
                cout << "You got " << r << " potions from the chest. Nice!\n";
                p->setHeal(p->getHeal() + r);
                return -2;
            }
            else {
                // get lockpicks
                r = rand() % 3 + 1;
                cout << "You got " << r << " lockpicks from the chest. Nice!\n";
                p->setLockP(p->getLockP() + r);
                return -2;

            }
            p->addPts(r * 10);
        }
        else {
            // chest is locked
            if (p->getLockP() != 0) {
                cout << "This chest is locked... Use a lockpick? (LOCKPICKS REMAINING: " << p->getLockP() << ")\n\n     0: Yes\n     1: No\n";
                cin >> inINT;
                if (inINT == 0) {
                    // chest is now unlocked
                    r = rand() % 5;
                    if (r < 3) {
                        // get potions
                        r = rand() % 3 + 1;
                        Sleep(250);
                        cout << "You got " << r << " potions from the chest. Nice!\n";
                        p->setHeal(p->getHeal() + r);
                    }
                    else {
                        // get lockpicks
                        r = rand() % 3 + 1;
                        Sleep(250);
                        cout << "You got " << r << " lockpicks from the chest. Nice!\n";
                        p->setLockP(p->getLockP() + r);

                    }
                    p->addPts(r * 10);
                }
                else {
                    Sleep(250);
                    cout << "Please input a valid value next time.\n";
                    return -4;
                }

                // remove chest from room
                room.setChest(false);
                return -2;

            }
            else {
                Sleep(250);
                cout << "Too bad! This chest is locked, and you don't have a lockpick!\n";
                return -3;
            }
        }
    }
    else {
        Sleep(250);
        cout << "Please input a valid value.\n";
        return -4;
    }
}