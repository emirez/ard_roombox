#ifndef BOX_LED_H
#define BOX_LED_H

#include <box_native.h>

void box_app_led_starter(roombox_s *obj);

void box_app_buzzer_starter(roombox_s *obj, int i);

void box_app_buzzer_box_alive_sign();

bool box_app_motion_sensor();

#endif
