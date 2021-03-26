#include <LiquidCrystal.h>;

LiquidCrystal lcd(10,9,5,4,3,2);

const int trigPin2=13;  // defines the pin numbers
const int echoPin2=11;
  
long duration;          // defines variables
int distanceCm;
//////////////////////////////////////////////////////////////// 
#include <Servo.h>

const int trigPin = 7; // Trigger Pin of Ultrasonic Sensor
const int echoPin = 6; // Echo Pin of Ultrasonic Sensor
Servo Myservo;


void setup() 
{  
    Serial.begin(9600); // Starting Serial Terminal
    lcd.begin (16,2); // Initializes the interface to the LCD screen, and specifies the dimensions (width and height) of the display
    
    pinMode (trigPin2, OUTPUT);
    pinMode (echoPin2, INPUT);
    
    ///////////////////////////////////part2///////////////////////////////
    
    Myservo.attach(8);  // Signal Pin of Servo      
                                           
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    
    Serial.print(" Automated Sanitizer Dispenser.");
    delay(1000);
    Serial.print("Made By: Group1");
    delay(2000);

}

void loop()
{
    digitalWrite(13,LOW);  // Clears the trigPin
    delayMicroseconds(2);
    digitalWrite(13,HIGH); // Sets the trigPin on HIGH state for 10 micro seconds
    delayMicroseconds(10); // Sets the trigPin on HIGH state for 10 micro seconds
    digitalWrite(13,LOW);
  
    duration = pulseIn(11, HIGH);   //To receive the reflected signal.
  
    distanceCm= duration*0.0340/2;  // Calculating the distance
    //distanceInch = duration*0.0133/2;
    
    lcd.setCursor(0,0);      // Sets the location where text written to the LCD will be displayed
    lcd.print("Liquid Status"); // Prints string "Distance" on the LCD
    lcd.print(distanceCm);   // Prints the distance value from the sensor
    lcd.print("cm");
    delay(20);
    lcd.setCursor(0,1);

    if(distanceCm<=5){
      lcd.print("Low");
      }
    else if(distanceCm<=12){
    lcd.print("Medium");
    }
    else if(distanceCm>12){
    lcd.print("Full");
    }
    delay(20);
    
    ///////////////////////////////////part2///////////////////////////////
    long duration, cm;
    pinMode(trigPin, OUTPUT);
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
  
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);
    cm = microsecondsToCentimeters(duration);
    
  
    Serial.print("Distance:");
    Serial.print(cm);
    Serial.print("cm");
    delay(100);
      
    if(cm >= 20){
      Myservo.write(0);
    }
    else {
      Myservo.write(90);
    }
    
    Serial.println();
    delay(100);

}


long microsecondsToCentimeters(long microseconds)
{
   return microseconds / 29 / 2;
}
