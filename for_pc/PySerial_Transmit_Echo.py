import serial
import time

SerialObj = serial.Serial('/dev/ttyACM0')
time.sleep(3)

BytesWritten = SerialObj.write(b'A')
EchoedVar    = SerialObj.read()

print('ByersWritten = ', BytesWritten)
print('EchoedVar    = ', EchoedVar)

SerialObj.close()

#