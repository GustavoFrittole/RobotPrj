#include "RandomBot.h"

int RandomBot::move(Maze& m){
    srand(time(NULL));
    while(!m.isExit() && !m.isEnemy()){
        int tempD = rand()%8;
        if(m.isPath(Direzione(tempD))) m.simpleMove(Direzione(tempD));
        tempD = rand()%8;
        if(m.isEPath(Direzione(tempD))) m.simpleEMove(Direzione(tempD));
    }
    return 1;
}