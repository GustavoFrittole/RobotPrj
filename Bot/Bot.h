#ifndef BOT_H
#define BOT_H
#include "Maze.h"

class Bot{
public:
    virtual int move(Maze&) = 0;
};

#endif