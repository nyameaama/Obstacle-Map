#ifndef FILTER
#define FILTER

#include<stdint.h>
#include<stddef.h>
#include<stdlib.h>
#include<math.h>

class STAT_FILTER {
    public:
        double AVT_STATISTICAL_FILTERING(double *set);

        double STANDARD_DEVIATION(double *array);

        double AVERAGE_FILTER(double *array);

};

#endif