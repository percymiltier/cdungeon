#ifndef DOOR_H
#define DOOR_H

#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "room.h"

using namespace std;

class Door
{
    public:
        Room getFrom() const;
        Room getTo() const;
    private:
        Room from;
        Room to;
};

#endif