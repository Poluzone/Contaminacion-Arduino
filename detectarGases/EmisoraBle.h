/**
 * 
 * Library EmisoraBLE -- Respiratory Irritants
 * 
 * Author: Matthew Conde Oltra
 * Team - 3
 * Date: 23/09/2019
 * 
 * 
 */

#ifndef EmisoraBle_h
#define EmisoraBle_h
 
 class EmisoraBle {
	private:
	  uint8_t beaconUUID[16] = {
         'E', 'Q', 'U', 'I', 'P', 'O', '-', '3',
         'X', 'U', 'R', 'O', 'D', 'I', 'M', 'I'
         };
	public:

		EmisoraBle()
		{
		  
		}
   
		void inicializar()
		{
		   //
		   // Initialise the Bluefruit module
		   //
		   Serial.println("Initialise the Bluefruit nRF52 module");
		   Bluefruit.begin();
		
		   //
		   // Set the advertised device name (keep it short!)
		   //
		   Serial.println("Setting Device Name to Equipo-3 " );
		
		   Bluefruit.setName("EQUIPO-3");
		   Bluefruit.ScanResponse.addName();
		
		   //
		   //
		   //
		   startAdvertising();
		
		   //
		   //
		   //
		   Serial.println("\nAdvertising");
		}
	 
	  void startAdvertising() 
	  {

       Serial.println( " startAdvertising() " );
    
       Serial.println( " Bluefruit.Advertising.stop(); ");
       Bluefruit.Advertising.stop(); // ya lo enchufo luego
    
       //
       // Advertising packet
       //
       Bluefruit.Advertising.addFlags(BLE_GAP_ADV_FLAGS_LE_ONLY_GENERAL_DISC_MODE);
       Bluefruit.Advertising.addTxPower();
    
       //
       //
       //
    
    
       // Include Name
       Serial.println( " Bluefruit.Advertising.addName(); " );
       Bluefruit.Advertising.addName();
    
       //
       //
       //
       Serial.println( " Bluefruit.Advertising.setBeacon( elBeacon ); ");
    
       /*uint8_t beaconUUID[16] = {
         'E', 'Q', 'U', 'I', 'P', 'O', '-', '3',
         'X', 'U', 'R', 'O', 'D', 'I', 'M', 'I'
         };*/
       BLEBeacon elBeacon( beaconUUID, 12, 34, 73 );
       elBeacon.setManufacturer( 0x004c ); // aple id
       Bluefruit.Advertising.setBeacon( elBeacon );
    
       //
       //
       //
       Bluefruit.Advertising.restartOnDisconnect(true);
       Bluefruit.Advertising.setInterval(32, 244);    // in unit of 0.625 ms
       Bluefruit.Advertising.setFastTimeout(30);      // number of seconds in fast mode
       Bluefruit.Advertising.start(0);                // 0 = Don't stop advertising after n seconds
    
       Serial.println( " Bluefruit.Advertising.start(0);" );
    
    } // startAdvertising ()

    //-------------------------------------------------------------------
    //Función para emitir el valor de la temperatura
    //-------------------------------------------------------------------
    void emitirValoresGasesIrritantes(int valorGasesIrritantes, int valorTemperatura)
    {
      
       BLEBeacon elBeacon( beaconUUID, valorGasesIrritantes, valorTemperatura, 73 );
       elBeacon.setManufacturer( 0x004c ); // aple id
       Bluefruit.Advertising.setBeacon( elBeacon );
    }
	 
 };

 #endif
