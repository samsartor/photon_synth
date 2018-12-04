#include "Arduino.h"

void setup() {
  pinMode(9, OUTPUT);
  pinMode(6, INPUT);
}

void loop() {
    float freq = 523.25 + analogRead(1) * 0.511485826;

    // 2272 is 1/440th of a second, in microseconds
    long period = 1e6 / (freq * 0.5);

    // cycle is current time in peroid
    long cycle = micros() % period;
    int out;
    if (cycle > (period / 2)) {
        // over halfway
        out = HIGH;
    } else {
        out = LOW;
    }

    if (digitalRead(6) == HIGH) {
        digitalWrite(9, out);
    }
}
