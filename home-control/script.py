#Imports
import webiopi
import time

from webiopi.devices.serial import Serial

serial = Serial("/dev/ttyAMA0", 9600)
serial.writeByte(0x30)

# Enable debug output
webiopi.setDebug()

# Retrieve GPIO lib

# Called by WebIOPi at script loading
def setup():
    webiopi.debug("Script with macros - Setup")
    # Setup GPIOs

# Looped by WebIOPi
def loop():
    # Toggle LED each 5 seconds
  #  value = not GPIO.digitalRead(LED1)
  #  GPIO.digitalWrite(LED, value)
    webiopi.sleep(1)        

# Called by WebIOPi at server shutdown
def destroy():
    webiopi.debug("Script with macros - Destroy")
    
@webiopi.macro
def living_room_light_on():
	serial.writeByte(0x41)

@webiopi.macro
def living_room_light_off():
	serial.writeByte(0x42)

@webiopi.macro
def main_room_light_on():
	serial.writeByte(0x43)

@webiopi.macro
def main_room_light_off():
	serial.writeByte(0x44)

@webiopi.macro
def room1_light_on():
	serial.writeByte(0x45)

@webiopi.macro
def room1_light_off():
	serial.writeByte(0x46)

@webiopi.macro
def room2_light_on():
	serial.writeByte(0x47)

@webiopi.macro
def room2_light_off():
	serial.writeByte(0x48)

@webiopi.macro
def toilet_light_on():
	serial.writeByte(0x49)

@webiopi.macro
def toilet_light_off():
	serial.writeByte(0x4A)

@webiopi.macro
def fan_on():
	serial.writeByte(0x4B)

@webiopi.macro
def fan_off():
	serial.writeByte(0x4C)

@webiopi.macro
def curtain_up():
	serial.writeByte(0x4D)

@webiopi.macro
def curtain_down():
	serial.writeByte(0x4E)

	

