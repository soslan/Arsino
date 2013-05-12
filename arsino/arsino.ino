int pin, val, nextFlag=0, record=0, savedPin=0, flag=0;
float a,t,v,v2;
int incomingByte = 0;

void setup(){
  Serial.begin(9600);
  pin=0;
  analogReference(INTERNAL);
  
}

float getVoltage(int pin){
  float a, v;
  a=analogRead(pin);
  v=1.1 * a * 1000/1024;
  return v;
}

boolean processDigit(byte b){
  if(b>='0' && b<='9'){
    record=record*10+(b-'0');
    return true;
  }
  else{
    return false;
  }
}

int readNumber(){
  int record=0;
  byte b;
  while(Serial.available()>0){
    b=Serial.read();
    if(b>='0' && b<='9'){
      record=record*10+(b-'0');
    }
    else{
      return record;
    }
    
  }
}

void loop(){
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
    switch(flag){
      case 0:
        switch(incomingByte){
          case 'a':
            pin=readNumber();
            Serial.println(getVoltage(pin));
            break;
          case 'd':
            pin=readNumber();
            Serial.println(digitalRead(pin));
            break;
          case 'i':
            pin=readNumber();
            pinMode(pin, INPUT);
            Serial.println("Done");
            break;
          case 'o':
            pin=readNumber();
            pinMode(pin, OUTPUT);
            Serial.println("Done");
            flag=0;
            break;
          case 'D':
            pin=readNumber();
            val=readNumber();
            if(val==0){
              digitalWrite(pin, LOW);
            }
            else{
              digitalWrite(pin, HIGH);
            }
            Serial.println("Done");
            break;
          case 'A':
            pin=readNumber();
            val=readNumber();
            analogWrite(pin, val);
            Serial.println("Done");
            break;
            
        }
        break;
    }
   }
  delay(100);
}

