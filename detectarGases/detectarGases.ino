// ----------------------------------------------------
// ---- general.ino ---
// Adaptado del codigo de Jordi Bataller
// Matthew Conde Oltra
// 23/09/2019
// Descripción: código principal de la Sparkfun
// ----------------------------------------------------
#include <bluefruit.h>
#include "EmisoraBle.h"
#include "Sensor.h"
// ----------------------------------------------------
// Declaramos la emisora
// ----------------------------------------------------
EmisoraBle emisora;
// ----------------------------------------------------
// Declaro los sensores
// ----------------------------------------------------
Sensor sensorUno(9600);
// ----------------------------------------------------
// setup
// ----------------------------------------------------
void setup() {
   
   Serial.println("-----------------------\n");
   Serial.println(" PRUEBAS iBeacon  ");
   Serial.println("-----------------------\n");

   // Inicialize the sensor
   sensorUno.inicializar();
   // Inicialize station
   emisora.inicializar();
   
} // setup()
// ----------------------------------------------------
// ----------------------------------------------------
void loop() {
   //SHOW SENSOR DATA
   sensorUno.muestrameEnElSerial();
   emisora.emitirValoresGasesIrritantes(sensorUno.dimeValorGasesIrritantes(),sensorUno.dimeTemperatura());
   delay(30000);
} // ()
// ----------------------------------------------------
// ----------------------------------------------------
// ----------------------------------------------------
// ----------------------------------------------------
