#define HAS_SD

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello Lauren");
  delay(1000);
}

/*
 * Check sound levels
 * Store sound levels on SD card
 * if sound level average has been high for x hours/minutes
 * Print 'last x hours a lot of sound has been present, how is your concentration?'
 * if sound level average has been low for x hours/minutes
 * Print 'last x hours have been very quiet, how is your concentration?'
 * 
 * At x o clock each day/week
 * Sound levels this day/week have been comparatively high/low, Why was that? Has this impacted your workflow?
 */
