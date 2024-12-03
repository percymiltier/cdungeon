#ifndef DUNGEON_H
#define DUNGEON_H

#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

#include "room.h"

class Dungeon {
    public:
        // make a dungeon
        Dungeon(int num);

        // getters
        vector<Room> getRooms() const;
        int getNumrooms() const;

        // setters
        void setRoom(vector<Room> newRooms);
        void setNumrooms(int num);
    private:
        int numrooms;
        vector<Room> rooms;
};

#endif
