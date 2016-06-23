/*
 * ModuleEnviroment
 * Version 1.0.0 May, 2016 - First version.
 * Copyright 2016 Diego de los Reyes
 *
 * Interacts with the enviroment of the robot.
 */

#include "ModuleEnviroment.h"

   
/** CONSTRUCTORES **/

/**
 * Construct.
 */
ModuleEnviroment::ModuleEnviroment(int rx): receiver(rx)
{
	
}

/** PUBLIC METHODS **/

/**
 * Enable IR Sensor
 */
void ModuleEnviroment::enableIR()
{
	receiver.enableIRIn();
}

/**
 * Attach the given pin.
 * @param pin: pin where the sensor is connected.
 */
void ModuleEnviroment::attachTemperature(int pin)
{
	pinTemperature = pin;
	pinMode(pinTemperature, INPUT);
}

/**
 * Attach the given pin.
 * @param pin: pin where the sensor is connected.
 */
void ModuleEnviroment::attachLight(int pin)
{
	pinLight = pin;
	pinMode(pinLight, INPUT);
}

/**
 * Send IR signal.
 */
void ModuleEnviroment::sendIR(IRTYPES protocol, unsigned long code)
{
	emitter.send(protocol, code, 32);
}

/**
 * Gets IR signal.
 */
unsigned long ModuleEnviroment::getIR()
{

	if (receiver.GetResults(&decoder)) {		
		decoder.decode();//decode the signal
		//decoder.DumpResults();//dump the results on the serial monitor
		code = decoder.value;
		Serial.print("IR\t\t");
    	Serial.println(code, HEX);
		receiver.resume(); //restart the receiver
	}

  	return 0xFFFFFFFF;
}

/**
 * Gets ambient temperature.
 */
float ModuleEnviroment::getTemperature()
{
  Vout=(Vin/1024)*(analogRead(pinTemperature));
  Rntc=(Vout*Rfija)/(Vin-Vout);
  TempK = Beta/(log(Rntc/R25)+(Beta/T0));
  TempC = TempK-273.15;

  return TempC;
}

/**
 * Gets ambient light.
 */
float ModuleEnviroment::getLight()
{
	return analogRead(pinLight);
}
