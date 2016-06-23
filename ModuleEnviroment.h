/*
 * ModuleEnviroment
 * Version 1.0.0 May, 2016 - First version.
 * Copyright 2016 Diego de los Reyes
 *
 * Interacts with the enviroment of the robot.
 */

#ifndef ModuleEnviroment_h
#define ModuleEnviroment_h
#define LIBRARY_VERSION	 0.1

// include core Wiring API and now Arduino
#if ARDUINO >= 100
  #include "Arduino.h"
#else
  #include "WProgram.h"
#endif

#include <IRLib.h>
#include <IRLibMatch.h>
#include <IRLibTimer.h>

// Class ModuleEnviroment
class ModuleEnviroment {
 
	/** Public elements. **/
	public:
	
		/**
		 * Construct.
		 */
		ModuleEnviroment(int rx);

		/**
		 * Enable IR Sensor
		 */
		void enableIR();

		/**
		 * Attach the given pin.
		 * @param pin: pin where the sensor is connected.
		 */
		void attachTemperature(int pin);

		/**
		 * Attach the given pin.
		 * @param pin: pin where the sensor is connected.
		 */
		void attachLight(int pin);
	
		/**
		 * Send IR signal.
		 */
		void sendIR(IRTYPES protocol, unsigned long code);

		/**
		 * Gets IR signal.
		 */
		unsigned long getIR();

		/**
		 * Gets ambient temperature.
		 */
		float getTemperature();

		/**
		 * Gets ambient light.
		 */
		float getLight();

		unsigned long code;

	private:

		/** Attributes **/

		//Attached pins
		int pinIREmitter;
		int pinIRReceiver;
		int pinTemperature;
		int pinLight;

		IRsend emitter;
		IRrecv receiver;
		IRdecode decoder;
		IRTYPES protocol = UNKNOWN;

		float Vin = 5.0;
		float Rfija = 2200;
		float R25 = 4700;
		float Beta = 3900.0;
		float T0 = 293.15;
		float Vout = 0.0;
		float Rntc = 0.0;
		float TempK = 0.0;
		float TempC = 0.0;
};

#endif

