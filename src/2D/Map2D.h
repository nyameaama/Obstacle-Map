#ifndef MAP_2D 
#define MAP_2D

#include<stddef.h>
#include<stdint.h>
#include"../utility/utility.h"

#define INIT (uint8_t) 1

class MAP2D {
    private:
        template <typename T>
        uint8_t ADD_ON_TO_TABLE(uint8_t index,T value);

        template <typename T>
        uint8_t searchTable(T bearing);

        uint8_t ATTACH_TO_JSON();

    public:
        template <typename T>
        char* INIT_MAP(T TOKEN);

        template <typename T>
        uint8_t UPDATE_2D(T bearing, T value);

};

#endif
