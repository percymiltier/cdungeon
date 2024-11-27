#ifndef DOOR_H
#define DOOR_H

#include <stdlib.h>
#include <stdio.h>

#include "room.h"

using namespace std;

class Door
{
    public:
        Room getFrom() const;
        Room getTo() const;
        void setTo();
        void setFrom();
    private:
        Room from;
        Room to;
};

#endif