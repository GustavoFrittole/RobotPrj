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
    bool isEOutOfMap(const Direzione&) const;
    bool isPath(const Direzione&) const;
    bool isEPath(const Direzione&) const;
    bool isExit() const;
    bool isEnemy() const;
    bool getEnemy() const {return enemy;}
    void simpleMove(const Direzione&);
    void simpleEMove(const Direzione&);
private:   
    bool disp;              //se attiva stampa la mappa ad ogni cambiamento
    bool polli;             //se attiva le caselle percorse vengono marchiate
    bool enemy;
    int position[2][2];
    char map[mapSize][mapSize];
};

#endif
