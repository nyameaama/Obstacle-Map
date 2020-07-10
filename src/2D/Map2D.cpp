#include"MAP2D.h"

//IACD is the strucutre which holds references to the each map and their index in the 
//three dimensional MAP structure
uint8_t ID_ARRAYINDEX_CORRELATION_DATA[5][2];

//IACD count is the variable which corresponds to the number of maps stored. 
//It is incremented every time a new map ID is called 
uint8_t IACD_count;

//MAP is the main data structure which holds all maps that are created 
//It is three dimensional consisting of up to 64 different map structures which can be stored
//at runtime
double MAP[1][64][2];

//mapSize holds maximum sub arrays which can be allocated
uint8_t mapSize = 64;
//Container to hold number of maps which can be allocated
uint8_t MAX_MAPS = 1;


//Structure to determine map location for individual IDs
uint8_t ADD_NEW_MAP_TO_CORRELATION_ARRAY(uint8_t ID,uint8_t NUMBER_OF_MAPS){
    ID_ARRAYINDEX_CORRELATION_DATA[IACD_count][0] = ID;
    ID_ARRAYINDEX_CORRELATION_DATA[IACD_count][1] = NUMBER_OF_MAPS;
    IACD_count++;
    return;
}

//Function returns the next available index position inside IACD data structure
uint8_t IACD_NEXT_AVAILABLE_INDEX_POS(){
    return (IACD_count);   
}

//Function adds new ID and new map location to ID correlation array
uint8_t MAP2D_::INIT_MAP(uint8_t TOKEN){
    //UTILITY *funcs = new UTILITY;
    //uint8_t ID = getID -> GENERATE_ID();
    uint8_t nextPos = IACD_NEXT_AVAILABLE_INDEX_POS();
    uint8_t ID = 5;
    if(TOKEN == INIT){
        ADD_NEW_MAP_TO_CORRELATION_ARRAY(ID,nextPos);
        //delete funcs;
        return ID;
    } else {
       //Add check function 
    }
}

//Determine last index used to avoid wrong memory overwrite. Add bearing to container at 
//last index + 1 and add value to container as well
uint8_t MAP2D_::ADD_NEW_BEARING(uint8_t ID,uint8_t bearing){

}

//Use ID to determine map location. -> If bearing not in map then add to map -> else
//search for bearing in map
uint8_t MAP2D_::UPDATE_2D(uint8_t  ID,uint8_t bearing, uint8_t  value){
    //Using ID, search for bearing sub-array in map
    if(SEARCH_FOR_BEARING(ID,bearing) != (-1)){
        //If index containing bearing is found, add data to map and release back to main program
        ADD_ON_TO_MAP(ID,SEARCH_FOR_BEARING(ID,bearing),value);
    }else{
        //If bearing is not found in current map, create new bearing sub-array
        //and call UPDATE_2D again 
        ADD_NEW_BEARING(ID,bearing);
        UPDATE_2D(ID,bearing,value);
    }
    //DEBUG_PRINT();
}

uint8_t  MAP2D_::ADD_ON_TO_MAP(uint8_t ID,uint8_t index,uint8_t  value){
    //Call IACD function to retrieve sub map position which corresponds with the ID
    uint8_t mapLocationIndex = GET_ID_INDEX_CORRELATION(ID);
    //Overwrite previous value stored with incoming value 
    MAP[mapLocationIndex][index][1] = value;
    //ATTACH_TO_JSON();
    return 1;
}

//Function to linear search Map for corresponding bearing and return index if found
uint8_t  MAP2D_::SEARCH_FOR_BEARING(uint8_t ID,uint8_t bearing){
    //Call IACD function to retrieve sub map position which corresponds with the ID
    uint8_t mapLocationIndex = GET_ID_INDEX_CORRELATION(ID);
    //Variable holding return index
    signed int finalIndex = -1;
    //Iterate through each sub array in corresponding map to find the bearing.
    //If bearing is found return 
    for(size_t i = 0; i < mapSize;++i){
        if(MAP[mapLocationIndex][i][0] != bearing){
            continue;
        }else{
            finalIndex = i;
            break;
        }
    }
    //Return;
    return finalIndex;
}

//Function gets position of corresponding sub map in the three dimensional
//data structure using the map ID 
uint8_t MAP2D_::GET_ID_INDEX_CORRELATION(uint8_t ID){
    //Variable holding return index
    signed int finalIndex = -1;
    // //Iterate through each sub array in IACD to find the sub map location.
     //If location is found, return 
    for(size_t i = 0; i < IACD_count;++i){
        if(ID_ARRAYINDEX_CORRELATION_DATA[i][0] != ID){
            continue;
        }else{
            finalIndex = i;
            break;
        }
    }
    //Return
    return finalIndex;
}

 void MAP2D_::DEBUG_PRINT(){
     //for(size_t i = 0; i < 64;++i){
        // Serial.println(MAP[0][i][0]);
        // Serial.println(MAP[0][i][1]);
        //std::cout << MAP[0][0][0] << std::endl;
        //std::cout << MAP[0][0][1] << std::endl;
     //}
 }

 int main(){
     MAP2D_ *obj1 = new MAP2D_;
     uint8_t ID = obj1 ->INIT_MAP(1);
    obj1 ->SEARCH_FOR_BEARING(ID,ID);
     //obj1 -> UPDATE_2D(ID,60,5);
     obj1 -> DEBUG_PRINT();
     return 0;
 }