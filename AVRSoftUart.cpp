#include "AVRSoftUart.h"
#include "softuart.h"

void AVRSoftUart::init() {
    softuart_init();
    softuart_turn_rx_on(); /* redundant - on by default */
}

int AVRSoftUart::read() {
    int rc = -1;
    
    if (softuart_kbhit()) {
        rc = (int) softuart_getchar();
    }
    
    return rc;
}

void AVRSoftUart::write(const uint8_t ch) {
    softuart_putchar((char) ch);
}

unsigned int AVRSoftUart::available() {
    return softuart_available();
}

int AVRSoftUart::peek() {
    return softuart_peek();
}

void AVRSoftUart::flush() {
    softuart_flush_input_buffer();
}
