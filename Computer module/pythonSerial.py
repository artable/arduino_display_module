import serial
import time
from random import randint

UNIT_PORT = "COM7"
UNIT_BAUDRATE = 9600

class DisplayUnit():
    """A single display module"""
    def __init__(self, unit_ID: int = None, unit_port: str = None, unit_baudrate: int = None):
        self.unit_ID = unit_ID
        self.hardware_ID = None
        self.ser = serial.Serial(UNIT_PORT, UNIT_BAUDRATE)



arduino = DisplayUnit(unit_ID = 0, unit_port= UNIT_PORT, unit_baudrate= UNIT_BAUDRATE)
while(True) :
    arduino.ser.write(randint(0,244).to_bytes(1, "little"))
    time.sleep(.5)