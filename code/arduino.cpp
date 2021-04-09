void setup() {
    Serial.begin(115200)
    pinMode(18, OUTPUT);
}

int i = 0;

void loop() {
    Serial.print("state: ");
    Serial.println(i % 2);
    digitalWrite(18, i % 2);
    delay(1000);
    i++;
}