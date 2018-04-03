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

	/* CANbus Initialisation */
	CANbus_Init();


	//Init_Pumps();

	//Init_Vacuume_Switches();
	/* Brushless EDF Initialisation on pin */
	//Brushless_Init(&Pin_B5);


#ifdef DEBUG
	/* ALL Initialisations Passed and UART sends 'k' */
	USART0_transmit('k');
#endif

  while(1) {



		if (can_check_message()) {
			can_t msg;

			if (can_get_message(&msg)) {

				//SingleVacuumPump_OnMessage(&msg);

			}
		}
  }

  return 0;
}
