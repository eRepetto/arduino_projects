//declare pins
const byte greenLED = 3;
const byte blueLED = 4;
const byte redLED = 5;
const byte pushButton = 10;

//Declare variables
boolean buttonPressed = false;
int counterRed =0 ;
int counterGreen = 0;
int counterBlue = 0;  
int delayTime = 1000;

int randomRed;
int randomGreen;
int randomBlue;

long dutyCycleRandNumber;

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
  pinMode(greenLED, OUTPUT);
  pinMode(blueLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(pushButton, INPUT);
  pinMode(0, INPUT); 
}

void loop() {

//demoOne();

randomColor();
  
}//end loop()


void displayColor(int red, int green, int blue){
analogWrite(redLED,red);
analogWrite(greenLED,green);
analogWrite(blueLED,blue);
}


void demoOne(){

//demo 1
   digitalWrite(greenLED, 1);
   delay(delayTime);
   digitalWrite(greenLED, 0);

    digitalWrite(redLED, 1);
   delay(delayTime);
   digitalWrite(redLED, 0);

    digitalWrite(blueLED, 1);
   delay(delayTime);
   digitalWrite(blueLED, 0);
  
}

void randomColor(){

 randomRed = random(255);
 randomGreen = random(255);
 randomBlue = random(255);

while(true){  
if (digitalRead(pushButton)==HIGH)
buttonPressed = true;

if (counterRed != randomRed){
  if(counterRed > randomRed)
counterRed--;
else
counterRed++;
}
if (digitalRead(pushButton)==HIGH)
buttonPressed = true;

if(counterGreen != randomGreen){
if(counterGreen > randomGreen)
counterGreen--;
else
counterGreen++;
}

if (digitalRead(pushButton)==HIGH)
buttonPressed = true;

if(counterBlue != randomBlue){
if(counterBlue > randomBlue)
counterBlue--;
else
counterBlue++;
}
  displayColor(counterRed, counterGreen, counterBlue);

delay(10);

if (digitalRead(pushButton)==HIGH)
buttonPressed = true;

if(counterRed == randomRed && counterGreen == randomGreen && counterBlue == randomBlue)
break;
}
  
delay(delayTime);

if (digitalRead(pushButton)==HIGH)
buttonPressed = true;

if (buttonPressed){
  while(digitalRead(pushButton) ==LOW){
  delay(10);
  if (digitalRead(pushButton) ==HIGH)
  break;  
  }
  Serial.println("button pressed");  
}  
}

void resetCounter(int red, int green, int blue){

while(red !=0 && green !=0 && blue !=0){
if(red !=0)
red--;
if(green !=0)
green--;
if (blue !=0)
blue--;

analogWrite(redLED,red);
analogWrite(greenLED,green);
analogWrite(blueLED,blue);

delay(10);
}  
}
