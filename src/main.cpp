/***
*
* Sensors:         ----------   Actuators:
* ´´´´´´´                       ´´´´´´´´´
* Air Quality (A0)  ----------   LED Colour (D2)
* High Temp   (A1)  ----------   LED White  (D3)
* Motion      (D8)  ----------   Buzzer     (D4)
* BME280      (I2C) ----------   LED_Bar    (D5)
* ...               ----------   OLED       (I2C)
***/

#include <Arduino.h>
#include <Wire.h>
#include "box_app.h"
#include "box_native.h"
#include "box_airqua.h"
#include "box_oled.h"
#include "box_hightemp.h"
#include "box_ledbar.h"
#include "box_bme.h"

// Structs
roombox_s my_roombox_s;
airquality_s my_airquality_s;
oled_s my_oled_s;
hightemp_s my_hightemp_s;
ledbar_s my_ledbar_s;
bme_s my_bme_s;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  // Initialize the structs
  roombox_init(&my_roombox_s);
  my_hightemp_s.init();
  my_airquality_s.init();
  my_oled_s.init();
  my_ledbar_s.init();
  my_bme_s.init();
  // Set and Start - LED and Buzzer
  set_roombox_led_wht(&my_roombox_s, true);
  set_roombox_led_clr(&my_roombox_s, false);
  box_app_led_starter(&my_roombox_s);
  box_app_buzzer_starter(&my_roombox_s, 0);
  // Beep Beep = I am Alive!
  // box_app_buzzer_box_alive_sign();
}

void loop(){
  // Air Quality Actions
  my_oled_s.setTextXY(0,0);
  switch (my_airquality_s.slope()) {
      case 0:
        my_oled_s.putString("Dangerous Air");
        set_roombox_air_qual_val(&my_roombox_s, 0);
        set_roombox_buzzer_status(&my_roombox_s, true);
        box_app_buzzer_starter(&my_roombox_s, 200);
        my_ledbar_s.setBits(0b000000000000001);
        break;
      case 1:
        my_oled_s.putString("Smokey Air");
        set_roombox_air_qual_val(&my_roombox_s, 1);
        set_roombox_buzzer_status(&my_roombox_s, true);
        box_app_buzzer_starter(&my_roombox_s, 100);
        my_ledbar_s.setBits(0b000000000001111);
        break;
      case 2:
        my_oled_s.putString("Dirty Air");
        set_roombox_air_qual_val(&my_roombox_s, 2);
        set_roombox_buzzer_status(&my_roombox_s, true);
        box_app_buzzer_starter(&my_roombox_s, 50);
        my_ledbar_s.setBits(0b000000000111110);
        break;
      case 3:
        my_oled_s.putString("Fresh Air :)");
        set_roombox_air_qual_val(&my_roombox_s, 3);
        set_roombox_buzzer_status(&my_roombox_s, false);
        box_app_buzzer_starter(&my_roombox_s, 0);
        my_ledbar_s.setBits(0b000111111111100);
        break;
    }
    my_oled_s.setTextXY(1,0);
    my_oled_s.putString("+----------+");
    // High Temperature Actions
  // Motion Sensor Actions
  my_oled_s.setTextXY(2,0);
    if(box_app_motion_sensor()){
      my_oled_s.putString("Someone's In");
      set_roombox_led_clr(&my_roombox_s, true);
      box_app_led_starter(&my_roombox_s);
    }
    else {
      my_oled_s.putString("Empty Room..");
      set_roombox_led_clr(&my_roombox_s, false);
      box_app_led_starter(&my_roombox_s);
    }
    my_oled_s.setTextXY(3,0);
    my_oled_s.putString("+----------+");
    // BME Actions
    my_oled_s.setTextXY(4,0);
    my_oled_s.putString("Room Temp:");
    my_oled_s.setTextXY(4,10);
    my_oled_s.putNumber(my_bme_s.getTemperature());
    my_oled_s.setTextXY(5,0);
    my_oled_s.putString("Room Pres:");
    my_oled_s.setTextXY(5,10);
    my_oled_s.putNumber(my_bme_s.getPressure());
    my_oled_s.setTextXY(6,0);
    my_oled_s.putString("Room Humd:");
    my_oled_s.setTextXY(6,10);
    my_oled_s.putNumber(my_bme_s.getHumidity());
    my_oled_s.setTextXY(7,0);
    my_oled_s.putString("+----------+");
    // High Temperature Actions
    set_roombox_hightemp_val(&my_roombox_s, my_hightemp_s.getThmc());
    my_oled_s.setTextXY(8,0);
    my_oled_s.putString("High Temp:");
    my_oled_s.setTextXY(8,10);
    my_oled_s.putNumber(get_roombox_hightemp_val(&my_roombox_s));
}

// Interrupt Vector
ISR(TIMER1_OVF_vect)
{
	if(my_airquality_s.counter==61)//set 2 seconds as a detected duty
	{
			my_airquality_s.last_vol=my_airquality_s.first_vol;
			my_airquality_s.first_vol=analogRead(A0);
			my_airquality_s.counter=0;
			my_airquality_s.timer_index=1;
			PORTB=PORTB^0x20;
	}
	else { my_airquality_s.counter++; }
}
