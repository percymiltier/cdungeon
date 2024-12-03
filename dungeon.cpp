#include <stdlib.h>
#include <stdio.h>
#include <vector>

using namespace std;

#include "room.h"
#include "dungeon.h"


// make a dungeon
Dungeon::Dungeon(int num) {
    vector<Room> rooms;
    int numrooms = num;
}

// getters
vector<Room> Dungeon::getRooms() const { return rooms; }
int Dungeon::getNumrooms() const { return numrooms; }

// setters
void Dungeon::setRoom(vector<Room> newRooms) { rooms = newRooms;  }
void Dungeon::setNumrooms(int num) { numrooms = num; }