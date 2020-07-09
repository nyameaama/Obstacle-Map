#ifndef MAP_2D 
#define MAP_2D

#include<stddef.h>
#include<stdint.h>
//#include"MapStructures.h"
#include"../utility/utility.h"
//#include<Arduino.h>

#define INIT (uint8_t) 1

class MAP2D_ {
    private:
        //template <typename T>
        uint8_t ADD_ON_TO_TABLE(uint8_t ID,uint8_t index,uint8_t value);

        //template <typename T>
        uint8_t searchTable(uint8_t ID,uint8_t bearing);

        uint8_t GET_ID_INDEX_CORRELATION(uint8_t ID);

        uint8_t ATTACH_TO_JSON();

    public:
        //template <typename T>
        uint8_t INIT_MAP(uint8_t TOKEN);

        //template <typename T>
        uint8_t UPDATE_2D(uint8_t ID,uint8_t bearing, uint8_t value);

        void DEBUG_PRINT();

};

#endif
