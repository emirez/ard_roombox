#ifndef __BOX_HIGHTEMP_H__
#define __BOX_HIGHTEMP_H__

typedef struct hightemp_s{

public:
    float getRoomTmp();                      //
    float getThmc();
    void init();
private:
    int pinRoomTmp;                         // pin of temperature sensor
    int pinThmc;                            // pin of thermocouple
    float tempRoom;                         // room temperature
    float tempThmc;                         // thermocouple temperature
public:
    int getAnalog(int pin);
    float K_VtoT(float mV);                 // K type thermocouple, mv->oC
    float getThmcVol();                     // get voltage of thmc in mV
} hightemp_s;

#endif
