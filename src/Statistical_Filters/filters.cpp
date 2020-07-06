#include"filters.h"

double STAT_FILTER::AVT_STATISTICAL_FILTERING(double *set){
    //AVT algorithm
    uint8_t size = sizeof(set)/sizeof(set[0]);
    //Calculate the standard deviation and average value
    double StandardDeviation = STANDARD_DEVIATION(set);
    double AVG = AVERAGE_FILTER(set);
    double *dropData = (double*)malloc(1);
    uint8_t dropDataIndex = 0;
    //Drop any data that is greater or less than average ± one standard deviation
    for(size_t i = 0; i < size;i++){
        if(set[i] < (AVG - StandardDeviation) || set[i] > (AVG + StandardDeviation)){
            continue;
        }else{
            dropData[dropDataIndex] = set[i];
            dropDataIndex++;
            realloc(dropData,dropDataIndex + 1);
        }
    }
    //Calculate average value of remaining data and present result as actual value representing data sample
    double finAvg = AVERAGE_FILTER(dropData);
    free(dropData);
    return finAvg;
}

double STAT_FILTER::STANDARD_DEVIATION(double *array){
    uint8_t size = sizeof(array)/sizeof(array[0]);
    //Work out the AVG
    double mean = AVERAGE_FILTER(array);
    double *temp = (double*)malloc(size);
    //for each number, subtract the Mean and square the result
    for(size_t i = 0; i < size;i++){
        temp[i] = pow((array[i] - mean),2);
    }
    //work out the mean of those squared differences.
    double finalMean = AVERAGE_FILTER(temp);
    free(temp);
    //Take the square root and return
    return sqrt(finalMean);
}

double STAT_FILTER::AVERAGE_FILTER(double *array){
    //Average Function
    double avg,sum;
    uint8_t size = sizeof(array)/sizeof(array[0]);
    for(size_t i = 0; i < size;i++){
        sum += array[i];
    }
    return avg = sum / size; 
}