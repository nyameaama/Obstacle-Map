#include"Map2D.h"

uint8_t ID_ARRAYINDEX_CORRELATION_DATA[64][64];
uint8_t IACD_count;

double MAP[64][64][2];
uint8_t mapSize = 64;

template <typename T>
uint8_t MAP2D::INIT_MAP(T TOKEN){
    UTILITY *funcs = new UTILITY;
    uint8_t ID = funcs -> GENERATE_ID();
    if(TOKEN == INIT){
        ID_ARRAYINDEX_CORRELATION_DATA[IACD_count][0] = ID;
        ID_ARRAYINDEX_CORRELATION_DATA[IACD_count][0] = IACD_count;
        IACD_count++;
        delete funcs;
        return ID;
    } else {
       //Add check function 
    }
}

template <typename T>
uint8_t MAP2D::UPDATE_2D(T ID,T bearing, T value){
    if(searchTable(ID,bearing) != (-1)){
        ADD_ON_TO_TABLE(ID,searchTable(ID,bearing),value);
    }else{

    }
}

template <typename T>
uint8_t  MAP2D::ADD_ON_TO_TABLE(T ID,uint8_t index,T value){
    uint8_t mapLocationIndex = GET_ID_INDEX_CORRELATION(ID);
    MAP[mapLocationIndex][index][1] = value;
    ATTACH_TO_JSON();
    return 1;
}

template <typename T>
uint8_t  MAP2D::searchTable(T ID,T bearing){
    //Get 
    uint8_t mapLocationIndex = GET_ID_INDEX_CORRELATION(ID);
    signed int finalIndex = -1;
    for(size_t i = 0; i < mapSize;++i){
        if(MAP[mapLocationIndex][i][0] != bearing){
            continue;
        }else{
            finalIndex = i;
            break;
        }
    }
    return finalIndex;
}

uint8_t MAP2D::ATTACH_TO_JSON(){

}

uint8_t MAP2D::GET_ID_INDEX_CORRELATION(uint8_t ID){
    signed int finalIndex = -1;
    for(size_t i = 0; i < mapSize;++i){
        if(ID_ARRAYINDEX_CORRELATION_DATA[i][0] != ID){
            continue;
        }else{
            finalIndex = i;
            break;
        }
    }
    return finalIndex;
}

 