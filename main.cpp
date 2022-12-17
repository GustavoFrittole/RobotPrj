#include<iostream>
#include "Maze.h"
#include "RandomBot.h"
#include "RightHandRuleBot.h"
int main(){
    
    RandomBot rb; 
    RightHandRuleBot rhrb;
        
    //RandomBot presente ma non eseguito perché lento
    //Il progetto poteva essere realizzato in modo che 
    
    std::cout << "\n------MapGen Setup-------\n\n";
    Maze mazeGen("../mapGenerator/map.txt", true, true);

    std::cout << "\n------RandomBot-------\n\n";
    //rb.move(mazeGen);
    
    std::cout << "\n------Clean up-------\n\n";
    mazeGen.cleanMap();
    mazeGen.setPos();
    
    std::cout << "\n------RightHandRuleBot-------\n\n";
    rhrb.move(mazeGen);
    
    std::cout << "\n------Map Setup-------\n\n";
    Maze maze("../MapFiles/Map.txt", true, true);
    
    std::cout << "\n------RandomBot-------\n\n";
    //rb.move(maze);
    
    std::cout << "\n------Clean up-------\n\n";
    maze.cleanMap();
    maze.setPos();
    
    std::cout << "\n------RightHandRuleBot-------\n\n";
    rhrb.move(maze);
    
    std::cout << "\n------Map1 Setup-------\n\n";
    Maze maze1("../MapFiles/Map1.txt", true, true);
    
    std::cout << "\n------RandomBot-------\n\n";
    //rb.move(maze1);
    
    std::cout << "\n------Clean up-------\n\n";
    maze1.cleanMap();
    maze1.setPos();
    
    std::cout << "\n------RightHandRuleBot-------\n\n";
    rhrb.move(maze1);
    
    
    std::cout << "\n------Map2 Setup-------\n\n";
    Maze maze2("../MapFiles/Map2.txt", true, true);
    
    std::cout << "\n------RandomBot-------\n\n";
    //rb.move(maze2);
    
    std::cout << "\n------Clean up-------\n\n";
    maze2.cleanMap();
    maze2.setPos();
    
    std::cout << "\n------RightHandRuleBot-------\n\n";
    rhrb.move(maze2);
    
    
    std::cout << "\n------Map3 Setup-------\n\n";
    Maze maze3("../MapFiles/Map3.txt", true, true);
    
    std::cout << "\n------RandomBot-------\n\n";
    //rb.move(maze3);
    
    std::cout << "\n------Clean up-------\n\n";
    maze3.cleanMap();
    maze3.setPos();
    
    std::cout << "\n------RightHandRuleBot-------\n\n";
    rhrb.move(maze3);
    
    return 0;
}