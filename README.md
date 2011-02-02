> This code originated from [Martin Thomas' AVR-Projects page][Martin_THOMAS].
> It's licensed under a BSD-style license. My intent is to extend this code for
> my own projects and possibly provide an Arduino port.

[Timer-based AVR Software-UARTS][Martin_THOMAS]
==============================

Some AVRs do not have a hardware-UART others have one or two. In case a UART
is needed on "non-UART" AVRs or the available hardware-UARTS are not enough to
fullfill the project-needs a software-UART can be used. The software-UART
available here is based on the "gerneric software uart" by Colin Gittins which
can be downloaded from the iar.com website in the application-notes section. I
have ported/adapted this code to AVRs using avr-gcc/avr-libc and fixed some
smaller mistakes. This code does not need an external interrupt-pin for the
RX-line - any input-pin will do. But the RX pin gets sampled three times the
baudrate so more process-time is needed compared to an "external-int" approach
as presented in various Atmel Application-Notes.

Get the latest version of this "softuart-library" including a demo-application
[here][20101010] (timestamp 20101010).

Version History:

* 20070319: fixed handling of start- and stopbit in receiver-section, 
    code-cleanup, extended example-applciation
* [20070430][20070430]: added more configuation options for easier adaption to
    other AVRs, this time tested with an ATtiny85
* [20101010][20101010]: different minor modifications, included settings for
    ATmega164(P|PV|PA), ATmega324, ATmega644

Copyright (c) 2003, Colin Gittins  
Copyright (c) 2005, 2007, 2010, Martin Thomas  
All rights reserved.

[Martin_THOMAS]: http://www.siwawi.arubi.uni-kl.de/avr_projects/#softuart
[20070430]: http://www.siwawi.arubi.uni-kl.de/avr_projects/softuart_gittins_avr_20070430.zip
[20101010]: http://www.siwawi.arubi.uni-kl.de/avr_projects/softuart_gittins_avr_20101010.zip
