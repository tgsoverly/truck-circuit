int rightIn = 5;         // the number of the input pin
int rightOut = 11;       // the number of the output pin
int leftIn = 6;         // the number of the input pin
int leftOut = 12;       // the number of the output pin
int mainIn = 7;         // the number of the input pin
int mainOut = 13;       // the number of the output pin

int mainState = HIGH;     
int mainReading;           
int mainPrevious = LOW;    
// int stateRight = HIGH;      
// int readingRight;           
// int previousRight = LOW;    

// the follow variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.
long mainTime = 0;         // the last time the output pin was toggled
long debounce = 200;   // the debounce time, increase if the output flickers

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
  mainReading = digitalRead(mainIn);
  long loopStart = millis()
  // if the input just went from LOW and HIGH and we've waited long enough
  // to ignore any noise on the circuit, toggle the output pin and remember
  // the time
  if (mainReading == HIGH && mainPrevious == LOW && millis() - mainTime > debounce) {
    if (state == HIGH)
      mainState = LOW;
    else
      mainState = HIGH;

    mainTime = millis();    
  }

  digitalWrite(mainOut, mainState);

  mainPrevious = mainReading;
}
