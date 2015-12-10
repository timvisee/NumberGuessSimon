int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int led5 = 13;

int button = 4;
int buttonState = LOW;
int lastButtonState = LOW;
int counter = 0;

int TIMER_TIMEOUT = 2000;
long timer = -2;

int antwoord;

void setup() {
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);

    pinMode(button, INPUT);

// willekeurig getal genereren adhv poort
    randomSeed(analogRead(1));
}

void startTimer() {
    timer = millis() + TIMER_TIMEOUT;
}

bool isTimerFinished() {
    return millis() >= timer && timer >= 0;
}

void stopTimer() {
    timer = -2;
}

void loop() {

    int willekeurig = random() % 15 + 1;
    antwoord = willekeurig;

// led 1 gaat aan als het getal hoger/gelijk is dan 8
    if (willekeurig >= 8) {
        digitalWrite(8, HIGH);
        willekeurig -= 8;
    }
// led 2 gaat aan als het getal hoger/gelijk is dan 4
    if (willekeurig >= 4) {
        digitalWrite(9, HIGH);
        willekeurig -= 4;
    }
// led 3 gaat aan als het getal hoger/gelijk is dan 2 
    if (willekeurig >= 2) {
        digitalWrite(10, HIGH);
        willekeurig -= 2;
    }
// led 4 gaat aan als het getal gelijk is aan 1
    if (willekeurig == 1) {
        digitalWrite(11, HIGH);
        willekeurig -= 1;
    }

    // Start the timer
    startTimer();

    // Loop until the timer endsd
    while (!isTimerFinished()) {
        // Update the current button state each loop
        buttonState = digitalRead(button);

        if (buttonState != lastButtonState) {
            counter++;
            startTimer();
        }
        lastButtonState = buttonState;
    }


    if (counter >= antwoord) {
        digitalWrite(13, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        delay(5000);
    }


    digitalWrite(13, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);

    delay(500);

    counter = 0;
    stopTimer();
}
