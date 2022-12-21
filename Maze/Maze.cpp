#include "Maze.h"
#include <fstream>
#include <thread>
#include <chrono>
#include <iostream>

Maze::Maze(const std::string& fname, bool disp, bool polli) : disp{disp}, polli{polli}, enemy{false}{
    setMap(fname);
    setPos();
}

void Maze::setMap(const std::string& fname){

    std::ifstream file;
    file.open(fname);
    if(!file.is_open()) throw std::invalid_argument("Impossibile aprire il file.");
    for(int r = 0; r < mapSize; r++){
        for(int c = 0; c < mapSize; c++){
            if(file.peek() != '\n' && file.peek() != '\r' && !file.eof()) file.get(map[r][c]);
            else map[r][c] = ' ';   //riempio eventuali spazi vuoti finali
        }
        if(file.eof() && r != mapSize-1) {
            if(file.is_open()) file.close();
            throw std::invalid_argument("Formato mappa invalido: troppo piccola.");
        }
        if(file.peek() == '\r') file.ignore();  //dovrebbe evitare problemi di encoding leggendo file generati da Windows
        if(file.peek() == '\n') file.ignore();
    }
    if(!file.eof()){
        if(file.is_open()) file.close();
        throw std::invalid_argument("Formato mappa invalido: troppo grande.");
    }
    file.close();
    return;
}

void Maze::setPos(){
    bool f = false;
    for(int r = 0; r < mapSize; r++)
        for(int c = 0; c < mapSize; c++){
            if(map[r][c] == 'S'){
                position[0][0] = r;
                position[0][1] = c;
                f = true;
            }
            if(map[r][c] == 'T'){
                position[1][0] = r;
                position[1][1] = c;
                enemy = true;
            }
        }
    if(!f) throw std::invalid_argument("Formato mappa invalido: manca punto di partenza."); //non è obbligatorio ci sia punto di arrivo
    if(!enemy){
        position[1][0] = -1;
        position[1][1] = -1;
    }
    if(disp) displayMap();
    return;
}

void Maze::cleanMap(){
    for(int r = 0; r < mapSize; r++)
        for(int c = 0; c < mapSize; c++)
            if(map[r][c] == '.') map[r][c] = ' ';
    return;
}

void Maze::displayMap() const {
    
    for(int r = 0; r < 2*mapSize; r++) std::cout << '_'; std::cout << std::endl;

    for(int r = 0; r < mapSize; r++){
        for(int c = 0; c < mapSize; c++){
            if(position[0][0] == r && position[0][1] == c)
                std::cout << 'P';
            else if(position[1][0] == r && position[1][1] == c)
                std::cout << 'M';
            else std::cout << map[r][c];
            std::cout << " ";
        } std::cout << '\n';
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200)); //delay per rendere l'output leggibile in tempo reale
}

bool Maze::isOutOfMap(const Direzione& d) const {
    switch(d){
        case O: 
            if(position[0][0] >= mapSize || position[0][0] < 0 || position[0][1]-1 >= mapSize || position[0][1]-1 < 0 ) return true;
            break;
        case NO: 
            if(position[0][0]-1 >= mapSize || position[0][0]-1 < 0 || position[0][1]-1 >= mapSize || position[0][1]-1 < 0 ) return true;
            break;
        case N: 
            if(position[0][0]-1 >= mapSize || position[0][0]-1 < 0 || position[0][1] >= mapSize || position[0][1] < 0 ) return true;
            break;
        case NE: 
            if(position[0][0]-1 >= mapSize || position[0][0]-1 < 0 || position[0][1]+1 >= mapSize || position[0][1]+1 < 0 ) return true;
           break;
        case E:
            if(position[0][0] >= mapSize || position[0][0] < 0 || position[0][1]+1 >= mapSize || position[0][1]+1 < 0 ) return true;
            break;
        case SE:
            if(position[0][0]+1 >= mapSize || position[0][0]+1 < 0 || position[0][1]+1 >= mapSize || position[0][1]+1 < 0 ) return true;
            break;
        case S: 
            if(position[0][0]+1 >= mapSize || position[0][0]+1 < 0 || position[0][1] >= mapSize || position[0][1] < 0 ) return true;
            break;
        case SO: 
            if(position[0][0]+1 >= mapSize || position[0][0]+1 < 0 || position[0][1]-1 >= mapSize || position[0][1]-1 < 0 ) return true;
            break;
        default: throw std::invalid_argument("Direzione non valida;");
    }
    return false;
}

bool Maze::isPath(const Direzione& d) const {
    if(isOutOfMap(d)) return false;
    switch(d){
        case O: 
            if(map[position[0][0]][position[0][1]-1] == '*') return false;
            break;
        case NO: 
            if(map[position[0][0]-1][position[0][1]-1] == '*') return false;
            break;
        case N: 
            if(map[position[0][0]-1][position[0][1]] == '*') return false;
            break;
        case NE: 
            if(map[position[0][0]-1][position[0][1]+1] == '*') return false; 
           break;
        case E:
            if(map[position[0][0]][position[0][1]+1] == '*') return false;
            break;
        case SE:
            if(map[position[0][0]+1][position[0][1]+1] == '*') return false;
            break;
        case S: 
            if(map[position[0][0]+1][position[0][1]] == '*') return false;
            break;
        case SO: 
            if(map[position[0][0]+1][position[0][1]-1] == '*') return false;
            break;
        default: throw std::invalid_argument("Direzione non valida;");
    }
    return true;
}

bool Maze::isExit() const {
    if(map[position[0][0]][position[0][1]] == 'E') return true;
    return false;   
}

void Maze::simpleMove(const Direzione& d){
    if(!isPath(d)) throw std::invalid_argument("Movimento in terreno non percorribile.");
    switch(d){
        case O: 
            --position[0][1];
            break;
        case NO: 
            --position[0][0]; --position[0][1];
            break;
        case N: 
            --position[0][0];
            break;
        case NE: 
            --position[0][0]; ++position[0][1];
            break;
        case E:
            ++position[0][1];
            break;
        case SE:
            ++position[0][0]; ++position[0][1];
            break;
        case S: 
            ++position[0][0];
            break;
        case SO: 
            ++position[0][0]; --position[0][1];
            break;
    }
    if(polli && map[position[0][0]][position[0][1]] == ' ')map[position[0][0]][position[0][1]] = '.';
    if(disp) displayMap();
    return;
}

bool Maze::isEOutOfMap(const Direzione& d) const {
    switch(d){
        case O: 
            if(position[1][0] >= mapSize || position[1][0] < 0 || position[1][1]-1 >= mapSize || position[1][1]-1 < 0 ) return true;
            break;
        case NO: 
            if(position[1][0]-1 >= mapSize || position[1][0]-1 < 0 || position[1][1]-1 >= mapSize || position[1][1]-1 < 0 ) return true;
            break;
        case N: 
            if(position[1][0]-1 >= mapSize || position[1][0]-1 < 0 || position[1][1] >= mapSize || position[1][1] < 0 ) return true;
            break;
        case NE: 
            if(position[1][0]-1 >= mapSize || position[1][0]-1 < 0 || position[1][1]+1 >= mapSize || position[1][1]+1 < 0 ) return true;
           break;
        case E:
            if(position[1][0] >= mapSize || position[1][0] < 0 || position[1][1]+1 >= mapSize || position[1][1]+1 < 0 ) return true;
            break;
        case SE:
            if(position[1][0]+1 >= mapSize || position[1][0]+1 < 0 || position[1][1]+1 >= mapSize || position[1][1]+1 < 0 ) return true;
            break;
        case S: 
            if(position[1][0]+1 >= mapSize || position[1][0]+1 < 0 || position[1][1] >= mapSize || position[1][1] < 0 ) return true;
            break;
        case SO: 
            if(position[1][0]+1 >= mapSize || position[1][0]+1 < 0 || position[1][1]-1 >= mapSize || position[1][1]-1 < 0 ) return true;
            break;
        default: throw std::invalid_argument("Direzione E non valida;");
    }
    return false;
}

bool Maze::isEPath(const Direzione& d) const {
    if(isEOutOfMap(d)) return false;
    switch(d){
        case O: 
            if(map[position[1][0]][position[1][1]-1] == '*') return false;
            break;
        case NO: 
            if(map[position[1][0]-1][position[1][1]-1] == '*') return false;
            break;
        case N: 
            if(map[position[1][0]-1][position[1][1]] == '*') return false;
            break;
        case NE: 
            if(map[position[1][0]-1][position[1][1]+1] == '*') return false; 
           break;
        case E:
            if(map[position[1][0]][position[1][1]+1] == '*') return false;
            break;
        case SE:
            if(map[position[1][0]+1][position[1][1]+1] == '*') return false;
            break;
        case S: 
            if(map[position[1][0]+1][position[1][1]] == '*') return false;
            break;
        case SO: 
            if(map[position[1][0]+1][position[1][1]-1] == '*') return false;
            break;
        default: throw std::invalid_argument("Direzione non valida;");
    }
    return true;
}

bool Maze::isEnemy() const {
    if(position[0][0] == position[1][0] && position[0][1] == position[1][1]) return true;
    return false;   
}

void Maze::simpleEMove(const Direzione& d){
    if(!isEPath(d)) throw std::invalid_argument("Movimento E in terreno non percorribile.");
    switch(d){
        case O: 
            --position[1][1];
            break;
        case NO: 
            --position[1][0]; --position[1][1];
            break;
        case N: 
            --position[1][0];
            break;
        case NE: 
            --position[1][0]; ++position[1][1];
            break;
        case E:
            ++position[1][1];
            break;
        case SE:
            ++position[1][0]; ++position[1][1];
            break;
        case S: 
            ++position[1][0];
            break;
        case SO: 
            ++position[1][0]; --position[1][1];
            break;
    }
    if(disp) displayMap();
    return;
}