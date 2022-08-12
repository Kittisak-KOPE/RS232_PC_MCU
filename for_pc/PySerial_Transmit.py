import serial
import time

SerialObj = serial.Serial('/dev/ttyACM0')
time.sleep(3)

BytesWritten = SerialObj.write(b'A')
print('ByersWritten = ', BytesWritten)

SerialObj.close()
#