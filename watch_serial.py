#!/usr/bin/env python
# encoding: utf-8
"""
watch_serial.py

Created by Brian Lalor on 2010-02-20.
Copyright (c) 2010 __MyCompanyName__. All rights reserved.
"""

import sys
import os
import serial
import datetime

def main():
    ser = serial.Serial(port = sys.argv[1], baudrate = int(sys.argv[2]), timeout = 0.25)
    
    # found_data = False
    # while True:
    #     b = ser.read(1)
    #     if b:
    #         found_data = True
    #         print '%.2X' % (ord(b),),
    #     else:
    #         if found_data:
    #             print ""
    #         
    #         found_data = False
    i = 0
    while True:
        c = ser.read()
        if c:
            sys.stdout.write(c)
            sys.stdout.flush()
        
        i += 1
        
        if i == 50:
            i = 0
            ser.write('\x55')
        
        # line =  ser.readline().strip()
        # if line:
        #     print '[%s] %s' % (datetime.datetime.now().isoformat(), line)
        #     
        #     sys.stdout.flush()
        
    


if __name__ == '__main__':
    main()

