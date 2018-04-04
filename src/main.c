#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "CanBus.h"
#include "Uart.h"
#include "Pin.h"
#include "Config.h"


int main() {


#ifdef DEBUG
	char uart_char1, uart_char2;

	/* UART0 for DEBUG Initialisation */
	USART0_init(57600);
#endif

	sei();

	/*	Binary Sensors Initialisation	*/
	// BinarySensor_Add(_pin_, 1);
	// BinarySensor_Add(_pin_, 2);
	// BinarySensor_Add(_pin_, 3);
	// BinarySensor_Add(_pin_, 4);
	// BinarySensor_Add(_pin_, 5);

	/* Brushless EDF Initialisation on pin */
	Brushless_Init(&Pin_B5);

	/* CANbus Initialisation */
	CANbus_Init();


#ifdef DEBUG
	/* ALL Initialisations Passed and UART sends 'k' */
	USART0_transmit('k');
#endif

  while(1) {

		can_wrapper_send(0x00006C00, 1, 0xFF);

		if (can_check_message()) {
			can_t msg;

			if (can_get_message(&msg)) {

				Brushless_Update(&msg);

			}
		}
  }

  return 0;
}
