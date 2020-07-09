#include"ObstacleMap.h"

//template<typename uint8_t>
 //Param = INIT token or custom specifier ID 
uint8_t OBSTACLEMAP::MAP2D(uint8_t TOKEN){
    MAP2D_ *obj = new MAP2D_;
    return obj -> INIT_MAP(TOKEN);
}

//template<typename uint8_t>
//Param = INIT token or custom specifier ID 
uint8_t OBSTACLEMAP::MAP3D(uint8_t TOKEN){

}
//template<typename uint8_t>
void OBSTACLEMAP::ADD_TO_MAP_2D(uint8_t MAP_ID,uint8_t bearing, uint8_t value){
    MAP2D_ *add = new MAP2D_;
    add -> UPDATE_2D(MAP_ID,bearing,value);
    delete add;
}
//template<typename uint8_t>
void OBSTACLEMAP::ADD_TO_MAP_3D(uint8_t MAP_ID,uint8_t bearing, uint8_t value,uint8_t ALTITUDE){

}
//template<typename uint8_t>
//Returns file ID <char type>
char* OBSTACLEMAP::OUTPUT_TO_JSON(uint8_t TOKEN){

}