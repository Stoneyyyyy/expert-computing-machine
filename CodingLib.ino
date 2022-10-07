// These are OUTPUT pins. Constants won't change. They're used to give names to the pins used:
const int 8-SegmentLedPin = ;      
// Digital output pin that the TASK indicator LEDs is attached to
const int pumpPin = ;        
const int fanPin = ;
const int lightingPin = ;
// Digital output pin that the TASK related Functions is attached to
const int emojiPin = ;                                          
// Digital output pin that FEEDBACK emoji is attached to
const int leftEyePin = ;
const int rightEyePin = ;
// Digital output pins that FEEDBACK eyes are attached to

// These are INPUT pins. Constants won't change. They're used to give names to the pins used:
const int waterLevelPin = ;     
// Analoge pin water level sensor is connected to
const int moistureSensorPin = ;    
// Digital input pin used to check the moisture level of the soil
const int temperatureSensorPin = ;
// Analoge pin used to check the temperature of the surroundings 




// These are the values to be edited for testing

double checkMoistureSensorInterval = ;
//time to wait before checking the soil moisture level - default it to an hour = 1800000
int waterLevelThreshold = ;                                   
// threshold at which we flash the LED to warn you of a low water level in the pump tank - set this as per the video explains
int timeToWait = ;    
// how long the LED will flash to tell us the water tank needs topping up - default it to 900 = 30mins
int timeToPump = ;      // how long the pump should pump water
int timeToFan = 900;          // how long the fan should work


// Global temp values

int sensorWaterLevelValue = 0;        // somewhere to store the value read from the waterlevel sensor
int moistureSensorValue = 0;          //somewhere to store the value read from the soil moisture sensor
  
void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);  
    pinMode(8-SegmentLedPin, OUTPUT);
    pinMode(pumpPin, OUTPUT);
    pinMode(fanPin, OUTPUT);
    pinMode(lightingPin, OUTPUT);
    pinMode(emojiPin, OUTPUT);
    pinMode(leftEyePin, OUTPUT);
    pinMode(rightEyePin, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
   
    pinMode(moistureSensorPin, INPUT);
    pinMode(waterLevelPin, INPUT);
    pinMode(temperatureSensorPin, INPUT);
                                                                  //flash the LED five times to confirm power on and operation of code:
     for (int i=0; i <= 4; i++){
        digitalWrite(LED_BUILTIN, HIGH);
        delay(300);
        digitalWrite(LED_BUILTIN, LOW);
        delay(300);
      }
      delay(2000);

    digitalWrite(ledPin, HIGH);                                   // turn the LED on 
}

void loop() {
  // put your main code here, to run repeatedly:
  
  sensorWaterLevelValue = analogRead(waterLevelPin);              //read the value of the water level sensor
  Serial.print("Water level sensor value: ");                     //print it to the serial monitor
  Serial.println(sensorWaterLevelValue);

  if (sensorWaterLevelValue < waterLevelThreshold){               //check if we need to alert you to a low water level in the tank
      for (int i=0; i <= emptyReservoirTimer; i++){  
        digitalWrite(ledPin, LOW);
        delay(1000);
        digitalWrite(ledPin, HIGH);
        delay(1000);
      }
  }
  else {
    digitalWrite(ledPin, HIGH);
    delay(checkInterval);                                         //wait before checking the soil moisture level
  }


// check soil moisture level

      moistureSensorValue = digitalRead(moistureSensorPin);       //read the moisture sensor and save the value
      Serial.print("Soil moisture sensor is currently: ");
      Serial.print(moistureSensorValue);
      Serial.println(" ('1' means soil is too dry and '0' means the soil is moist enough.)");

      if (moistureSensorValue == 1){
                                                                 //pulse the pump 
        digitalWrite(pumpPin, HIGH);
          Serial.println("pump on");
        delay(amountToPump);                                      //keep pumping water
        digitalWrite(pumpPin, LOW);
         Serial.println("pump off");
        delay(800);                                              //delay to allow the moisture in the soil to spread through to the sensor
      }



}
