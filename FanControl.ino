#define ENABLE 5 //this is the control pin
#define DIRA 3
#define DIRB 4   //those two are the spin direction pin

int i;
 
void setup() {
  //---set pin direction
  pinMode(ENABLE,OUTPUT);
  pinMode(DIRA,OUTPUT);
  pinMode(DIRB,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Start The Motors!");
  //---PWM example, full speed then slow

  for (i=255;i>100;i--) {
  digitalWrite(DIRA,HIGH); //one way
  digitalWrite(DIRB,LOW);
  analogWrite(ENABLE,i); //enable on
  delay(200);
  }
  for (i=100;i<255;i++) {
  digitalWrite(DIRA,HIGH); //one way
  digitalWrite(DIRB,LOW);
  analogWrite(ENABLE,i); //enable on
  delay(200);  
  }
