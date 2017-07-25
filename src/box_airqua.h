#ifndef BOX_AIRQUA__H
#define BOX_AIRQUA__H

#include <box_native.h>

typedef struct airquality_s
{
public:
    int i ;
    long vol_standard;
    int init_voltage;
    int first_vol;
    int last_vol;
    int temp;
    int counter;
    bool timer_index;
    bool error;
    void init();
    int slope(void);
private:
    int _pin;
    void avgVoltage(void);
} airquality_s;

#endif
