#include"ObstacleMap.h"

template<typename TYPEDEF>
 //Param = INIT token or custom specifier ID 
uint8_t OBSTACLEMAP::MAP2D(TYPEDEF TOKEN){
    MAP2D_ *obj = new MAP2D_;
    return obj -> INIT_MAP(TOKEN);
}

template<typename TYPEDEF>
//Param = INIT token or custom specifier ID 
uint8_t OBSTACLEMAP::MAP3D(TYPEDEF TOKEN){

}
template<typename TYPEDEF>
void OBSTACLEMAP::ADD_TO_MAP_2D(uint8_t MAP_ID,TYPEDEF bearing, TYPEDEF value){
    MAP2D_ *add = new MAP2D_;
    add -> UPDATE_2D(MAP_ID,bearing,value);
    delete add;
}
template<typename TYPEDEF>
void OBSTACLEMAP::ADD_TO_MAP_3D(uint8_t MAP_ID,TYPEDEF bearing, TYPEDEF value,TYPEDEF ALTITUDE){

}
template<typename TYPEDEF>
//Returns file ID <char type>
char* OBSTACLEMAP::OUTPUT_TO_JSON(TYPEDEF TOKEN){

}