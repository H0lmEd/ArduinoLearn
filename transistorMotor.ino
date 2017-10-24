int motorPin = 9;

void setup() {
    pinMode(motorPin, OUTPUT);
}

void loop() {
    motorOnThenOff();
}

void motorOnThenOff(){
    int onTime = 2500;
    int offTime = 1000;

    digitalWrite(motorPin, HIGH);
    delay(onTime);
    digitalWrite(motorPin, LOW);
    delay(offTime);
}


