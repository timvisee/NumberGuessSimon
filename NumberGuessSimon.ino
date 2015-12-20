// Led pins
int led1 = 8;
int led2 = 9;
int led3 = 10;
int led4 = 11;
int led5 = 13;

// Button pin
int button = 4;

// States
int buttonState = LOW;
int lastButtonState = LOW;
int counter = 0;

int timerTimeout = 2000;
long timer = -1;

// Antwoord
int antwoord;

// Called on setup
void setup() {
    // Set up leds
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);

    // Set up the button
    pinMode(button, INPUT);

// willekeurig getal genereren adhv poort
    randomSeed(analogRead(1));
}

// Start the timer
void startTimer() {
    timer = millis() + timerTimeout;
}

// Check whether the timer is finished
bool isTimerFinished() {
    return millis() >= timer && timer >= 0;
}

// Stop the timer
void stopTimer() {
    timer = -1;
}

// Called on loop
void loop() {
    // Willekeurig nummer voor de game
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

    // Loop until the timer ends
    while (!isTimerFinished()) {
        // Update the current button state each loop
        buttonState = digitalRead(button);

        if (buttonState == HIGH && lastButtonState == LOW) {
            counter++;
            startTimer();
            lastButtonState = HIGH;

        } else if(buttonState == LOW && lastButtonState == HIGH) {
            lastButtonState = LOW;
            startTimer();
        }
    }

    // Stop the timer, since it's no longer needed
    stopTimer();

    // Led 13 aan
    if (counter >= antwoord) {
        digitalWrite(13, HIGH);
        digitalWrite(8, LOW);
        digitalWrite(9, LOW);
        digitalWrite(10, LOW);
        digitalWrite(11, LOW);
        delay(5000);
    }

// Alle leds uit
    digitalWrite(13, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);

// Even wachten
    delay(500);

    // Variabele resetten
    counter = 0;
}
