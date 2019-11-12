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
    //Raw Sensor
    /*int unknow2;
    //It's the digital temperature
    int unknow3;
    //It's the digital humidity
    int unknow4;
    //Day
    int unknow5;
    //Hour
    int unknow6;
    //Minute
    int unknow7;
    //Second
    int unknow8; */
    
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
      while ( !Serial ) delay(10);
      // Serial 1
      Serial1.begin(baudios);
    }

    // Read of the sensor and save variables
    void leerSensor()
    {
      Serial1.print('\r'); // Inicia una lectura del sensor. Ahora hay que espera a que nos envíe algo de vuelta!
      //Serial.println("Lectura del sensor iniciada...esperando...");
      Serial1InParser();
      for (int j = 0; j<11; j++)
      {
        //Give id value
        if(j == 0)
        {
          idSensor = sensorData[j];
        }
        //Give unknow value
        if(j == 1)
        {
          valorGasesIrritantes = sensorData[j]; //valor supuesto gas
        }
        //Give the temperature value
        if(j == 2)
        {
          valorTemperatura = sensorData[j];
        }
        //Give the humidity value
        if(j == 3)
        {
          humedad = sensorData[j];
        }
        //Give unknow value
        /*if(j == 4)
        {
          unknow2 = sensorData[j];
        }
        //Give unknow value
        if(j == 5)
        {
          unknow3 = sensorData[j];
        }
        //Give unknow value
        if(j == 6)
        {
          unknow4 = sensorData[j];
        }
        //Give unknow value
        if(j == 7)
        {
          unknow5 = sensorData[j];
        }
        //Give unknow value
        if(j == 8)
        {
          unknow6 = sensorData[j];
        }
        //Give unknow value
        if(j == 9)
        {
          unknow7 = sensorData[j];
        }
        //Give unknow value
        if(j == 10)
        {
          unknow8 = sensorData[j];
        }*/
        Serial.println(sensorData[j]);
      }
      //for (int j=0; j<11; j++) {Serial.println(sensorData[j]);}
      //Serial.println("EL SENSOR A LEÍDO");
    }

    //////////////////////////////////////////////////////////////////////////
    // Recive un string en sequencia ASCII y lo parsea
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
    // Function that orders the values returned by the gas sensor
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

    int dimeValorGasesIrritantes()
    {
      return valorGasesIrritantes;
    }
    
    int dimeTemperatura()
    {
      return valorTemperatura;
    }

    
 };
#endif
