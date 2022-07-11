#define rledPin 6//RGB引脚
#define gledPin  5
#define bledPin  3
#define irSensorPin 8//红外人体感应模块信号输出
#define lightSensorPin A0//光敏电阻分压电路信号输出

int ledR = 0;//led亮度
int ledG = 0;
int ledB = 0;

bool irReading;
int lightReading;
int ledColorIndex;


void setup() {
  // put your setup code here, to run once:
  pinMode(rledPin,OUTPUT);  //pinMode(6,OUTPUT);
  pinMode(gledPin,OUTPUT);
  pinMode(bledPin,OUTPUT);
  pinMode(irSensorPin,INPUT);

  Serial.begin(9600);
  Serial.println("hello:");
}

void loop() {
  // put your main code here, to run repeatedly:
  lightReading = analogRead(lightSensorPin);  //测试光敏电阻
  delay(500);
  irReading = digitalRead(irSensorPin);  //测试红外
  delay(500);
  rgbLedTest();                          //测试LED

  Serial.println("___");
  Serial.println("lightReading = ");Serial.println(lightReading);
  Serial.println("irReading");Serial.println(irReading);
  Serial.println("========");
  

}

void rgbLedTest()
{
  ledColorIndex++;
  switch (ledColorIndex)
    {
      case 1:
      redTest();
      break;

      case 2:
      blackTest();
      break;

      case 3:
      greenTest();
      break;
      
      case 4:
      blackTest();
      break;

      case 5:
      blueTest();
      break;
      
      case 6:
      blackTest();
      break;
      }
      if (ledColorIndex == 12) ledColorIndex = 0; //led测试循环
  }
void redTest(){  //测试红色LED
  digitalWrite(rledPin, HIGH);
  digitalWrite(gledPin, LOW);
  digitalWrite(bledPin, LOW);  
}
 
void greenTest(){  //测试绿色LED
  digitalWrite(rledPin, LOW);
  digitalWrite(gledPin, HIGH);
  digitalWrite(bledPin, LOW);  
}
 
void blueTest(){  //测试蓝色LED
  digitalWrite(rledPin, LOW);
  digitalWrite(gledPin, LOW);
  digitalWrite(bledPin, HIGH);  
}
 
void blackTest(){ //LED熄灭
  digitalWrite(rledPin, LOW);
  digitalWrite(gledPin, LOW);
  digitalWrite(bledPin, LOW);    
}
 
