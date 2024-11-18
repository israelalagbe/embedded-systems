const int redLed = 6;
const int yellowLed = 5;
const int greenLed = 4;
const unsigned long int timeout = 3000; //  3 seconds(s)

void turnOnLed(int pin) {
  digitalWrite(redLed, LOW);
  digitalWrite(yellowLed, LOW);
  digitalWrite(greenLed, LOW);
  digitalWrite(pin, HIGH);
}

void setup()
{
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
}

void loop()
{
  turnOnLed(redLed);
  delay(timeout); 
  turnOnLed(yellowLed);
  delay(timeout);
  turnOnLed(greenLed);
  delay(timeout);
}