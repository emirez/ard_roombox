#ifndef BOX_NATIVE_H
#define BOX_NATIVE_H

typedef struct roombox_s {
public:
		bool box_led_wht_status;			 /**< White LED on/off status */
		bool box_led_clr_status;			 /**< Color LED on/off status */
	  bool box_buzzer_status;        /**< Buzzer    on/off status */
		int box_air_qual_val;					 /**< Air Quality value */
		int box_hightemp_val;					 /**< High Temperature value */
} roombox_s;

void roombox_init(roombox_s *obj);

void set_roombox_led_wht(roombox_s *obj, bool b);

void set_roombox_led_clr(roombox_s *obj, bool b);

void set_roombox_buzzer_status(roombox_s *obj, bool b);

void set_roombox_air_qual_val(roombox_s *obj, int i);

void set_roombox_hightemp_val(roombox_s *obj, int i);

bool get_roombox_led_wht(roombox_s *obj);

bool get_roombox_led_clr(roombox_s *obj);

bool get_roombox_buzzer_status(roombox_s *obj);

int get_roombox_air_qual_val(roombox_s *obj);

int get_roombox_hightemp_val(roombox_s *obj);

#endif
