#ifndef MAIN_
#define MAIN_

#include<stdint.h>
#include<stddef.h>
#include<string.h>

#include"2D/Map2D.h"

#define INIT (uint8_t) 1

class OBSTACLEMAP {
    public:
        template<typename TYPEDEF>
        //Param = INIT token or custom specifier ID 
        uint8_t MAP2D(TYPEDEF TOKEN);

        template<typename TYPEDEF>
        //Param = INIT token or custom specifier ID 
        uint8_t MAP3D(TYPEDEF TOKEN);

        template<typename TYPEDEF>
        void ADD_TO_MAP_2D(uint8_t MAP_ID,TYPEDEF bearing, TYPEDEF value);

        template<typename TYPEDEF>
        void ADD_TO_MAP_3D(uint8_t MAP_ID,TYPEDEF bearing, TYPEDEF value,TYPEDEF ALTITUDE);

        template<typename TYPEDEF>
        //Returns file ID <char type>
        char* OUTPUT_TO_JSON(TYPEDEF TOKEN);
};

#endif