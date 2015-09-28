#include <Average.h>
Average<float> ave(10);


#define trigPin 7
#define echoPin 6
#define led 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9
#define led6 8
#define buzzer 3

int sound = 0;
int maxdist = 0;
int mindist = 0;
int interval = 0;

void setup() {
  Serial.begin (115200);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  
 
}

void loop() {
      int total = 0;
 long duration, distance;
    for(int i=0; i<10; i++){
       
      digitalWrite(trigPin, LOW); 
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      duration = pulseIn(echoPin, HIGH);
     
      total += duration;
      Serial.print("Their Avg: ");
      Serial.println(duration);
      delay(10);
    }
     ave.push(duration);
    int ourAvg = total / 10;
    Serial.println("Our Avg: " + ourAvg);
    
 
    
   distance = ave.mean();
 
  if (distance <= 800 && distance >= 770){
    sound = 523;
    tone(buzzer, sound);
  }
  if (distance <= 700 && distance >= 600){
    sound = 587;
    tone(buzzer, sound);
  }
  if (distance <= 580 && distance >= 540){
    sound = 659;
    tone(buzzer, sound);
  }
  if (distance <= 520 && distance >= 480){
    sound = 698;
    tone(buzzer, sound);
  }
  if (distance <= 400 && distance >= 320) {
    sound = 783;
    tone(buzzer, sound);
  }
  if (distance <= 300 && distance >= 250){
     sound = 880;
     tone(buzzer, sound);
  }
  if (distance <= 240 && distance >= 200) {
    sound = 987;
    tone(buzzer, sound);
  }
  if (distance <= 175 && distance >= 100)  {
    sound = 1046;
    tone(buzzer, sound);
  }
  
 
  if (distance > 800 || distance <= 100){
    Serial.println(distance);
    noTone(buzzer);
  }
  else {
    Serial.print(distance);
    Serial.print(" ");
    Serial.println(sound);

   
   
  }
  delay(50);
}
