const float NOTES[4] = {261.63, 293.66, 329.63, 392.00};
const int BUTTONS[4] = {D0, D1, D2, D3};
const int LED = D7;

void setup() {
  pinMode(D0), INPUT_PULLUP);
  pinMode(LED, OUTPUT);
}

void loop() {
    int period = 1e6 / 440.0;
    float cycle = (micros() % period) / (float) period;
    float theta = cycle * TWO_PI;
    int out = sin(theta) * 2048 + 2047;

    if (digitalRead(D0)) == LOW) {
        analogWrite(DAC1, out);
    }
}
