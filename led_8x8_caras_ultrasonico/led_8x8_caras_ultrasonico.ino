#include <LedControl.h>                   // Library for LED Control



const int trigPin = 7;                          // Assign Arduino Pin 7 as Trig Pin

const int echoPin = 8;                       // Assign Arduino Pin 8 as Echo Pin



long duration;                                   // Initialize Variable

int distance;                                     // Initialize Variable



int DIN = 12;                                     // Assign Arduino Pin D12

int CS =  11;                                     // Assign Arduino Pin D11 as Chip Select

int CLK = 10;                                   // Assign Arduino Pin D10 as Clock

byte smile[8] =   {0x04, 0x02, 0x24, 0x40, 0x40, 0x24, 0x02, 0x04}; // Matrix to Print Smile

byte nosmile[8] =   {0x00, 0x06, 0x06, 0x20, 0x20, 0x06, 0x06, 0x00}; // Matrix to Print NoSmile



LedControl lc = LedControl(DIN, CLK, CS, 0);       
void setup()

{

  pinMode(trigPin, OUTPUT);                                 // Sets the trigPin as an Output

  pinMode(echoPin, INPUT);                                  // Sets the echoPin as an Input

  Serial.begin(9600);                                              // Starts the serial communication

  lc.shutdown(0, false);                                          

  lc.setIntensity(0, 15);                                           // Set the brightness to maximum value

  lc.clearDisplay(0);                                               // and clear the display



}


void loop()

{

  digitalWrite(trigPin, LOW);

  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);                                 

  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);                                  

  duration = pulseIn(echoPin, HIGH);

  distance = duration * 0.034 / 2;                             // Calculating the distance

  Serial.print("Distance: ");                                       // Prints the distance on the Serial Monitor

  Serial.println(distance);



  if (distance < 6)                                                     // When the distance is less than 6 cm

  {

    printByte(smile);                                                // Print Smile on LCD

    delay(150);                                                        // Hold By 150 ms



  }

  else

  {

    printByte(nosmile);                                          // Print No smile on LCD

    delay(150);                                                      // Hold By 150 ms

  }

}



void printByte(byte character [])                         // Function to Print Characters

{

  int i = 0;

  for (i = 0; i < 8; i++)                                          // Loop for Printing Characters

  {

    lc.setRow(0, i, character[i]);                           // Set the Row to Print Characters

  }

}
