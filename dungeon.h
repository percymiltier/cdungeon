#ifndef DUNGEON_H
#define DUNGEON_H

#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "door.h"
#include "room.h"

class Dungeon {
    public:
        // make a dungeon
        Dungeon(int rooms);

        // getters
        Room[] getRooms() const;

        // setters
        Room[] setRoom(int roomNumber);
    private:
        Room[];
};

#endif
