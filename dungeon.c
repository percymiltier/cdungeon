#include <stdlib.h>
#include <stdio.h>

using namespace std;

#include "door.h"
#include "room.h"


// make a dungeon
Dungeon::Dungeon(int rooms) {
    Room[rooms];
}

// getters
Room[] Dungeon::getRooms() const;

// setters
Room[] Dungeon::setRoom(int roomNumber);