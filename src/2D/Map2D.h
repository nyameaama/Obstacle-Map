#ifndef MAP_2D 
#define MAP_2D

#include<stddef.h>
#include<stdint.h>
//#include"MapStructures.h"
#include"../utility/utility.h"
//#include<Arduino.h>
#include<iostream>

#define INIT (uint8_t) 1

class MAP2D_ {
    private:
        //Structure to determine map location for individual IDs
        uint8_t ADD_NEW_MAP_TO_CORRELATION_ARRAY(uint8_t ID,uint8_t NUMBER_OF_MAPS);

        //Function returns the next available index position inside IACD data structure
        uint8_t IACD_NEXT_AVAILABLE_INDEX_POS();

        //Function checks to see if ID exists
        uint8_t CHECK_IF_ID_EXISTS(uint8_t ID);


    private:
        //Function to add incoming data to map using ID to determine container where data will be stored
        uint8_t ADD_ON_TO_MAP(uint8_t ID,uint8_t index,uint8_t value);

        //Determine last index used to avoid wrong memory overwrite. Add bearing to container at 
        //last index + 1 and add value to container as well
        uint8_t ADD_NEW_BEARING(uint8_t ID,uint8_t bearing);

        //Function to linear search Map for corresponding bearing and return index if found
        uint8_t SEARCH_FOR_BEARING(uint8_t ID,uint8_t bearing);

        //Function gets position of corresponding sub map in the three dimensional
        //data structure using the map ID 
        uint8_t GET_ID_INDEX_CORRELATION(uint8_t ID);

        uint8_t ATTACH_TO_JSON();

    public:
        //Function adds new ID and new map location to ID correlation array
        uint8_t INIT_MAP(uint8_t TOKEN);

        //Use ID to determine map location. -> If bearing not in map then add to map -> else
        //search for bearing in map
        uint8_t UPDATE_2D(uint8_t ID,uint8_t bearing, uint8_t value);

        void DEBUG_PRINT();

};

#endif
