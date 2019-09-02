const int speakerPin = 9;
const int frequency = 880;
const int duration = 50;

unsigned int beats_per_minute = 60;
unsigned int MS_per_beat = 0;

const int potPin = A0;
int potValue;

void setup() {
  // put your setup code here, to run once:
  unsigned int milliseconds_per_minute = 60000;
  MS_per_beat = milliseconds_per_minute / beats_per_minute;

  Serial.begin(9600);
}

void loop() {

  int value = analogRead(potPin);


  if (value != potValue) {
    beats_per_minute = map(value, 0, 1023, 30, 350);
    unsigned int milliseconds_per_minute = 60000;
    MS_per_beat = milliseconds_per_minute / beats_per_minute;

    potValue = value;
    formatPrint("", beats_per_minute, " | ", potValue, ".");
  }
  
  // put your main code here, to run repeatedly:
  tone(speakerPin, frequency, duration);
  delay(MS_per_beat);
}


void formatPrint(char const *leftStr, int msPerBeat, char const *sepStr, int potValue, char const *rightStr) {
     Serial.print (leftStr);
     Serial.print (msPerBeat);
     Serial.print (sepStr);
     Serial.print (potValue);
     Serial.println (rightStr);
}
