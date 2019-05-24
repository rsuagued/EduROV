//Iniciando librerías
#include "Edurovs.h"

//Varables globlaes
EduRov robot(PUENTE_LM298N); //Este puente es el usado en los coches - Hay que verificar el pinout
//byte pinesD[]={5,4,0}; //pin1= 5 pin2= 4 pinEnable=0 - Posibles pines del motor derecho  
//byte pinesI[]={6,7,0}; //pin1= 6 pin2= 7 pinEnable=0 - Posibles pines del motor izquierdo  


void setup()
{
  //robot.darPinesMotor(MOTOR_DERECHO,pinesD); //Método que cambia los pines de un motor
  Serial.begin(9600);
}


void loop()
{
  robot.avanza();
  Serial.println("HACIA ADELANTE");
  delay(1000);
  robot.paraMotores();
  Serial.println("PARA TODOS LOS MOTORES");
  delay(2000);
  robot.giraDerecha();
  Serial.println("Gira hacia la derecha");
  delay(1000);
  robot.giraIzquierda();
  Serial.println("Gira hacia la izquierda");
  delay(1000);
  robot.paraMotor(MOTOR_DERECHO);
  Serial.println("Para el motor derecho");
  delay(2000);
  robot.retrocede();
  Serial.println("Marcha atrás");
  delay(1000);
  robot.paraMotores();
  Serial.println("Para los motores");
  delay(1000);
  
}
