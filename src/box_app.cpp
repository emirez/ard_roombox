#include <Arduino.h>
#include <box_app.h>
#include <box_native.h>

#define AIR_QUAL_PORT_A 0
#define LED_WHT_PORT_D 2
#define LED_CLR_PORT_D 3
#define BUZZER_PORT_D 4
#define MOTION_PORT_D 8


// LEDs
void box_app_led_starter(roombox_s *obj){
  pinMode(LED_WHT_PORT_D, OUTPUT);
  pinMode(LED_CLR_PORT_D, OUTPUT);
  digitalWrite(LED_WHT_PORT_D, get_roombox_led_wht(obj));
  digitalWrite(LED_CLR_PORT_D, get_roombox_led_clr(obj));
}

// Buzzer
void box_app_buzzer_box_alive_sign(){
  pinMode(BUZZER_PORT_D, OUTPUT);

    for(int i = 0; i<2; i++){
        digitalWrite(BUZZER_PORT_D, HIGH);
        delay(100);
        digitalWrite(BUZZER_PORT_D, LOW);
        delay(100);
        }
}

void box_app_buzzer_starter(roombox_s *obj, int i){
  if ( i==0 ){
    digitalWrite(BUZZER_PORT_D, LOW);
  }
      else {
        pinMode(BUZZER_PORT_D, OUTPUT);
        digitalWrite(BUZZER_PORT_D, get_roombox_buzzer_status(obj));
        delay(i);
        digitalWrite(BUZZER_PORT_D, !get_roombox_buzzer_status(obj));
        delay(i*5);
        }
}

bool box_app_motion_sensor()
{
    if ( digitalRead(MOTION_PORT_D) )
    {
        return true;
    }
    else
    {
        return false;
    }
}
