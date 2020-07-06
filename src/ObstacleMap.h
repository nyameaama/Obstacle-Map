#ifndef MAIN_
#define MAIN_

#include<stdint.h>
#include<stddef.h>
#include<string.h>

#define INIT (uint8_t) 1

template<typename TYPEDEF>
class OBSTACLEMAP {
    public:
        //Param = INIT token or custom specifier ID 
        uint8_t MAP2D(TYPEDEF TOKEN);

        //Param = INIT token or custom specifier ID 
        uint8_t MAP3D(TYPEDEF TOKEN);

        void ADD_TO_MAP_2D(uint8_t MAP_ID,TYPEDEF bearing, TYPEDEF value);

        void ADD_TO_MAP_3D(uint8_t MAP_ID,TYPEDEF bearing, TYPEDEF value,TYPEDEF ALTITUDE);

        //Returns file ID <char type>
        char* OUTPUT_TO_JSON(TYPEDEF TOKEN);
};

#endif