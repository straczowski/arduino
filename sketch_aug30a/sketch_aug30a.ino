const int speakerPin = 9;
const int frequency = 880;
const int duration = 50;

unsigned int MS_per_beat = 0;

void setup() {
  // put your setup code here, to run once:
  unsigned int milliseconds_per_minute = 60000;
  unsigned int beats_per_minute = 60;
  MS_per_beat = milliseconds_per_minute / beats_per_minute;
}

void loop() {
  // put your main code here, to run repeatedly:
  tone(speakerPin, frequency, duration);
  delay(MS_per_beat);
}
