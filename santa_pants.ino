/*

Santa: Naughty or Nice
 
 */

int sensorPin = A0;
int ledOne = 7;
int ledTwo = 8;
int sensorValue = 0;
int sensorTriggerLevel = 250;

void setup() {
  // declare the ledPin as an OUTPUT:
  pinMode(ledOne, OUTPUT);
  pinMode(ledTwo, OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  digitalWrite(ledOne, LOW); 
  digitalWrite(ledTwo, LOW);
  
  if(isTriggered())
  {
    Serial.println("Pressure sensor triggered");      
    for(int i=500; i>0; i-=100)
    {
      digitalWrite(ledOne, HIGH);
      digitalWrite(ledTwo, LOW);
      delay(i);
      digitalWrite(ledTwo, HIGH);
      digitalWrite(ledOne, LOW);
      delay(i);
      if(!isTriggered()) return;
    }
    makeDecision();
    while(isTriggered())
    {
      delay(400);
    }
  }
}

boolean isTriggered()
{
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  Serial.println(sensorValue);
  return sensorValue>sensorTriggerLevel;
}

void makeDecision()
{
  randomSeed(analogRead(1));
  int naughty = random(2);
  
  if(naughty)
  {
    digitalWrite(ledOne, HIGH);
    digitalWrite(ledTwo, LOW);
  }
  else
  {
    digitalWrite(ledTwo, HIGH);
    digitalWrite(ledOne, LOW);
  }
}
