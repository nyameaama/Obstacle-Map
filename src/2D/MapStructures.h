#include<stdint.h>
//IACD is the strucutre which holds references to the each map and their index in the 
//three dimensional MAP structure
uint8_t ID_ARRAYINDEX_CORRELATION_DATA[64][64];

//IACD count is the variable which corresponds to the number of maps stored. 
//It is incremented every time a new map ID is called 
uint8_t IACD_count;

//MAP is the main data structure which holds all maps that are created 
//It is three dimensional consisting of up to 64 different map structures which can be stored
//at runtime
double MAP[64][64][2];

//mapSize holds maximum size which can be allocated
uint8_t mapSize = 64;