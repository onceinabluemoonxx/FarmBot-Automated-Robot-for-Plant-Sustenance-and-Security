int calibrationTime = 30;        

long unsigned int lowIn;         

long unsigned int pause = 5000;  

boolean lockLow = true;
boolean takeLowTime;  

int pirPin1 = 13;    
int pirPin2 = 12;
int pirPin3 = 11;
int pirPin4 = 10;
int Buzzer = 9;    

void setup(){
  Serial.begin(9600);
  pinMode(pirPin1, INPUT);
  pinMode(pirPin2, INPUT);
  pinMode(pirPin3, INPUT);
  pinMode(pirPin4, INPUT);

  pinMode(Buzzer, OUTPUT);
  digitalWrite(pirPin1, LOW);
  digitalWrite(pirPin2, LOW);
  digitalWrite(pirPin3, LOW);
  digitalWrite(pirPin4, LOW);


  Serial.print("calibrating sensor ");
    for(int i = 0; i < calibrationTime; i++){
      Serial.print(".");
      delay(1000);
      }
    Serial.println(" done");
    Serial.println("SENSOR ACTIVE");
    delay(50);
  }

void loop(){

     if(digitalRead(pirPin1) == HIGH){
   
       tone(Buzzer,500);
       if(lockLow){  
         lockLow = false;            
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec"); 
         delay(50);
         }         
         takeLowTime = true;
       }

     if(digitalRead(pirPin1) == LOW){       
       noTone(Buzzer);
       if(takeLowTime){
        lowIn = millis();          
        takeLowTime = false;       
        }

       if(!lockLow && millis() - lowIn > pause){  
        
           lockLow = true;                        
           Serial.print("motion ended at ");     
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
       }
       
     if(digitalRead(pirPin2) == HIGH){
       tone(Buzzer,500);
       if(lockLow){  
         lockLow = false;            
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec"); 
         delay(50);
         }         
         takeLowTime = true;
       }

     if(digitalRead(pirPin2) == LOW){       
     //  digitalWrite(ledPin2, LOW);  //the led visualizes the sensors output pin state
       noTone(Buzzer);
       if(takeLowTime){
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause, 
       //we assume that no more motion is going to happen
       if(!lockLow && millis() - lowIn > pause){  
           //makes sure this block of code is only executed again after 
           //a new motion sequence has been detected
           lockLow = true;                        
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
       }
       
     if(digitalRead(pirPin3) == HIGH){
    //   digitalWrite(ledPin3, HIGH);   //the led visualizes the sensors output pin state
       tone(Buzzer,500);
       if(lockLow){  
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;            
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec"); 
         delay(50);
         }         
         takeLowTime = true;
       }

     if(digitalRead(pirPin3) == LOW){       
     //  digitalWrite(ledPin3, LOW);  //the led visualizes the sensors output pin state
       noTone(Buzzer);
       if(takeLowTime){
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause, 
       //we assume that no more motion is going to happen
       if(!lockLow && millis() - lowIn > pause){  
           //makes sure this block of code is only executed again after 
           //a new motion sequence has been detected
           lockLow = true;                        
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
       }
       
     if(digitalRead(pirPin4) == HIGH){
  //     digitalWrite(ledPin4, HIGH);   //the led visualizes the sensors output pin state
       tone(Buzzer,500);
       if(lockLow){  
         //makes sure we wait for a transition to LOW before any further output is made:
         lockLow = false;            
         Serial.println("---");
         Serial.print("motion detected at ");
         Serial.print(millis()/1000);
         Serial.println(" sec"); 
         delay(50);
         }         
         takeLowTime = true;
       }

     if(digitalRead(pirPin4) == LOW){       
    //   digitalWrite(ledPin4, LOW);  //the led visualizes the sensors output pin state
       noTone(Buzzer);
       if(takeLowTime){
        lowIn = millis();          //save the time of the transition from high to LOW
        takeLowTime = false;       //make sure this is only done at the start of a LOW phase
        }
       //if the sensor is low for more than the given pause, 
       //we assume that no more motion is going to happen
       if(!lockLow && millis() - lowIn > pause){  
           //makes sure this block of code is only executed again after 
           //a new motion sequence has been detected
           lockLow = true;                        
           Serial.print("motion ended at ");      //output
           Serial.print((millis() - pause)/1000);
           Serial.println(" sec");
           delay(50);
           }
       }
  }
