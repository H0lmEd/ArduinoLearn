int data = 2;
int clock = 3;
int latch = 4;

int ledState = 0;
const int ON = HIGH;
const int OFF = LOW;

void setup() {
    pinMode(data, OUTPUT);
    pinMode(clock, OUTPUT);
    pinMode(latch, OUTPUT);
}

void loop() {
    int delayTime = 100;
    for (int i=0; i<25; i++) {
        updateLEDs(3);
        delay(delayTime);
    }
}

void updateLEDs(int value) {
    digitalWrite(latch, LOW);
    shiftOut(data, clock, MSBFIRST, value);
    digitalWrite(latch, HIGH);
}

void updateLEDsLong(int value) {
    digitalWrite(latch, LOW);
    for(int i=0; i<8; i++) {
        int bit = value & B10000000;
        value = value << 1;
        if (bit == 128) {digitalWrite(data, HIGH);}
        else {digitalWrite(data, LOW);}
        digitalWrite(clock, HIGH);
        delay(1);
        digitalWrite(clock, LOW);
    }
    digitalWrite(latch, HIGH);
}
