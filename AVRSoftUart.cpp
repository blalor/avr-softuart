#include "AVRSoftUart.h"
#include "softuart.h"

int AVRSoftUart::read() {
    return softuart_getchar();
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
