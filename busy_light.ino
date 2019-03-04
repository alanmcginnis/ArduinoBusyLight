/////////Resources///////////
// https://learn.adafruit.com/adafruit-arduino-lesson-3-rgb-leds/arduino-sketch
// https://cdn-shop.adafruit.com/datasheets/FD-5WSRGB-A.pdf
// https://programmingelectronics.com/make-one-button-functionality-two-arduino/
// Ohm's Law: I = V/R

/////////Declare and Initialize Variables////////////////////////////

//We need to track how long the momentary pushbutton is held in order to execute different commands
//This value will be recorded in seconds
float pressLength_milliSeconds = 0;

// Define the *minimum* length of time, in milli-seconds, that the button must be pressed for a particular option to occur
int red_milliSeconds = 100;
int green_milliSeconds = 1000;
int blue_milliSeconds = 2000;
int off_milliSeconds = 4000;

//The Pin your button is attached to
int buttonPin = 2;


int redPin= 3;
int greenPin = 5;
int bluePin = 6;

void setup() {
  // Initialize the pushbutton pin as an input pullup
  // Keep in mind, when pin 2 has ground voltage applied, we know the button is being pressed
  pinMode(buttonPin, INPUT_PULLUP);
  //set the LEDs pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {

  //Record *roughly* the tenths of seconds the button in being held down
  while (digitalRead(buttonPin) == LOW ){
    delay(100);  //if you want more resolution, lower this number
    pressLength_milliSeconds = pressLength_milliSeconds + 100;
  }


  //Different if-else conditions are triggered based on the length of the button press
  //Start with the longest time option first

  //Turn Light Off
  if (pressLength_milliSeconds >= off_milliSeconds){
    setColor(0,0,0);
  }

  // Set Color to Blue
  else if(pressLength_milliSeconds >= blue_milliSeconds){
    setColor(0,0,255);
  }

  // Set Color to Green
  else if(pressLength_milliSeconds >= green_milliSeconds){
    setColor(0,255,0);
  }

  // Set Color to Red
  else if(pressLength_milliSeconds >= red_milliSeconds){
    setColor(255,0,0);
  }


  //every time through the loop, we need to reset the pressLength_Seconds counter
  pressLength_milliSeconds = 0;

} // close void loop

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}
