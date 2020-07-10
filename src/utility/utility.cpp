#include"utility.h"

//Vraible to store previous number
uint8_t previousNum;

uint8_t UTILITY::GENERATE_ID(){
    return (previousNum += 1);
}