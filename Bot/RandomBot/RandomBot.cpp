#include "RandomBot.h"

int RandomBot::move(Maze& m){
    srand(time(NULL));
    while(!m.isExit() && !m.isEnemy()){
            int tempD = rand()%8;
            while(!m.isPath(Direzione(tempD))) tempD = rand()%8;
            m.simpleMove(Direzione(tempD));
        if(m.getEnemy()){
            if(m.isEnemy()) break;
            tempD = rand()%8;
            while(!m.isEPath(Direzione(tempD))) tempD = rand()%8;
            m.simpleEMove(Direzione(tempD));
        }
    }
    return 1;
}