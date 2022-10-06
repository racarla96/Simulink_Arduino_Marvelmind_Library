//MarvelmindDriver.cpp 
#include "MarvelmindDriver.h"   
#include "Marvelmind.h"

#include <Arduino.h>

Stream * _HardSerial; // member within class

MarvelmindHedge hedge;
RawDistances rawDs;

#define BAUDRATE 115200

const int8_t sID0 = 0;
const int8_t sID1 = 1;
const int8_t sID2 = 2;
const int8_t sID3 = 3;

extern "C" void MarvelmindDriver_Init(int8_t serialID)
{ 
    if(serialID == sID0) {
        Serial.begin(BAUDRATE);
        _HardSerial = &Serial;
    }
    if(serialID == sID1) {
        Serial1.begin(BAUDRATE);
        _HardSerial = &Serial1;
    }
    if(serialID == sID2) {
        Serial2.begin(BAUDRATE);
        _HardSerial = &Serial2;
    }
    if(serialID == sID3) {
        Serial3.begin(BAUDRATE);
        _HardSerial = &Serial3;
    }

    hedge.begin(_HardSerial);
} 
extern "C" void MarvelmindDriver_Step(int8_t *updated, uint32_t *d1, uint32_t *d2, uint32_t *d3, uint32_t *d4) 
{ 
    *updated = 0;
    hedge.read(); // Update the information of the Serial
    
    if(hedge.getRawDistancesFromMarvelmindHedge(&rawDs)){
        *updated = 1;
        *d1 = rawDs.distances[0].distance;
        *d2 = rawDs.distances[1].distance;
        *d3 = rawDs.distances[2].distance;
        *d4 = rawDs.distances[3].distance;
    }
} 
extern "C" void MarvelmindDriver_Terminate() 
{ 
}