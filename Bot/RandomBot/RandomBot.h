#ifndef RANDOMBOT_H
#define RANDOMBOT_H
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Bot.h"

class RandomBot : public Bot{
public:
    int move(Maze& m) override;
};
#endif
