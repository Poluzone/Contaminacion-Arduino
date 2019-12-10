/**
 * Library Sensor -- Respiratory Irritants
 * 
 * Author: Matthew Conde Oltra
 * Team - 3
 * Date: 23/09/2019
 * 
 * 
 */

 //SN [XXXXXXXXXXXX], 
 //PPB [0 : 999999], 
 //TEMP [-99 : 99], 
 //RH [0 : 99], 
 //RawSensor[ADCCount], 
 //TempDigital, 
 //RHDigital, 
 //Day [0 : 99], 
 //Hour [0 : 23], 
 //Minute [0 : 59], 
 //Second [0 : 59]

#ifndef Sensor_h
#define Sensor_h
 
#include "Arduino.h"

 class Sensor {
  // Variables privadas
  private: 
    long baudios;
    int sensorData [11];
    //Values of the sensor
    //Serial number
    int idSensor;
    //PPB 
    int valorGasesIrritantes;
    //It's the temperature
    int valorTemperatura;
    //It's the humidity
    int humedad;    
  // Constructor y metodos
  public:
    Sensor(long baudios_)
    {
      baudios = baudios_;
    }
    // Initialize the serial for sensor values
    void inicializar()
    { 
      Serial.begin(baudios);
      //Comentamos el while que ejecutará el sensor al abrir el Serial
      //while ( !Serial ) delay(10);
      // Serial 1
      Serial1.begin(baudios);
    }

    //Función que lee del sensor y guarda los valores en las variables globales
    void leerSensor()
    {
      Serial1.print('\r'); // Inicia una lectura del sensor. Ahora hay que espera a que nos envíe algo de vuelta!
      Serial.println("Lectura del sensor iniciada...esperando...");
      Serial1InParser();
      //Guardamos los valores en su variable correspondiente
      idSensor = sensorData[0];
      valorGasesIrritantes = sensorData[1];
      valorTemperatura = sensorData[2];
      humedad = sensorData[3];
    }

    //////////////////////////////////////////////////////////////////////////
    // Recibe un string en sequencia ASCII y lo parsea
    //////////////////////////////////////////////////////////////////////////

    void Serial1InParser(void)
    {
        int i = 0;
        for (int i =0; i<11; i++) {
           while(!Serial1.available()) {
              //Serial.println("No está disponible");
            }
           sensorData[i] = Serial1.parseInt();
        }
    }

    //----------------------------------------------------------------------
    // Función para devolver en el serial lo que está recogiendo el sensor
    //----------------------------------------------------------------------
    void muestrameEnElSerial()
    {
      // coge el valor sensorData[] y lo separa
      leerSensor();
      Serial.println("---------- DATA OF THE SENSOR ----------");
      Serial.print("The id of the sensor is: ");
      Serial.println(idSensor);
      Serial.print("The gas value is: ");
      Serial.println(valorGasesIrritantes);
      Serial.print("The temperature is: ");
      Serial.println(valorTemperatura);
      Serial.print("The humidity is: ");
      Serial.println(humedad);
      Serial.println("The other values are unknow...");
    }

    //Devuelve el valor de los gases irritantes recogido
    /**
     * dimeValorGasesIrritantes() --> N
     */
    int dimeValorGasesIrritantes()
    {
      return valorGasesIrritantes;
    }
   //Devuelve el valor de la temperatura recogida
   /**
     * dimeTemperatura() --> N
     */
    int dimeTemperatura()
    {
      return valorTemperatura;
    }

    
 };
#endif
