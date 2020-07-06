#ifndef MAP_2D 
#define MAP_2D

#include<stddef.h>
#include<stdint.h>
#include"../utility/utility.h"

#define INIT (uint8_t) 1

class MAP2D {
    private:
        template <typename T>
        uint8_t ADD_ON_TO_TABLE(T ID,uint8_t index,T value);

        template <typename T>
        uint8_t searchTable(T ID,T bearing);

        uint8_t GET_ID_INDEX_CORRELATION(uint8_t ID);

        uint8_t ATTACH_TO_JSON();

    public:
        template <typename T>
        uint8_t INIT_MAP(T TOKEN);

        template <typename T>
        uint8_t UPDATE_2D(T ID,T bearing, T value);

};

#endif
