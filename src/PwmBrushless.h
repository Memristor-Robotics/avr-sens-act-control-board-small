#ifndef _PWM_BRUSHLESS_H_
#define _PWM_BRUSHLESS_H_

#define MAX_OCR 20000

#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "CanBus.h"
#include "Pin.h"
#include "Config.h"

void Brushless_Calibration(void);

void Brushless_Init(Pin* pin);

void Brushless_Update(can_t* canMsg);

#endif
