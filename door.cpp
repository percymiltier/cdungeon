#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "room.h"
#include "door.h"

using namespace std;


Room Door::getFrom() const {
    return from;
}

Room Door::getTo() const {
    return to;
}