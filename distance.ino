int trigPinf = 11;    //Trig - green Jumper
int echoPinf = 12;    //Echo - yellow Jumper
int trigPinl = 13;    //Trig - green Jumper
int echoPinl = 2;    //Echo - yellow Jumper
int trigPinr = 3;    //Trig - green Jumper
int echoPinr = 4;    //Echo - yellow Jumper
long duration, cm, cml, cmr;
 
void setup() {
  Serial.begin (9600);
  pinMode(trigPinf, OUTPUT);
  pinMode(echoPinf, INPUT);
  pinMode(trigPinl, OUTPUT);
  pinMode(echoPinl, INPUT);
  pinMode(trigPinr, OUTPUT);
  pinMode(echoPinr, INPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  cm = 0;
  cml = 0;
  cmr = 0;
}
 
void loop()
{
  // Pulse To front
  digitalWrite(trigPinf, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPinf, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPinf, LOW);
  
  // Reading value
  pinMode(echoPinf, INPUT);
  duration = pulseIn(echoPinf, HIGH);
  cm = (duration/2) / 29.1;
  
  // Auomatinc
  
  if (cm < 50 )
  
  {
        // Stop the bot
            digitalWrite(6,LOW);
            digitalWrite(7,LOW);
            analogWrite(5,250);
            digitalWrite(8,LOW);
            digitalWrite(9,LOW);
            analogWrite(10,250);
            delay(20);
        
        // Now decide which way to go
        
            // Pulse To left
            digitalWrite(trigPinl, LOW);
            delayMicroseconds(5);
            digitalWrite(trigPinl, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPinl, LOW);
            
            // Reading left
            pinMode(echoPinl, INPUT);
            duration = pulseIn(echoPinl, HIGH);
            cml = (duration/2) / 29.1;
            
            // Pulse to right 
            digitalWrite(trigPinr, LOW);
            delayMicroseconds(5);
            digitalWrite(trigPinr, HIGH);
            delayMicroseconds(10);
            digitalWrite(trigPinr, LOW);
            
            // Reading left
            pinMode(echoPinr, INPUT);
            duration = pulseIn(echoPinr, HIGH);
            cmr = (duration/2) / 29.1;
        
        // Moving in the direction where obstacle is far away
                
          if (cml > cmr || cml >300 )
            {
              
              // Move left
              
                  
                digitalWrite(6,LOW);
                digitalWrite(7,HIGH);
                analogWrite(5,250);
                digitalWrite(8,HIGH);
                digitalWrite(9,LOW);
                analogWrite(10,250);
                delay(500);
            }
            
            else
            {
              
              // Move right
              
                digitalWrite(6,HIGH);
                digitalWrite(7,LOW);
                analogWrite(5,250);
                digitalWrite(8,LOW);
                digitalWrite(9,HIGH);
                analogWrite(10,250);
                delay(500);
              
            }
            
            
        
  }
  
  else 
    {       
        digitalWrite(6,LOW);
        digitalWrite(7,HIGH);
        analogWrite(5,250);
        digitalWrite(8,LOW);
        digitalWrite(9,HIGH);
        analogWrite(10,250);
        delay(500);
    }
    
  Serial.print(cm);
  Serial.print(" F ");
  Serial.print(cml);
  Serial.print(" L ");
  Serial.print(cmr);
  Serial.print(" R ");
  Serial.println();
}




