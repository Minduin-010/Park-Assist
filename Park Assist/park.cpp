const int triggerPin1 = 2;  
const int echoPin1 = 3;     
const int greenLED = 8;     
const int redLED = 9;       
const int buzzer = 6;       
const int yellowLED = 7;    

void setup() {
  Serial.begin(9600);         
  pinMode(triggerPin1, OUTPUT); 
  pinMode(echoPin1, INPUT);     
  pinMode(greenLED, OUTPUT);    
  pinMode(redLED, OUTPUT);      
  pinMode(buzzer, OUTPUT);      
  pinMode(yellowLED, OUTPUT);   
}

void loop() {
  long duration, distance;

  digitalWrite(triggerPin1, LOW);    
  delayMicroseconds(2);              
  digitalWrite(triggerPin1, HIGH);   
  delayMicroseconds(10);             
  digitalWrite(triggerPin1, LOW);    

  duration = pulseIn(echoPin1, HIGH); 
  distance = (duration * 0.034 / 2);  

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance < 30) { 
    digitalWrite(redLED, HIGH);    
    digitalWrite(greenLED, LOW);   
    digitalWrite(yellowLED, LOW);  
    digitalWrite(buzzer, HIGH);    
  }
  else if (distance >= 30 && distance < 80) { 
    digitalWrite(yellowLED, HIGH);  
    digitalWrite(greenLED, LOW);    
    digitalWrite(redLED, LOW);      
    digitalWrite(buzzer, LOW);      
  }
  else { 
    digitalWrite(greenLED, HIGH);   
    digitalWrite(redLED, LOW);      
    digitalWrite(yellowLED, LOW);   
    digitalWrite(buzzer, LOW);      
  }

  delay(500); 
}