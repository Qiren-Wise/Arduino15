
  const int rledPin = 6;//引脚
const int gledPin = 5;
const int bledPin = 3;

int ledR = 0; //亮度
int ledG = 0;
int ledB = 0;


void setup() {
  // put your setup code here, to run once:
  pinMode(rledPin,OUTPUT); 
  pinMode(gledPin,OUTPUT); 
  pinMode(bledPin,OUTPUT); 
  Serial.begin(9600);
  Serial.println("nishihsui");
  Serial.println("nishihsui");

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()>0)
  {
    char serialCmdChar = Serial.read();
    serialCmd(serialCmdChar);
    }
    delay(50);
}

void serialCmd(char serialCmdChar)
{
  switch(serialCmdChar)
{
  case 'r':
  ledR = Serial.parseInt();
  break;

  case 'g':
  ledG = Serial.parseInt();
  break;

  case 'b':
  ledB = Serial.parseInt();
  break;

  case 'c':
  ledR = 0;
  ledB = 0;
  ledG = 0;
 
  }

analogWrite(rledPin,ledR);
delay(100);
analogWrite(gledPin,ledG);
delay(100);
analogWrite(bledPin,ledB);
delay(100);

Serial.print("Red Value:");
Serial.println(ledR);
Serial.print("Green Value:");
Serial.println(ledG);
Serial.print("Blue Value:");
Serial.println(ledB);
Serial.println("______");
  
  }
