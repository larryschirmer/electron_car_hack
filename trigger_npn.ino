//Global Variables
int npn = D7;

//Setup
void setup() {
  pinMode(npn,OUTPUT);
  Serial.begin(9600);
  Particle.function("trigger",trigger);
}

//Loop
void loop() {

}

int trigger(String button) {
  Serial.println("stateChange has run");

  if (button == "unlock") {
    Serial.println("Button Press: unlock");
    shortBlink(npn);
    shortBlink(npn);
    longBlink(npn);
    return 1;
  }
  if (button == "lock") {
    Serial.println("Button Press: lock");
    shortBlink(npn);
    midBlink(npn);
    shortBlink(npn);
    longBlink(npn);
    return 1;
  }
  if (button == "start_car") {
    Serial.println("Button Press: start car");
    shortBlink(npn);
    shortBlink(npn);
    shortBlink(npn);
    shortBlink(npn);
    varBlink(npn,4000,0);
    return 1;
  }
}

//Quarter Second
//Turns a pin on for 1/8 second and blocks for a 1/8 second
int shortBlink(int pin) {
  digitalWrite(pin,HIGH);
  delay(125);
  digitalWrite(pin,LOW);
  delay(125);
}

//Half Second
//Turns a pin on for 1/4 second and blocks for a 1/4 second
int midBlink(int pin) {
  digitalWrite(pin,HIGH);
  delay(250);
  digitalWrite(pin,LOW);
  delay(250);
}

//Full Second
//Turns a pin on for 1/2 second and blocks for a 1/2 second
int longBlink(int pin) {
  digitalWrite(pin,HIGH);
  delay(500);
  digitalWrite(pin,LOW);
  delay(500);
}

//Variable Second
//Turns a pin on and off for a set amount of seconds
int varBlink(int pin,int onTime,int offTime) {
  digitalWrite(pin,HIGH);
  delay(onTime);
  digitalWrite(pin,LOW);
  delay(offTime);
}
