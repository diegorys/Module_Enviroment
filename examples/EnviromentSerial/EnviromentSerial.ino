#include <ModuleEnviroment.h>

ModuleEnviroment enviroment = ModuleEnviroment(8);

void setup() {
  Serial.begin(9600);
  enviroment.attachTemperature(A2);
  enviroment.attachLight(A1);
  enviroment.enableIR();
}

void loop() {
  float temperature = enviroment.getTemperature();
  float light = enviroment.getLight();
  unsigned long code = enviroment.getIR();

  Serial.print("Temperature\t");
  Serial.println(temperature);
  Serial.print("Light\t\t");
  Serial.println(light);
  if (code != REPEAT) {
    Serial.print("IR\t\t");
    Serial.println(code, HEX);
    enviroment.sendIR(NEC, code);
  }
  
  delay(2000);
}
