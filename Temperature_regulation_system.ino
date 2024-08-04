#include <DFRobot_DHT11.h>

// Define DHT sensor type and pin
#define DHTPIN 33

// Initialize DHT sensor
DFRobot_DHT11 dht(DHTPIN);

// Define relay pin
#define RELAY_PIN 32

// Define temperature thresholds
const float TEMP_THRESHOLD_ON = 30.0;  // Turn on the fan (in Celsius)
const float TEMP_THRESHOLD_OFF = 25.0; // Turn off the fan (in Celsius)

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);
  
  // Initialize DHT sensor
  dht.begin();
  
  // Initialize relay pin
  pinMode(RELAY_PIN, OUTPUT);
  
  // Ensure the fan is off at the start
  digitalWrite(RELAY_PIN, LOW);
}

void loop() {
  // This is repeated process for temperature from DHT sensor
  float temperature = dht.readTemperature();
  
  // Check if reading was successful
  if (isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Temperature score is ");
  Serial.println(temperature);
  // Print the temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  
  // Control the relay based on temperature thresholds
  if (temperature >= TEMP_THRESHOLD_ON) {
    digitalWrite(RELAY_PIN, HIGH);  // Turn on the fan
    Serial.println("Fan ON");
  } else if (temperature <= TEMP_THRESHOLD_OFF) {
    digitalWrite(RELAY_PIN, LOW);   // Turn off the fan
    Serial.println("Fan OFF");
  }
  
  // Wait for 5 seconds before the next reading
  delay(5000);
}

