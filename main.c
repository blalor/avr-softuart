/* 
	AVR Software-Uart Demo-Application 
	Version 0.3, 4/2007
	
	by Martin Thomas, Kaiserslautern, Germany
	<eversmith@heizung-thomas.de>
	http://www.siwawi.arubi.uni-kl.de/avr_projects
*/

/* 
Test environment/settings: 
- avr-gcc 4.1.1/avr-libc 1.4.5 (WinAVR 1/2007)
- Atmel ATtiny85 @ 1MHz internal R/C
- 2400bps

AVR Memory Usage (-Os)
----------------
Device: attiny85

Program:     874 bytes (10.7% Full)
(.text + .data + .bootloader)

Data:         52 bytes (10.2% Full)
(.data + .bss + .noinit)

*/

// #define WITH_STDIO_DEMO

#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include "softuart.h"


#ifdef WITH_STDIO_DEMO
#include <stdio.h>

// interface between avr-libc stdio and the modified Fleury uart-lib:
static int my_stdio_putchar( char c, FILE *stream )
{
	if ( c == '\n' ) {
		softuart_putchar( '\r' );
	}
	softuart_putchar( c );

	return 0;
}

FILE suart_stream = FDEV_SETUP_STREAM( my_stdio_putchar, NULL, _FDEV_SETUP_WRITE );

static void stdio_demo_func( void ) 
{
	stdout = &suart_stream;
	printf( "This output done with printf\n" );
	printf_P( PSTR("This output done with printf_P\n") );
}
#endif /* WITH_STDIO_DEMO */


int main(void)
{
	char c;
	static const char pstring[] PROGMEM = 
		"adapted for Atmel AVR and this demo by Martin Thomas\r\n";
	unsigned short cnt = 0;
#if (F_CPU > 4000000UL)
#define CNTHALLO (unsigned int)(0xFFFF)
#else 
#define CNTHALLO (unsigned int)(0xFFFF/3)
#endif

	softuart_init();
	softuart_turn_rx_on(); /* redundant - on by default */
	
	sei();
	
	softuart_puts_P( "\r\nSoftuart Demo-Application\r\n" );    // "implicit" PSTR
	softuart_puts_p( PSTR("generic softuart driver code by Colin Gittins\r\n") ); // explicit PSTR
	softuart_puts_p( pstring ); // pstring defined with PROGMEM
	softuart_puts( "--\r\n" );  // string "from RAM"

#ifdef WITH_STDIO_DEMO
	stdio_demo_func();
#endif
	
	for (;;) {
	
		if ( softuart_kbhit() ) {
			c = softuart_getchar();
			softuart_putchar( '[' );
			softuart_putchar( c );
			softuart_putchar( ']' );
		}

		cnt++;
		if (cnt == CNTHALLO) {
			cnt = 0;
			softuart_puts_P( " Hello " );
		}
		
	}
	
	return 0; /* never reached */
}
