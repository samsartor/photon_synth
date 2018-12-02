#include "Arduino.h"

void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
    // 2272 is 1/440th of a second, in microseconds
    long period = 2272;

    // cycle is current time in peroid
    long cycle = micros() % period;
    int out;
    if (cycle > (period / 2)) {
        // over halfway
        out = 255;
    } else {
        out = 0;
    }

    analogWrite(9, out);
}
