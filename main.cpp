#include<iostream>
#include "Maze.h"
#include "RandomBot.h"
#include "RightHandRuleBot.h"
int main(){
    
    RandomBot rb; 
    RightHandRuleBot rhrb;
        
    //Funzione attiva solo per RandomBot
    //Il nemico M (non E perche' gia' exit, quindi Mostro)
    //Nasce dalla tana T (solo se presente), si muove come un RandomBot e in sontanza
    //costituisce una via d'uscita alternativa che si puo' immaginare essere "meno piacevole"
    //Idea nata per supplire alla lentazza di RandBot nal raggiungere l'uscita
    
    std::cout << "\n------MapGen Setup-------\n\n";
    Maze mazeGen("../mapGenerator/map.txt", true, false);

    std::cout << "\n------RandomBot-------\n\n";
    rb.move(mazeGen);
    
    std::cout << "\n------Clean up-------\n\n";
    mazeGen.cleanMap();
    mazeGen.setPos();
    
    std::cout << "\n------RightHandRuleBot-------\n\n";
    //rhrb.move(mazeGen);
    
    std::cout << "\n------Map Setup-------\n\n";
    Maze maze("../MapFiles/Map.txt", true, false);
    
    std::cout << "\n------RandomBot-------\n\n";
    rb.move(maze);
    
    std::cout << "\n------Clean up-------\n\n";
    maze.cleanMap();
    maze.setPos();
    
    std::cout << "\n------RightHandRuleBot-------\n\n";
    //rhrb.move(maze);
    
    std::cout << "\n------Map1 Setup-------\n\n";
    Maze maze1("../MapFiles/Map1.txt", true, false);
    
    std::cout << "\n------RandomBot-------\n\n";
    rb.move(maze1);
    
    std::cout << "\n------Clean up-------\n\n";
    maze1.cleanMap();
    maze1.setPos();
    
    std::cout << "\n------RightHandRuleBot-------\n\n";
    rhrb.move(maze1);
    
    
    std::cout << "\n------Map2 Setup-------\n\n";
    Maze maze2("../MapFiles/Map2.txt", true, false);
    
    std::cout << "\n------RandomBot-------\n\n";
    //rb.move(maze2);
    
    std::cout << "\n------Clean up-------\n\n";
    maze2.cleanMap();
    maze2.setPos();
    
    std::cout << "\n------RightHandRuleBot-------\n\n";
    rhrb.move(maze2);
    
    
    std::cout << "\n------Map3 Setup-------\n\n";
    Maze maze3("../MapFiles/Map3.txt", true, false);
    
    std::cout << "\n------RandomBot-------\n\n";
    //rb.move(maze3);
    
    std::cout << "\n------Clean up-------\n\n";
    maze3.cleanMap();
    maze3.setPos();
    
    std::cout << "\n------RightHandRuleBot-------\n\n";
    rhrb.move(maze3);
    
    return 0;
}