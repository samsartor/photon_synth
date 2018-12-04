const int NOTE_COUNT = 4;
const float NOTES[NOTE_COUNT] = {261.63, 293.66, 329.63, 392.00};
const int BUTTONS[NOTE_COUNT] = {D0, D1, D2, D3};
const int AUDIO_OUTPUT = A4;

void setup() {
    for (int i=0; i < NOTE_COUNT; i++) {
        pinMode(BUTTONS[i], INPUT_PULLUP);
    }
    pinMode(AUDIO_OUTPUT, OUTPUT);
    pinMode(LED, OUTPUT);
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

    if (state != new_state) {
        state = new_state;
        if (state == -1) {
            analogWrite(AUDIO_OUTPUT, 0);
        } else {
            analogWrite(AUDIO_OUTPUT, 128, NOTES[state]);
        }
    }

    delay(10);
}
