#define DEBUG true

#define PHOTO_SENSORS 1  // the number of servos, up to 48 for Mega, 12 for other boards
#define FIRST_SENSOR_PIN 22

int photo_sensor_states[PHOTO_SENSORS];
int old_photo_sensor_states[PHOTO_SENSORS];

void setup() {
  if (DEBUG) {
    Serial.begin(57600);
    Serial.println(LOW);
    Serial.println(HIGH);
  }
  
  // put your setup code here, to run once:
  for(int i = 0; i < PHOTO_SENSORS * 2; i = i + 2) {
    if (DEBUG) {
      Serial.print("Photo-Sensor-Pin: ");
      Serial.println(FIRST_SENSOR_PIN + i);
      
      Serial.print("Photo-Sensor-LED-Pin: ");
      Serial.println(FIRST_SENSOR_PIN + i + 1);
    }
    
    photo_sensor_states[i] = LOW;
    old_photo_sensor_states[i] = LOW;
    pinMode(FIRST_SENSOR_PIN + i, INPUT);
    pinMode(FIRST_SENSOR_PIN + i + 1, OUTPUT);
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < PHOTO_SENSORS * 2; i = i + 2) {
    old_photo_sensor_states[i] = photo_sensor_states[i];
    photo_sensor_states[i] = digitalRead(FIRST_SENSOR_PIN + i);
    if (photo_sensor_states[i] == LOW) {
      digitalWrite(FIRST_SENSOR_PIN + i + 1, HIGH);
    } else {
      digitalWrite(FIRST_SENSOR_PIN + i + 1, LOW);
    }
    if (DEBUG && old_photo_sensor_states[i] != photo_sensor_states[i]) {
      Serial.print("Photo-Sensor-Pin ");
      Serial.print(FIRST_SENSOR_PIN + i);
      Serial.print(" - Signal: ");
      Serial.println(photo_sensor_states[i]);
      old_photo_sensor_states[i] = photo_sensor_states[i];
    }
  }
}
