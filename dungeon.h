#ifndef DUNGEON_H
#define DUNGEON_H

#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

#include "room.h"
#include "player.h"

class Dungeon {
    public:
        // make a dungeon
        Dungeon(int num);

        // getters
        vector<Room> getRooms() const;
        int getNumrooms() const;
        int getCurrRoom() const;
        Room getRoom(int num) const;

        // setters
        void setRoom(vector<Room> newRooms);
        void setNumrooms(int num);
        void setCurrRoom(int num);

        // extras
        int inspectRoom(Room room, Player p, Dungeon d);

    private:
        int numrooms;
        int currRoom;
        vector<Room> rooms;
};

#endif
