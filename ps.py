#!/usr/bin/python
import socket
#import struct
#import binascii


s = socket.socket(socket.AF_INET, socket.SOCK_RAW, socket.htons(0x0800))
#s.bind(("192.168.20.19", 80))
while True:
    packet = s.recv(2048)
