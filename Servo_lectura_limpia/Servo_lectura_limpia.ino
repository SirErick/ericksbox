/*
 * By: Erick M. Sirpa
 * Conexiones: 
 * Servomotor - pin 9
 * Potenciometro - pin A0
 */

#include <Servo.h>

int Lecturas[10]; //Vector de lecturas.
int Val, i = 0, Total = 0, Promedio = 0;
Servo MiServo;

void setup(){
MiServo.attach(9);
Serial.begin(9600);
for(i=0; i< 10; i++) //Inicialización del vector.
Lecturas[i] = 0;
i=0;
}

void loop(){
//Sustrae el total con la lectura inmediata anterior
Total = Total - Lecturas[i];
//Agrega una lectura a la posición actual dentro del vector
Lecturas[i] = analogRead(A0);
//Realiza la sumatoria entre lecturas
Total = Total + Lecturas[i];
i = i + 1;
//Calcula el promedio y envía el resultado al servomotor
if (i >= 10){
i = 0;
Promedio = Total / 10;
Val = map(Promedio, 0, 1023, 0, 179);
MiServo.write(Val);
Serial.println(Val, DEC);
}
}
