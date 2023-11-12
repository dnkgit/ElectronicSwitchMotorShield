int directionPin = 12;
int pwmPin = 3;
int brakePin = 9;
uint32_t nextTime_ms_u32;
#define INTERVAL_MS   (3000)

void setup()
{
  pinMode(directionPin, OUTPUT);
  pinMode(pwmPin, OUTPUT);
  pinMode(brakePin, OUTPUT);
  Serial.begin(115200);
  while(!Serial)
  {
  }
  Serial.println("Start");
  Serial.println("PWM : 0");
  digitalWrite(brakePin, HIGH);
  analogWrite(pwmPin, 0);
  nextTime_ms_u32 = millis() + (INTERVAL_MS * 2);
}

void loop()
{
  static bool FlipFlop_bool = false;
  uint32_t nowTime_ms_u32 = millis();
  if(nowTime_ms_u32 >= nextTime_ms_u32)
  {
    nextTime_ms_u32 = nowTime_ms_u32 + INTERVAL_MS;

    if(!FlipFlop_bool)
    {
      Serial.println("PWM : 100");
      //digitalWrite(brakePin, LOW);
      analogWrite(pwmPin, 100);
    }
    else
    {
      Serial.println("PWM : 0");
      //digitalWrite(brakePin, HIGH);
      analogWrite(pwmPin, 0);
    }
    FlipFlop_bool = !FlipFlop_bool;
  }
}
