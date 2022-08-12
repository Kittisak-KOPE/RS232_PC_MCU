import serial
import time

SerialObj = serial.Serial('/dev/ttyACM0')
SerialObj.timeout = 3
time.sleep(3)

ReceivedString = SerialObj.readline()

print(ReceivedString)

SerialObj.close()

#