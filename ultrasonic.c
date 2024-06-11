// Define the pins for the ultrasonic sensor and the LED
const int trigPin = 4;
const int echoPin = 5;
const int ledPin = 2;

// Variables to store the distance measurement
long duration;
int distance;

void setup() {
  // Initialize the serial communication
  Serial.begin(9600);

  // Set the pins as inputs and outputs
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // Clear the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the echo pulse
  duration = pulseIn(echoPin, HIGH);

  // Calculate the distance in centimeters
  distance = duration * 0.034 / 2;

  // Print the distance to the serial monitor
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if an obstacle is detected
  if (distance <= 20) {
    // Turn the LED on
    digitalWrite(ledPin, HIGH);
  } else {
    // Turn the LED off
    digitalWrite(ledPin, LOW);
  }

  // Wait for a short period before the next measurement
  delay(100);
}