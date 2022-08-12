# RS232_PC_MCU

Step

#1 How To Install python3-serial on Ubuntu 22.04 (Using apt-get)

```
sudo apt-get update
sudo apt-get -y install python3-serial
```

#2 Opening the Serial Port using PySerial and Python
How can you know port for connect Arduino Uno

```
  dmesg | tail
```

\*\*When happen the problem :

```
  sudo usermod -a -G tty rahul
  sudo usermod -a -G dialout rahul
  groups rahul
```

Follow : SerialPortCommunication.py

```
import serial

SerialObj = serial.Serial('/dev/ttyACM0')

print(SerialObj)

SerialObj.close()
```

Result from therminal : Serial<id=0x7fc97a027640, open=True>(port='/dev/ttyACM0', baudrate=9600, bytesize=8, parity='N', stopbits=1, timeout=None, xonxoff=False, rtscts=False, dsrdtr=False)

# PC to Arduino data transmission using Python (PySerial) Serial Port (Python serial Port Transmission)

Step 1 --> Follow : Serial_Reception_LED.ino

```
void setup() {
pinMode(13, OUTPUT);
digitalWrite(13, LOW);
Serial.begin(9600);
}

void loop() {

    char RxedByte = 0;
    if(Serial.available()){

      RxedByte = Serial.read();

      if(RxedByte == 'A' && RxedByte != 'B'){
        digitalWrite(13, HIGH);
      }

      if(RxedByte == 'B'){
        digitalWrite(13, LOW);
      }
    }

}
```

Step 2 --> Follow : Pyserial_Transmit.py

```
  import serial
  import time

  SerialObj = serial.Serial('/dev/ttyACM0')
  time.sleep(3)

  BytesWritten = SerialObj.write(b'A')
  print('ByersWritten = ', BytesWritten)
  SerialObj.close()
```

# How to receive data from Arduino to your PC using Python (Python serial Port Reception)

Step 1 --> Follow : Serial_SendString.ino

```
  void setup() {
    Serial.begin(9600);
  }

  void loop() {
    char TextToSend[] = "Hello! This is massage from Arduino Uno";
    Serial.println(TextToSend);
    delay(1000);
  }
```

Step 2 -->Follow : PySerial_ReceiveString.py

```
  import serial
  import time

  SerialObj = serial.Serial('/dev/ttyACM0')
  SerialObj.timeout = 3
  time.sleep(3)

  ReceivedString = SerialObj.readline()

  print(ReceivedString)

  SerialObj.close()
```

# Python Serial Transmit and Receive Echo Program using Pyserial

Step 1 --> Follow : Serial_Echo_Back.ino

```
  void setup() {
    pinMode(13, OUTPUT);
    digitalWrite(13, LOW);
    Serial.begin(9600);
  }

  void loop() {
  char RxedByte = 0;
  if(Serial.available()){
        RxedByte = Serial.read();
        Serial.print(RxedByte);
      }
  }
```

Step 2 --> Follow : PySerial_Transmit_Echo.py

```
  import serial
  import time

  SerialObj = serial.Serial('/dev/ttyACM0')
  time.sleep(3)

  BytesWritten = SerialObj.write(b'A')
  EchoedVar = SerialObj.read()

  print('ByersWritten = ', BytesWritten)
  print('EchoedVar = ', EchoedVar)

  SerialObj.close()
```
