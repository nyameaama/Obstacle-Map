#include"MAP2D.h"

//IACD is the strucutre which holds references to the each map and their index in the 
//three dimensional MAP structure
uint8_t ID_ARRAYINDEX_CORRELATION_DATA[18][2];

//IACD count is the variable which corresponds to the number of maps stored. 
//It is incremented every time a new map ID is called 
uint8_t IACD_count;

//MAP is the main data structure which holds all maps that are created 
//It is three dimensional consisting of up to 64 different map structures which can be stored
//at runtime
double MAP[1][64][2];

//mapSize holds maximum size which can be allocated
uint8_t mapSize = 64;

//template <typename T>
uint8_t MAP2D_::INIT_MAP(uint8_t TOKEN){
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

//template <typename T>
uint8_t MAP2D_::UPDATE_2D(uint8_t  ID,uint8_t bearing, uint8_t  value){
    if(searchTable(ID,bearing) != (-1)){
        ADD_ON_TO_TABLE(ID,searchTable(ID,bearing),value);
    }else{

    }
    //DEBUG_PRINT();
}

//template <typename T>
uint8_t  MAP2D_::ADD_ON_TO_TABLE(uint8_t ID,uint8_t index,uint8_t  value){
    uint8_t mapLocationIndex = GET_ID_INDEX_CORRELATION(ID);
    MAP[mapLocationIndex][index][1] = value;
    //ATTACH_TO_JSON();
    return 1;
}

//template <typename T>
uint8_t  MAP2D_::searchTable(uint8_t  ID,uint8_t  bearing){
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

uint8_t MAP2D_::ATTACH_TO_JSON(){

}

uint8_t MAP2D_::GET_ID_INDEX_CORRELATION(uint8_t ID){
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

 void MAP2D_::DEBUG_PRINT(){
     for(size_t i = 0; i < 64;++i){
        // Serial.println(MAP[0][i][0]);
        // Serial.println(MAP[0][i][1]);
     }
 }