int firstSensor = 0;    // first analog sensor
int inByte = 0;         // incoming serial byte

void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  pinMode(2, INPUT_PULLUP);   // digital sensor is on digital pin 2
  pinMode(3, OUTPUT);

  establishContact();  // send a byte to establish contact until receiver responds
}

void loop() {
  // if we get a valid byte, read analog ins:
  if (Serial.available() > 0) {
    // get incoming byte:
    inByte = Serial.read();
    
//    if (digitalRead(2) == LOW){
//      digitalWrite(3,HIGH);
//  
//    } else {
//      // turn LED off:
//      digitalWrite(3, LOW);
//    }
    
    // read first analog input, divide by 4 to make the range 0-255:
    firstSensor = analogRead(A0) / 4;


    int firstSensor1= map(firstSensor, 0, 255, 0, 100);
    // send sensor values:
    Serial.print(firstSensor1);

    delay(500);
  }
}

void establishContact() {
  while (Serial.available() <= 0) {
    Serial.print('0');   // send a capital 0
    delay(300);
  }
}
