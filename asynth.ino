const float NOTES[4] = {261.63, 293.66, 329.63, 392.00};
const int BUTTONS[4] = {D0, D1, D2, D3};
const int LED = D7;

void setup() {
  pinMode(D0), INPUT_PULLUP);
  pinMode(LED, OUTPUT);
  pinMode(A4, OUTPUT);
  pinMode(DAC1, OUTPUT);
  analogWrite(A4, 128, 1000);
}

void loop() {
//    int period = 1e6 / NOTES[0];
//    long cycle = micros() % period;
//    int out;
//    if (cycle > (period / 2)) {
//        out = 4095;
//    } else {
//        out = 0;
//    }
//
//    if (digitalRead(BUTTONS[0]) == LOW) {
//        analogWrite(A4, 128, 1000);
//    }
}
