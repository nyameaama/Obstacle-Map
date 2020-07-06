#include"Map2D.h"

double MAP[64][64];
uint8_t mapSize = 64;

template <typename T>
char* MAP2D::INIT_MAP(T TOKEN){
    UTILITY *funcs = new UTILITY;
    if(TOKEN == INIT)
        return funcs -> GENERATE_ID();
    else {
       //Add check function 
    }
}

template <typename T>
uint8_t MAP2D::UPDATE_2D(T bearing, T value){
    if(searchTable(bearing) != (-1)){
        ADD_ON_TO_TABLE(searchTable(bearing),value);
    }else{

    }
}

template <typename T>
uint8_t  MAP2D::ADD_ON_TO_TABLE(uint8_t index,T value){
    MAP[index][0] = value;
    ATTACH_TO_JSON();
    return 1;
}

template <typename T>
uint8_t  MAP2D::searchTable(T bearing){
    signed int finalIndex = -1;
    for(size_t i = 0; i < mapSize;++i){
        if(MAP[i][0] != bearing){
            continue;
        }else{
            finalIndex = MAP[i][0];
            break;
        }
    }
    return finalIndex;
}

uint8_t MAP2D::ATTACH_TO_JSON(){
    
}