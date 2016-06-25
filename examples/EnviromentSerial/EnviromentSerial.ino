#include <ModuleEnviroment.h>

ModuleEnviroment enviroment = ModuleEnviroment(8);
unsigned long code;

void setup() {
  Serial.begin(9600);
  enviroment.attachTemperature(A2);
  enviroment.attachLight(A1);
  enviroment.enableIR();

  Serial.println("1. Get temperature");
  Serial.println("2. Get light");
  Serial.println("3. Get IR");
  Serial.println("4. Send IR");
  Serial.println("Select option: ");
}

void loop() {
    int order = getOrder();
    executeOrder(order);    
}

int getOrder() {   
  int order = 0;
  //We received the order.
  if (Serial.available() > 0) {
    order = Serial.parseInt();
  }
  
  return order;
}

void executeOrder(int order) {
    float temperature;
    float light;
    
    //We execute the order.
    switch(order){
      case 0:
        //It has not received anything.
        break;
      case 1:
        temperature = enviroment.getTemperature();
        Serial.print("Temperature\t");
        Serial.println(temperature);
        break;
      case 2:
        light = enviroment.getLight();
        Serial.print("Light\t\t");
        Serial.println(light);
        break;
      case 3:
        code = enviroment.getIR();
        Serial.print("IR\t\t");
        Serial.println(code, HEX);
        break;
      case 4:
        Serial.print("Sending IR\t");
        enviroment.sendIR(NEC, code);
        Serial.println(code, HEX);
        break;
      default:
        Serial.println("Unknown order");
     }
}
