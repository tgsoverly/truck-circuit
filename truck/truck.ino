 int rightIn = 5;         // the number of the input pin
int rightOut = 11;       // the number of the output pin
int leftIn = 6;         // the number of the input pin
int leftOut = 12;       // the number of the output pin
int mainIn = 7;         // the number of the input pin
int mainOut = 13;       // the number of the output pin

int mainState = HIGH;     
int mainReading;           
int mainPrevious = LOW;

bool rightOn = false;
long rightSwitch = 0;
int rightState = HIGH;      
int rightReading;           
int rightPrevious = LOW;    

bool leftOn = false;    
long leftSwitch = 0;
int leftState = HIGH;      
int leftReading;           
int leftPrevious = LOW;  

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long mainTime = 0;         // the last time the output pin was toggled
long rightTime = 0;         // the last time the output pin was toggled
long leftTime = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers
long blinkSpeed = 700;

void setup()
{
  pinMode(rightIn, INPUT);
  pinMode(leftIn, INPUT);
  pinMode(mainIn, INPUT);
  pinMode(rightOut, OUTPUT);
  pinMode(leftOut, OUTPUT);
  pinMode(mainOut, OUTPUT);
}

void loop()
{
  long loopStart = millis();
  // ----------------------------
  //Main lights section
  // ----------------------------
  mainReading = digitalRead(mainIn);
  if (mainReading == HIGH && mainPrevious == LOW && millis() - mainTime > debounce) {
    if (mainState == HIGH)
      mainState = LOW;
    else
      mainState = HIGH;
    mainTime = millis();    
  }


  // ----------------------------
  // Left Blinker
  // ----------------------------

  //Read the input from the pin
  leftReading = digitalRead(leftIn);
  if (leftReading == HIGH && leftPrevious == LOW && millis() - leftTime > debounce) {
    if (leftOn == true)
      leftOn = false;
    else
      leftOn = true;
    leftTime = millis();    
  }
  //If the left blinker is on, then cycle it every second.
  if(leftOn){
    if(millis()-leftSwitch>blinkSpeed){
      leftSwitch=millis();
      if(leftState == HIGH){
        leftState = LOW;
      }else{
        leftState = HIGH;
      }
    }
  }else{
    leftState = LOW;
  }

  // ----------------------------
  //Right blinker
  // ----------------------------
  //Read the input from the pin
  rightReading = digitalRead(rightIn);
  if (rightReading == HIGH && rightPrevious == LOW && millis() - rightTime > debounce) {
    if (rightOn == true)
      rightOn = false;
    else
      rightOn = true;
    rightTime = millis();    
  }

  //If the right blinker is on, then cycle it every second.
  if(rightOn){
    if(millis()-rightSwitch>blinkSpeed){
      rightSwitch=millis();
      if(rightState == HIGH){
        rightState = LOW;
      }else{
        rightState = HIGH;
      }
    }
  }else{
    rightState = LOW;
  }


  digitalWrite(mainOut, mainState);
  digitalWrite(rightOut, rightState);
  digitalWrite(leftOut, leftState);

  mainPrevious = mainReading;
  rightPrevious = rightReading;
  leftPrevious = leftReading;
}
