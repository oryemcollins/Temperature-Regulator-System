GULU UNIVERSITY
P.O BOX 166, GULU




Course: Bachelor of Information and Communication Technology
Name: ORYEM COLLIN
REG No: 23/U/2345/GIW/PS
Project Name: Temperature_Regulator_System






 
How the System Works
1.	Initialization:
o	When the system starts, it initializes the DHT sensor and the relay pin.
o	It ensures that the fan is off at the start.
2.	Continuous Operation:
o	The system enters a loop where it continuously reads the temperature from the DHT sensor.
o	If the temperature reading is valid, it prints the temperature to the Serial Monitor.
o	Based on the temperature, it decides whether to turn the fan on or off: 
	If the temperature is 30°C or higher, it turns on the fan.
	If the temperature is 25°C or lower, it turns off the fan.
o	It prints the status of the fan to the Serial Monitor.
o	The system waits for 5 seconds before repeating the process
This how I can illustrate how the code will run
#include <DFRobot_DHT11.h> // Define DHT sensor type and pin
#define DHTPIN 33 // Initialize DHT sensor
DFRobot_DHT11 dht(DHTPIN); // Define relay pin
#define RELAY_PIN 32 // Define temperature thresholds
const float TEMP_THRESHOLD_ON = 30.0;  // Turn on the fan (in Celsius)
const float TEMP_THRESHOLD_OFF = 25.0; // Turn off the fan (in Celsius)

void setup() {
  // Start serial communication for debugging
  Serial.begin(9600);
   // Initialize DHT sensor
  dht.begin();  // Initialize relay pin
  pinMode(RELAY_PIN, OUTPUT);  // Ensure the fan is off at the start
  digitalWrite(RELAY_PIN, LOW);
}
void loop() {
  // This is repeated process for temperature from DHT sensor
  float temperature = dht.readTemperature();   // Check if reading was successful
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

