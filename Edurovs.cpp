

#if ARDUINO >= 100
#include "Arduino.h"
#else
extern "C" {
#include "WConstants.h"
#include <WProgram.h>
#include <pins_arduino.h>
}
#endif

#include "Edurovs.h"
/*****************************************************************************
* Constructores: Sin parámetros configura solo el puente de EduShield Canarias
*****************************************************************************/
EduRov::EduRov(){
  
  puenteH=PUENTE_EDUSHIELD_CANARIAS;
  pinMotorIzq=7;
  pinMotorIzqEna=5;  
  pinMotorDer=4;
  pinMotorDerEna=6;
  pinMotorSum=12;
  pinMotorSumEna=11;
  //No se usa un segundo pin de control
  pinMotorIzq2=0;
  pinMotorDer2=0;
  pinMotorSum2=0;
  
  pinMode(pinMotorIzq,OUTPUT);
  pinMode(pinMotorIzqEna,OUTPUT);
  pinMode(pinMotorDer,OUTPUT);
  pinMode(pinMotorDerEna,OUTPUT);
  pinMode(pinMotorSum,OUTPUT);
  pinMode(pinMotorSumEna,OUTPUT);
  digitalWrite(pinMotorIzqEna,LOW);
  digitalWrite(pinMotorDerEna,LOW);
  digitalWrite(pinMotorSumEna,LOW);
  }
EduRov::EduRov(byte puente){
  puenteH=puente;
  if (puenteH==PUENTE_LM298N){
    pinMotorIzq=4;
    pinMotorIzq2=5;
    pinMotorDer=7;
    pinMotorDer2=6;
    pinMotorSum=12;
    pinMotorSum2=11;
    //En este tipo de puente en H el enable siempre está activo
    pinMotorIzqEna=0;
    pinMotorDerEna=0;
    pinMotorSumEna=0;
   
    pinMode(pinMotorIzq,OUTPUT);
    pinMode(pinMotorIzq2,OUTPUT);
    pinMode(pinMotorDer,OUTPUT);
    pinMode(pinMotorDer2,OUTPUT);
    pinMode(pinMotorSum,OUTPUT);
    pinMode(pinMotorSum2,OUTPUT);
    //Para parar los motores tengo que poner ambos pines a 0 o  a 1
    digitalWrite(pinMotorIzq,LOW);
    digitalWrite(pinMotorDer,LOW);
    digitalWrite(pinMotorSum,LOW);
    digitalWrite(pinMotorIzq2,LOW);
    digitalWrite(pinMotorDer2,LOW);
    digitalWrite(pinMotorSum2,LOW);
    }
 if (puenteH==PUENTE_LM298N_HEX){
    pinMotorIzq=4;
    pinMotorIzq2=3;
    pinMotorDer=7;
    pinMotorDer2=8;
    pinMotorSum=12;
    pinMotorSum2=13;
    pinMotorIzqEna=5;
    pinMotorDerEna=6;
    pinMotorSumEna=11;
   
    pinMode(pinMotorIzq,OUTPUT);
    pinMode(pinMotorIzq2,OUTPUT);
    pinMode(pinMotorIzqEna,OUTPUT);
    pinMode(pinMotorDer,OUTPUT);
    pinMode(pinMotorDer2,OUTPUT);
    pinMode(pinMotorDerEna,OUTPUT);
    pinMode(pinMotorSum,OUTPUT);
    pinMode(pinMotorSum2,OUTPUT);
    pinMode(pinMotorSumEna,OUTPUT);
    //Para parar los motores tengo que poner los enables a 0
    digitalWrite(pinMotorIzqEna,LOW);
    digitalWrite(pinMotorDerEna,LOW);
    digitalWrite(pinMotorSumEna,LOW);
    }
 if (puenteH==PUENTE_EDUSHIELD_CANARIAS){
    pinMotorIzq=7;
    pinMotorIzqEna=5;  
    pinMotorDer=4;
    pinMotorDerEna=6;
    pinMotorSum=12;
    pinMotorSumEna=11;
    pinMode(pinMotorIzq,OUTPUT);
    pinMode(pinMotorIzqEna,OUTPUT);
    pinMode(pinMotorDer,OUTPUT);
    pinMode(pinMotorDerEna,OUTPUT);
    pinMode(pinMotorSum,OUTPUT);
    pinMode(pinMotorSumEna,OUTPUT);
    digitalWrite(pinMotorIzqEna,LOW);
    digitalWrite(pinMotorDerEna,LOW);
    digitalWrite(pinMotorSumEna,LOW);
    }
  }  
/***********************************************************
* Procedimiento que permita cambiar los pines de los motores
***********************************************************/
void EduRov::darPinesMotor(int motor,byte pines[3]){
  switch (motor){
  case MOTOR_DERECHO: 
    pinMotorDer = pines[0];
    pinMotorDer2 = pines[1];
    pinMotorDerEna = pines[2];
    break;
  case MOTOR_IZQUIERDO:
    pinMotorIzq = pines[0];
    pinMotorIzq2 = pines[1];
    pinMotorIzqEna = pines[2];
    break;
  case MOTOR_CENTRAL:
    pinMotorSum = pines[0];
    pinMotorSum2 = pines[1];
    pinMotorSumEna = pines[2];
    break;
  default:break;
  }
  }
void EduRov::paraMotores(){
if (puenteH==PUENTE_EDUSHIELD_CANARIAS ||puenteH==PUENTE_LM298N_HEX){ 
    digitalWrite(pinMotorDerEna,LOW);
    digitalWrite(pinMotorIzqEna,LOW);
    digitalWrite(pinMotorSumEna,LOW);
 }
if (puenteH==PUENTE_LM298N){ 
    digitalWrite(pinMotorDer,LOW);
    digitalWrite(pinMotorIzq,LOW);
    digitalWrite(pinMotorSum,LOW);
    digitalWrite(pinMotorDer2,LOW);
    digitalWrite(pinMotorIzq2,LOW);
    digitalWrite(pinMotorSum2,LOW);
 } 
}
void  EduRov::paraMotor(int motor){
 if (puenteH==PUENTE_EDUSHIELD_CANARIAS ||puenteH==PUENTE_LM298N_HEX){
  switch (motor){
  case MOTOR_DERECHO: 
    digitalWrite(pinMotorDerEna,LOW);
    break;
  case MOTOR_IZQUIERDO:
    digitalWrite(pinMotorIzqEna,LOW);
    break;
  case MOTOR_CENTRAL:
    digitalWrite(pinMotorSumEna,LOW);
    break;
  default:break;
  }
 }
 if (puenteH==PUENTE_LM298N){
  switch (motor){
  case MOTOR_DERECHO: 
    digitalWrite(pinMotorDer,LOW);
    digitalWrite(pinMotorDer2,LOW);
    break;
  case MOTOR_IZQUIERDO:
    digitalWrite(pinMotorIzq,LOW);
    digitalWrite(pinMotorIzq2,LOW);
    break;
  case MOTOR_CENTRAL:
    digitalWrite(pinMotorSum,LOW);
    digitalWrite(pinMotorSum2,LOW);
    break;
  default:break;
  }
 }
}
void  EduRov::avanza(){
if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
    digitalWrite(pinMotorDer,HIGH);
    digitalWrite(pinMotorIzq,HIGH);
    digitalWrite(pinMotorDerEna,HIGH);
    digitalWrite(pinMotorIzqEna,HIGH);
 }
if (puenteH==PUENTE_LM298N){ 
    digitalWrite(pinMotorDer,HIGH);
    digitalWrite(pinMotorIzq,HIGH);
    digitalWrite(pinMotorDer2,LOW);
    digitalWrite(pinMotorIzq2,LOW);
 }
if (puenteH==PUENTE_LM298N_HEX){ 
    digitalWrite(pinMotorDer,HIGH);
    digitalWrite(pinMotorIzq,HIGH);
    digitalWrite(pinMotorDer2,LOW);
    digitalWrite(pinMotorIzq2,LOW);
    digitalWrite(pinMotorDerEna,HIGH);
    digitalWrite(pinMotorIzqEna,HIGH);
 }
}
void EduRov::retrocede(){
if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
    digitalWrite(pinMotorDer,LOW);
    digitalWrite(pinMotorIzq,LOW);
    digitalWrite(pinMotorDerEna,HIGH);
    digitalWrite(pinMotorIzqEna,HIGH);
 }
if (puenteH==PUENTE_LM298N){ 
    digitalWrite(pinMotorDer2,HIGH);
    digitalWrite(pinMotorIzq2,HIGH);
    digitalWrite(pinMotorDer,LOW);
    digitalWrite(pinMotorIzq,LOW);
 }
if (puenteH==PUENTE_LM298N_HEX){ 
    digitalWrite(pinMotorDer2,HIGH);
    digitalWrite(pinMotorIzq2,HIGH);
    digitalWrite(pinMotorDer,LOW);
    digitalWrite(pinMotorIzq,LOW);
    digitalWrite(pinMotorDerEna,HIGH);
    digitalWrite(pinMotorIzqEna,HIGH);
 }
}
void EduRov::giraDerecha(){
if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
    digitalWrite(pinMotorIzq,HIGH);
    digitalWrite(pinMotorDerEna,LOW);
    digitalWrite(pinMotorIzqEna,HIGH);
 }
if (puenteH==PUENTE_LM298N){ 
    digitalWrite(pinMotorIzq,HIGH);
    digitalWrite(pinMotorIzq2,LOW);
    digitalWrite(pinMotorDer,LOW);
    digitalWrite(pinMotorDer,LOW);
 }
if (puenteH==PUENTE_LM298N_HEX){ 
    digitalWrite(pinMotorIzq,HIGH);
    digitalWrite(pinMotorIzq2,LOW);
    digitalWrite(pinMotorDerEna,LOW);
    digitalWrite(pinMotorIzqEna,HIGH);
 }
}
void  EduRov::giraIzquierda(){
if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
    digitalWrite(pinMotorDer,HIGH);
    digitalWrite(pinMotorDerEna,HIGH);
    digitalWrite(pinMotorIzqEna,LOW);
 }
if (puenteH==PUENTE_LM298N){ 
    digitalWrite(pinMotorIzq,LOW);
    digitalWrite(pinMotorIzq2,LOW);
    digitalWrite(pinMotorDer,HIGH);
    digitalWrite(pinMotorDer,LOW);
 }
if (puenteH==PUENTE_LM298N_HEX){ 
    digitalWrite(pinMotorDer,HIGH);
    digitalWrite(pinMotorDer2,LOW);
    digitalWrite(pinMotorDerEna,HIGH);
    digitalWrite(pinMotorIzqEna,LOW);
 }
}
void  EduRov::sumerge(){
if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
    digitalWrite(pinMotorSum,HIGH);
    digitalWrite(pinMotorSumEna,HIGH);
 }
if (puenteH==PUENTE_LM298N){ 
    digitalWrite(pinMotorSum,HIGH);
    digitalWrite(pinMotorSum2,LOW);
 }
if (puenteH==PUENTE_LM298N_HEX){ 
    digitalWrite(pinMotorSum,HIGH);
    digitalWrite(pinMotorSum2,LOW);
    digitalWrite(pinMotorSumEna,HIGH);
 }
}
void  EduRov::emerge(){
  if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
    digitalWrite(pinMotorSum,LOW);
    digitalWrite(pinMotorSumEna,HIGH);
 }
if (puenteH==PUENTE_LM298N){ 
    digitalWrite(pinMotorSum,HIGH);
    digitalWrite(pinMotorSum2,LOW);
 }
if (puenteH==PUENTE_LM298N_HEX){ 
    digitalWrite(pinMotorSum2,HIGH);
    digitalWrite(pinMotorSum,LOW);
    digitalWrite(pinMotorSumEna,HIGH);
 }  
}
