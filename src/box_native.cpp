#include <Arduino.h>
#include <box_app.h>
#include <box_native.h>

void roombox_init(roombox_s *obj){
  obj->box_led_wht_status = false;
  obj->box_led_clr_status = false;
  obj->box_buzzer_status = false;
  obj->box_air_qual_val  = -1;
}

void set_roombox_led_wht(roombox_s *obj, bool b){
  obj->box_led_wht_status = b;
}

void set_roombox_led_clr(roombox_s *obj, bool b){
  obj->box_led_clr_status = b;
}

void set_roombox_buzzer_status(roombox_s *obj, bool b){
  obj->box_buzzer_status = b;
}

void set_roombox_air_qual_val(roombox_s *obj, int i){
  obj->box_air_qual_val = i;
}

void set_roombox_hightemp_val(roombox_s *obj, int i){
  obj->box_hightemp_val = i;
}

bool get_roombox_led_wht(roombox_s *obj){
  return obj->box_led_wht_status;
}

bool get_roombox_led_clr(roombox_s *obj){
  return obj->box_led_clr_status;
}

bool get_roombox_buzzer_status(roombox_s *obj){
  return obj->box_buzzer_status;
}

int get_roombox_air_qual_val(roombox_s *obj){
  return obj->box_air_qual_val;
}

int get_roombox_hightemp_val(roombox_s *obj){
  return obj->box_hightemp_val;
}
