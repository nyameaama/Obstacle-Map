#include"Format.h"

typedef double DEFAULT_MAP_TYPE;

DEFAULT_MAP_TYPE **RETURN_FORMAT::CHANGE_TO_2D(uint8_t sub_map_pos,DEFAULT_MAP_TYPE ***array){
    uint8_t len;
    DEFAULT_MAP_TYPE returnStruct[64][64];
    for(size_t i = 0; i < len;++i){
        returnStruct[i][0] = array[sub_map_pos][i][0];
        returnStruct[i][1] = array[sub_map_pos][i][1];
    }
    //return returnStruct;
}

 DEFAULT_MAP_TYPE **RETURN_FORMAT::FORMAT_MAP(uint8_t ID,DEFAULT_MAP_TYPE ***map){
    MAP2D_ *pos = new MAP2D_;
    uint8_t sub_map_pos = pos -> GET_ID_INDEX_CORRELATION(ID);
    delete pos;
    return CHANGE_TO_2D(sub_map_pos,map);
 }