#include <math.h>

#define MOISTURE_PIN A0
#define TEMP_PIN A1

void setup() {
  Serial.begin(9600);
  while (!Serial) { ; }
}

float getTemperature() {
  int raw = analogRead(TEMP_PIN);
  float resistance = (float)(1023 - raw) * 10000 / raw;
  float temp = 1 / (log(resistance / 10000) / 3975 + 1 / 298.15) - 263.15;
  return temp;
}

void loop() {
  // Moisture
  int raw = analogRead(MOISTURE_PIN);
  int moisture_pct = map(raw, 1023, 300, 0, 100);
  moisture_pct = constrain(moisture_pct, 0, 100);
  
  String label;
  if (moisture_pct >= 70) label = "DRY";
  else if (moisture_pct >= 60) label = "moist";
  else if (moisture_pct >= 50) label = "Wet";
  else label = "Very Dry";

  // Temperature
  float temp = getTemperature();

  // Send JSON
  Serial.print("{\"moisture_raw\":");
  Serial.print(raw);
  Serial.print(",\"moisture_pct\":");
  Serial.print(moisture_pct);
  Serial.print(",\"moisture_label\":\"");
  Serial.print(label);
  Serial.print("\",\"temperature\":");
  Serial.print(temp, 1);
  Serial.println("}");

  delay(1000);
}