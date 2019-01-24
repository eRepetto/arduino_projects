
const byte ledPin = 20; // 13/20
const byte buttonPin = 9;
byte buttonState = 0;
boolean lightOn  = false;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
}

void loop() {
 //works holding the button   
 buttonState = digitalRead (buttonPin);
if(buttonState == HIGH){
  digitalWrite(ledPin, HIGH);
} else{
  digitalWrite(ledPin, LOW);    
  }
 
   //led pin number 13   
  /*
  digitalWrite(ledPin, HIGH);   // set the LED on
  delay(1000);                  // wait for a second
  digitalWrite(ledPin, LOW);    // set the LED off
  delay(1000);                  // wait for a second  
  */
  
  //switch
  /*
buttonState = digitalRead (buttonPin);
if(buttonState == HIGH){
 if(lightOn== false)
 lightOn = true;
 else
 lightOn = false;  
}

if(lightOn)
  digitalWrite(ledPin, HIGH);
  else
  digitalWrite(ledPin, LOW);

delay(100);
  
*/
}
