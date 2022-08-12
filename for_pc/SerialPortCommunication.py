import serial

SerialObj = serial.Serial('/dev/ttyACM0')

print(SerialObj)

SerialObj.close()
#