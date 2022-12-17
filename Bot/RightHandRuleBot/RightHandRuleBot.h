#ifndef RHRB_H
#define RHRB_H
#include<iostream>
#include<cstdlib>
#include<ctime>
#include "Bot.h"

class RightHandRuleBot : public Bot{
public:
    int move(Maze& m) override;
};
#endif
