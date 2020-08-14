int ldrPin = A0;
int ldrVal;
int ledPin = 9;
const int trigPin = 2;
const int echoPin = 3;
long duration; 
int distance;
int a = 0;
int val; 
int tempPin = A3;
int buzzerPin = 5;
int indicator = 6;
int LightPower;

void setup(){
    pinMode(ldrPin, INPUT);
    pinMode(ledPin, OUTPUT);
    Serial.begin(9600);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    pinMode(buzzerPin, OUTPUT);
    pinMode(indicator, OUTPUT);
}
void loop(){
    if (a == 2){
        a = 0;
    }
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration*0.034/2;
    
    Serial.print("Distance : ");
    Serial.println(distance);
    delay(500);
    
    if(distance <= 15){
        a+=1;
        delay(1500);
    }
    if(a == 1){
        ldrVal = analogRead(ldrPin);
        indicate();
        
        if(ldrVal >= 900){
            digitalWrite(ledPin, HIGH);
        } 
        else if(ldrVal <= 900 && ldrVal >= 850){
            analogWrite(ledPin, 90);
        }
        else if(ldrVal <= 850){
        digitalWrite(ledPin, LOW);
    }
        delay(500);
        Serial.println(ldrVal);
        
    }
    if(a == 2){
        digitalWrite(ledPin, LOW);
        indicateClose();
    }
}
void indicate(){
    digitalWrite(indicator, HIGH);
}
void indicateClose(){
    digitalWrite(indicator, LOW);
}
