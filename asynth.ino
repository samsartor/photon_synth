const int NOTE_COUNT = 4;
const float NOTES[NOTE_COUNT] = {261.63, 293.66, 329.63, 392.00};
const int BUTTONS[NOTE_COUNT] = {D0, D1, D2, D3};
const int AUDIO_OUTPUT = A4;
const int MOD_INTPUT = A0;

void setup() {
    for (int i=0; i < NOTE_COUNT; i++) {
        pinMode(BUTTONS[i], INPUT_PULLUP);
    }
    pinMode(AUDIO_OUTPUT, OUTPUT);
    pinMode(MOD_INTPUT, INPUT);
}

static int state = -1;

void loop() {
    int new_state = -1;
    for (int i=0; i < NOTE_COUNT; i++) {
        if (digitalRead(BUTTONS[i]) == LOW) {
            new_state = i;
            break;
        }
    }

    state = new_state;
    if (state == -1) {
        analogWrite(AUDIO_OUTPUT, 0);
    } else {
        float mult = analogRead(MOD_INTPUT) / 4096.0 + 1.0;
        float freq = NOTES[state] * mult;
        analogWrite(AUDIO_OUTPUT, 128, freq);
    }

    delay(100);
}
