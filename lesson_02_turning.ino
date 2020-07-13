// Lesson 02 Turning
// www.smarsfan.com/play/lessons/lesson_02_turning

// set Motor A to Arduino Pins
int motor_A = 12;
int motor_B = 13;

// set the Motor Speed using the Arduino Pins
int motor_A_speed = 10;
int motor_B_speed = 11;

// set the time between motor on and motor off
int wait_in_milliseconds = 1000;

// this code runs once at the start
void setup() {

  // this sets the speed of communication between the computer and Arduino,
  // used when uploading your code
  Serial.begin(9600);

  Serial.println("SMARS OS v1.0")
  // set the Arduino pin to OUTPUT mode
  pinMode(motor_A, OUTPUT);
  pinMode(motor_B, OUTPUT);
}

// move forward
void forward() {

  // set the direction to forward
  digitalWrite(motor_A, HIGH);
  digitalWrite(motor_B, LOW);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

// move backward
void backward() {

  // set the direction to backward
  digitalWrite(motor_A, LOW);
  digitalWrite(motor_B, HIGH);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

// turn left
void turnLeft() {

  // set the direction to backward
  digitalWrite(motor_A, HIGH);
  digitalWrite(motor_B, HIGH);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

// turn right
void turnRight() {

  // set the direction to backward
  digitalWrite(motor_A, LOW);
  digitalWrite(motor_B, LOW);

  // set to full speed
  analogWrite(motor_A_speed, 255);
  analogWrite(motor_B_speed, 255);

  // wait
  delay(wait_in_milliseconds);

  // stop
  analogWrite(motor_A_speed, 0);
  analogWrite(motor_B_speed, 0);
}

// the main program loop
void loop(){

  while (Serial.available()) {
    char c = Serial.read();
    switch(c) {
    // press the 'w' key to move SMARS Forward
    case 'w':
    Serial.println("Moving Forward");
    forward();
    break;

    // press the 's' key to move SMARS backward
    case 's':
    Serial.println("Moving Backward");
    backward();
    break;

    // press the 'a' key to move SMARS left
    case 'a':
    Serial.println("Turning Left");
    turnLeft();
    break;

    // press the 'd' key to move SMARS right
    case 'd':
    Serial.println("Turning Right");
    turnRight();
    break;
    }
  }
  // wait 2 seconds
  delay(2000);
}
