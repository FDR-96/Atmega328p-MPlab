/*
 * File:   PWM.c
 * Author: FDR-96
 *
 * Created on 21 de febrero de 2021, 19:44
 */

#ifndef PWM_H_
#define PWM_H_

	#include <avr/io.h>

	void PWM_init(int freq);
	void PWM_on();
	void PWM_off();

	void PWM_setDuty(int duty);


#endif /* PWM_H_ */