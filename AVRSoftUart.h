#ifndef AVRSOFTUART_H
#define AVRSOFTUART_H

#include <Stream.h>

class AVRSoftUart : public Stream {
public:
    void init();
    
    void flush();
    int peek();
    unsigned int available();
    void write(const uint8_t ch);
    int read();
};

#endif
