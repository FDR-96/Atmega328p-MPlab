/*
 * PWM.h
 *
 * Created: 16/03/2019 13:05:34
 *  Author: marlon
 */ 


#ifndef PWM_H_
#define PWM_H_

	#include <avr/io.h>

	void PWM_init(int freq);
	void PWM_on();
	void PWM_off();

	void PWM_setDuty(int duty);


#endif /* PWM_H_ */