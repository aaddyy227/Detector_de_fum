int led_rosu = 12;
int led_verde = 11;
int difuzor = 10;
int smokeA0 = A5;

int sensorThres = 400;

void setup() {
  pinMode(led_rosu, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(difuzor, OUTPUT);
  pinMode(smokeA0, INPUT);
  Serial.begin(9600);
}

void loop() {
  int analogSensor = analogRead(smokeA0);

  Serial.print("Pin A0: ");
  Serial.println(analogSensor);
  
  if (analogSensor > sensorThres)
  {
    digitalWrite(led_rosu, HIGH);
    digitalWrite(led_verde, LOW);
    tone(difuzor, 1000, 200);
  }
  else
  {
    digitalWrite(led_rosu, LOW);
    digitalWrite(led_verde, HIGH);
    noTone(difuzor);
  }
  delay(100);
}
