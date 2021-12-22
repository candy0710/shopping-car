#include <BluetoothSerial.h>
BluetoothSerial BT;
int num;
int flag=1;
byte b=1;
int sensor_pin = 12;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("candyTestEsp32");//請改名
  pinMode(sensor_pin, INPUT);
}

void loop() {

  num=analogRead(12);
  if(num<500){flag=1; }
  
  if(flag==1){
    num=analogRead(12);
      //Serial.println(b);
    if((num>=3000)&&(b==1))
    {
      Serial.println(b);
      BT.write(b);
      b=2;
      flag=0;
    }
    else if((num>=3000)&&(b==2))
    {
      Serial.println(b);
      BT.write(b);
      b=3;
      flag=0;
    }
    else if((num>=3000)&&(b==3))
    {
      Serial.println(b);
      BT.write(b);
      flag=0;
  }
  
    }
}
