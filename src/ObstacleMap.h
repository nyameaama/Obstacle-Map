#ifndef MAIN_
#define MAIN_

#include<stdint.h>
#include<stddef.h>
#include<string.h>

#include"2D/Map2D.h"

#define INIT (uint8_t) 1

class OBSTACLEMAP {
    public:
        //template<typename uint8_t>
        //Param = INIT token or custom specifier ID 
        uint8_t MAP2D(uint8_t TOKEN);

        //template<typename uint8_t>
        //Param = INIT token or custom specifier ID 
        uint8_t MAP3D(uint8_t TOKEN);

        //template<typename uint8_t>
        void ADD_TO_MAP_2D(uint8_t MAP_ID,uint8_t bearing, uint8_t value);

        //template<typename uint8_t>
        void ADD_TO_MAP_3D(uint8_t MAP_ID,uint8_t bearing, uint8_t value,uint8_t ALTITUDE);

        //template<typename uint8_t>
        //Returns file ID <char type>
        char* OUTPUT_TO_JSON(uint8_t TOKEN);
};

#endif