#ifndef MAZE_H
#define MAZE_H
#include<iostream>

enum Direzione{
        O, NO, N, NE, E, SE, S, SO
};

class Maze{
public:
    static const int mapSize{9}; 
    Maze(const std::string&, bool disp = false, bool polli = false);
    void displayMap() const;
    void setMap(const std::string&);
    void setPos();
    void cleanMap();
    bool isOutOfMap(const Direzione&) const;
    bool isPath(const Direzione&) const;
    bool isExit() const;
    void simpleMove(const Direzione&);
private:   
    bool disp;              //se attiva stampa la mappa ad ogni cambiamento
    bool polli;             //se attiva le caselle percorse vengono marchiate
    int position[2];
    char map[mapSize][mapSize];
};

#endif
