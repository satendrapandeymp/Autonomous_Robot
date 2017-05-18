int trigPinf = 9;    //Trig - green Jumper
int echoPinf = 8;    //Echo - yellow Jumper
int trigPinl = 11;    //Trig - green Jumper
int echoPinl = 10;    //Echo - yellow Jumper
int trigPinr = 7;    //Trig - green Jumper
int echoPinr = 6;    //Echo - yellow Jumper
long duration, cm, cml, cmr;
int min_bt_3 (int a, int b, int c) 
{
  if (a<b)
  {
    if (a<c)
    return a;
    else 
    return c;
  }
  else
  {
    if (b<c)
    return b;
    else 
    return c;
  }
}

 
void setup() {
  Serial.begin (9600);
  pinMode(trigPinf, OUTPUT);
  pinMode(echoPinf, INPUT);
  pinMode(trigPinl, OUTPUT);
  pinMode(echoPinl, INPUT);
  pinMode(trigPinr, OUTPUT);
  pinMode(echoPinr, INPUT);
  pinMode(0, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
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
  
  // Pulse to left
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
  
  // Reading right
  pinMode(echoPinr, INPUT);
  duration = pulseIn(echoPinr, HIGH);
  cmr = (duration/2) / 29.1;

  
  
  // Auomatinc
  
  if (cm < 25 || cml < 20 || cmr < 20 )
  
  {
        int dir = min_bt_3(cm , cmr , cml);
        // Stop the bot
            digitalWrite(2,LOW);
            digitalWrite(13,LOW);
            analogWrite(12,250);
            digitalWrite(3,LOW);
            digitalWrite(4,LOW);
            analogWrite(5,250);
            delay(20);
            
        if (cm < 25 && cml < 20 && cmr < 20 )
        {
         // Back bot
         
          digitalWrite(2,HIGH);
          digitalWrite(13,LOW);
          analogWrite(12,250);
          digitalWrite(3,HIGH);
          digitalWrite(4,LOW);
          analogWrite(5,250);
          delay(2000);
          
          // check o move left or right 
          
          // Pulse to left
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
          
          // Reading right
          pinMode(echoPinr, INPUT);
          duration = pulseIn(echoPinr, HIGH);
          cmr = (duration/2) / 29.1;
          
          // Now move left or right
          
            if (cml > cmr || cml > 50 )
                    {
                      
                      // Move left
                      
                          
                        digitalWrite(2,LOW);
                        digitalWrite(13,HIGH);
                        analogWrite(12,250);
                        digitalWrite(3,HIGH);
                        digitalWrite(4,LOW);
                        analogWrite(5,250);
                        delay(2000);
                    }
                    
                    else
                    {
                      
                      // Move right
                      
                        digitalWrite(2,HIGH);
                        digitalWrite(13,LOW);
                        analogWrite(12,250);
                        digitalWrite(3,LOW);
                        digitalWrite(4,HIGH);
                        analogWrite(5,250);
                        delay(2000);
                      
                    }
                
        }
        
        else {
          
            // Now decide which way to go
        if ( cm == dir )
        {
                if (cml > cmr || cml > 50 )
                    {
                      
                      // Move left
                      
                          
                        digitalWrite(2,LOW);
                        digitalWrite(13,HIGH);
                        analogWrite(12,250);
                        digitalWrite(3,HIGH);
                        digitalWrite(4,LOW);
                        analogWrite(5,250);
                        delay(2000);
                    }
                    
                    else
                    {
                      
                      // Move right
                      
                        digitalWrite(2,HIGH);
                        digitalWrite(13,LOW);
                        analogWrite(12,250);
                        digitalWrite(3,LOW);
                        digitalWrite(4,HIGH);
                        analogWrite(5,250);
                        delay(2000);
                      
                    }
                
           }
        
        if (cml == dir )
       {
       
            digitalWrite(2,HIGH);
            digitalWrite(13,LOW);
            analogWrite(12,250);
            digitalWrite(3,LOW);
            digitalWrite(4,HIGH);
            analogWrite(5,250);
            delay(2000);
         
       } 
       
        if (cmr == dir )
       {
       
          digitalWrite(2,LOW);
          digitalWrite(13,HIGH);
          analogWrite(12,250);
          digitalWrite(3,HIGH);
          digitalWrite(4,LOW);
          analogWrite(5,250);
          delay(2000);
         
       } 
          
        }
        
      
            
            
        
  }
  
  
  
  else 
    {       
        digitalWrite(2,LOW);
        digitalWrite(13,HIGH);
        analogWrite(12,250);
        digitalWrite(3,LOW);
        digitalWrite(4,HIGH);
        analogWrite(5,250);
        delay(200);
    }
    
  Serial.print(cm);
  Serial.print(" F ");
  Serial.print(cml);
  Serial.print(" L ");
  Serial.print(cmr);
  Serial.print(" R ");
  Serial.println();
}




