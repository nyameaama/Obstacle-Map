#ifndef FORMAT
#define FORMAT

#include"../2D/Map2D.h"
#include<stdint.h>
#include<stddef.h>

class RETURN_FORMAT {
    private:
        typedef double DEFAULT_MAP_TYPE;

    private:
        DEFAULT_MAP_TYPE **CHANGE_TO_2D(uint8_t sub_map_pos,DEFAULT_MAP_TYPE ***array);

    public:
        DEFAULT_MAP_TYPE **FORMAT_MAP(uint8_t ID,DEFAULT_MAP_TYPE ***map);


};


#endif