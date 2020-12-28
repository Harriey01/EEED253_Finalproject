#define sw 5
#define echo 6
#define trig 7
#define buzz 8

int sound = 0;
int Resistance = 0;
int Switch = 0;
void setup()
{
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(buzz,OUTPUT);
  pinMode(sw,INPUT);
}

void loop()
{
  
  long durationindigit, distance;
  digitalWrite(trig, LOW); 
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);
  durationindigit = pulseIn(echo, HIGH);
  distance = (durationindigit/5) / 29;
  Resistance=analogRead(A0);
  Switch=digitalRead(sw);

  
  if(Resistance >= 600 || Switch == HIGH){
    Serial.print(distance);
 	Serial.println(" cm");
    
    if (distance < 70) {
      sound = 100;
    }
  	if (distance < 30) {
      sound = 300;
    }
 	if (distance < 15) {
      sound = 500;
    }
    if (distance > 70 || distance <= 0){
      noTone(buzz);
  	}
	else {
      tone(buzz, sound);
	}
  }
    
  else{
    noTone(buzz);
  }

}
