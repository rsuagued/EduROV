

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
  pinMode(pinMotor[MOTOR_CENTRAL][pin1],OUTPUT);
  pinMode(pinMotor[MOTOR_CENTRAL][pinEN],OUTPUT);
  pinMode(pinMotor[MOTOR_IZQUIERDO][pin1],OUTPUT);
  pinMode(pinMotor[MOTOR_IZQUIERDO][pinEN],OUTPUT);
  pinMode(pinMotor[MOTOR_DERECHO][pin1],OUTPUT);
  pinMode(pinMotor[MOTOR_DERECHO][pinEN],OUTPUT);
  digitalWrite(pinMotor[MOTOR_CENTRAL][pinEN],LOW);
  digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],LOW);
  digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],LOW);
  }
EduRov::EduRov(uint8_t puente){
  puenteH=puente;
  if (puenteH==PUENTE_LM298N){
    pinMotor[MOTOR_IZQUIERDO][pin1]=4;
    pinMotor[MOTOR_IZQUIERDO][pin2]=5;
    pinMotor[MOTOR_DERECHO][pin1]=7;
    pinMotor[MOTOR_DERECHO][pin2]=6;
    pinMotor[MOTOR_CENTRAL][pin1]=12;
    pinMotor[MOTOR_CENTRAL][pin2]=11;
    //En este tipo de puente en H el enable siempre está activo
    pinMode(pinMotor[MOTOR_CENTRAL][pin1],OUTPUT);
	pinMode(pinMotor[MOTOR_CENTRAL][pin2],OUTPUT);
	pinMode(pinMotor[MOTOR_IZQUIERDO][pin1],OUTPUT);
	pinMode(pinMotor[MOTOR_IZQUIERDO][pin2],OUTPUT);
	pinMode(pinMotor[MOTOR_DERECHO][pin1],OUTPUT);
	pinMode(pinMotor[MOTOR_DERECHO][pin2],OUTPUT);

    //Para parar los motores tengo que poner ambos pines a 0 o  a 1
    digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],LOW);
    digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);
    digitalWrite(pinMotor[MOTOR_DERECHO][pin1],LOW);
    digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);
    digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],LOW);
    digitalWrite(pinMotor[MOTOR_CENTRAL][pin2],LOW);
    }
 if (puenteH==PUENTE_LM298N_HEX){
    pinMotor[MOTOR_IZQUIERDO][pin1]=4;
    pinMotor[MOTOR_IZQUIERDO][pin2]=3;
    pinMotor[MOTOR_DERECHO][pin1]=7;
    pinMotor[MOTOR_DERECHO][pin2]=8;
    pinMotor[MOTOR_CENTRAL][pin1]=12;
    pinMotor[MOTOR_CENTRAL][pin2]=13;
    pinMotor[MOTOR_IZQUIERDO][pinEN]=5;
    pinMotor[MOTOR_DERECHO][pinEN]=6;
    pinMotor[MOTOR_CENTRAL][pinEN]=11;

	pinMode(pinMotor[MOTOR_CENTRAL][pin1],OUTPUT);
	pinMode(pinMotor[MOTOR_CENTRAL][pin2],OUTPUT);
	pinMode(pinMotor[MOTOR_CENTRAL][pinEN],OUTPUT);
	pinMode(pinMotor[MOTOR_IZQUIERDO][pin1],OUTPUT);
	pinMode(pinMotor[MOTOR_IZQUIERDO][pin2],OUTPUT);
	pinMode(pinMotor[MOTOR_IZQUIERDO][pinEN],OUTPUT);
	pinMode(pinMotor[MOTOR_DERECHO][pin1],OUTPUT);
	pinMode(pinMotor[MOTOR_DERECHO][pin2],OUTPUT);
	pinMode(pinMotor[MOTOR_DERECHO][pinEN],OUTPUT);
	//Para parar los motores tengo que poner los enables a 0
	digitalWrite(pinMotor[MOTOR_CENTRAL][pinEN],LOW);
	digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],LOW);
	digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],LOW);
    }
 if (puenteH==PUENTE_EDUSHIELD_CANARIAS){
	pinMode(pinMotor[MOTOR_CENTRAL][pin1],OUTPUT);
	pinMode(pinMotor[MOTOR_CENTRAL][pinEN],OUTPUT);
	pinMode(pinMotor[MOTOR_IZQUIERDO][pin1],OUTPUT);
	pinMode(pinMotor[MOTOR_IZQUIERDO][pinEN],OUTPUT);
	pinMode(pinMotor[MOTOR_DERECHO][pin1],OUTPUT);
	pinMode(pinMotor[MOTOR_DERECHO][pinEN],OUTPUT);
	 //Para parar los motores tengo que poner los enables a 0
	digitalWrite(pinMotor[MOTOR_CENTRAL][pinEN],LOW);
	digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],LOW);
	digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],LOW);
    }

  }  

EduRov::EduRov(uint8_t puente, uint8_t nMotores){
	puenteH=puente;
	motores=nMotores;
	if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
		 //en caso de se tengan más de dos motores
		 if (motores>2){
			 pinMode(pinMotor[MOTOR_CENTRAL][pin1],OUTPUT);
			pinMode(pinMotor[MOTOR_CENTRAL][pinEN],OUTPUT);
			//Para parar el motor tengo que poner el enable a 0
			digitalWrite(pinMotor[MOTOR_CENTRAL][pinEN],LOW);
		 }
	pinMode(pinMotor[MOTOR_IZQUIERDO][pin1],OUTPUT);
	pinMode(pinMotor[MOTOR_IZQUIERDO][pinEN],OUTPUT);
	pinMode(pinMotor[MOTOR_DERECHO][pin1],OUTPUT);
	pinMode(pinMotor[MOTOR_DERECHO][pinEN],OUTPUT);
	 //Para parar los motores tengo que poner los enables a 0
	
	digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],LOW);
	digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],LOW);
    }
	 if (puenteH==PUENTE_LM298N){
		 if (motores>2){
			pinMotor[MOTOR_CENTRAL][pin1]=12;
			pinMotor[MOTOR_CENTRAL][pin2]=11;
			pinMode(pinMotor[MOTOR_CENTRAL][pin1],OUTPUT);
			pinMode(pinMotor[MOTOR_CENTRAL][pin2],OUTPUT);
			//Para parar el motor tengo que poner los dos pines a 0
			digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],LOW);
			digitalWrite(pinMotor[MOTOR_CENTRAL][pin2],LOW);
		 }
		pinMotor[MOTOR_IZQUIERDO][pin1]=4;
		pinMotor[MOTOR_IZQUIERDO][pin2]=5;
		pinMotor[MOTOR_DERECHO][pin1]=7;
		pinMotor[MOTOR_DERECHO][pin2]=6;
	    //En este tipo de puente en H el enable siempre está activo
		pinMode(pinMotor[MOTOR_IZQUIERDO][pin1],OUTPUT);
		pinMode(pinMotor[MOTOR_IZQUIERDO][pin2],OUTPUT);
		pinMode(pinMotor[MOTOR_DERECHO][pin1],OUTPUT);
		pinMode(pinMotor[MOTOR_DERECHO][pin2],OUTPUT);
		//Para parar los motores tengo que poner ambos pines a 0 o  a 1
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);
		
    }
	if (puenteH==PUENTE_LM298N_HEX){
		 if (motores>2){
			pinMotor[MOTOR_CENTRAL][pin1]=12;
			pinMotor[MOTOR_CENTRAL][pin2]=13;
			pinMotor[MOTOR_CENTRAL][pinEN]=11;
			pinMode(pinMotor[MOTOR_CENTRAL][pin1],OUTPUT);
			pinMode(pinMotor[MOTOR_CENTRAL][pin2],OUTPUT);
			pinMode(pinMotor[MOTOR_CENTRAL][pinEN],OUTPUT);
			//Para parar el motor tengo que poner los dos pines a 0
			digitalWrite(pinMotor[MOTOR_CENTRAL][pinEN],LOW);
		 }
		pinMotor[MOTOR_IZQUIERDO][pin1]=4;
		pinMotor[MOTOR_IZQUIERDO][pin2]=3;
		pinMotor[MOTOR_DERECHO][pin1]=7;
		pinMotor[MOTOR_DERECHO][pin2]=8;
		pinMotor[MOTOR_IZQUIERDO][pinEN]=5;
		pinMotor[MOTOR_DERECHO][pinEN]=6;
		pinMode(pinMotor[MOTOR_IZQUIERDO][pin1],OUTPUT);
		pinMode(pinMotor[MOTOR_IZQUIERDO][pin2],OUTPUT);
		pinMode(pinMotor[MOTOR_IZQUIERDO][pinEN],OUTPUT);
		pinMode(pinMotor[MOTOR_DERECHO][pin1],OUTPUT);
		pinMode(pinMotor[MOTOR_DERECHO][pin2],OUTPUT);
		pinMode(pinMotor[MOTOR_DERECHO][pinEN],OUTPUT);
		//Para parar los motores tengo que poner los enables a 0
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],LOW);
    }
}
/***********************************************************
* Procedimiento que permita cambiar los pines de los motores
***********************************************************/
void EduRov::darPinesMotor(int motor,byte pines[3]){
	pinMotor[motor][pin1]=pines[0];
	pinMotor[motor][pin2]=pines[1];
	pinMotor[motor][pinEN]=pines[2];
  }
  
void EduRov::paraMotores(){
	if (puenteH==PUENTE_EDUSHIELD_CANARIAS ||puenteH==PUENTE_LM298N_HEX){ 
		if (motores>2) digitalWrite(pinMotor[MOTOR_CENTRAL][pinEN],LOW);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],LOW);
	 }
	if (puenteH==PUENTE_LM298N){ 
		if (motores>2) {
			digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],LOW);
			digitalWrite(pinMotor[MOTOR_CENTRAL][pin2],LOW);
		}
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);
	 } 
}
void  EduRov::paraMotor(int motor){
	 if (puenteH==PUENTE_EDUSHIELD_CANARIAS ||puenteH==PUENTE_LM298N_HEX){
		 digitalWrite(pinMotor[motor][pinEN],LOW);
	 }
	 if (puenteH==PUENTE_LM298N){
	  digitalWrite(pinMotor[motor][pin1],LOW);
	  digitalWrite(pinMotor[motor][pin2],LOW);
	 }
}
void  EduRov::avanza(){
if (puenteH==PUENTE_EDUSHIELD_CANARIAS){
	digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],HIGH);
	digitalWrite(pinMotor[MOTOR_DERECHO][pin1],HIGH);
	digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],HIGH);	
	digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],HIGH);
 }
if (puenteH==PUENTE_LM298N){
	digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],HIGH);
	digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);
	digitalWrite(pinMotor[MOTOR_DERECHO][pin1],HIGH);
	digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);
 }
if (puenteH==PUENTE_LM298N_HEX){ 
	digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],HIGH);
	digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);	
	digitalWrite(pinMotor[MOTOR_DERECHO][pin1],HIGH);
	digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);	
	digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],HIGH);
	digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],HIGH);
 }
}
void  EduRov::avanza(int velocidad){
	if (velocidad>255) velocidad = 255;
	if (velocidad<0) velocidad = 0;

	if (puenteH==PUENTE_EDUSHIELD_CANARIAS){
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],HIGH);
		analogWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],velocidad);	
		analogWrite(pinMotor[MOTOR_DERECHO][pinEN],velocidad);
	}
	if (puenteH==PUENTE_LM298N){
		analogWrite(pinMotor[MOTOR_IZQUIERDO][pin1],velocidad);	
		analogWrite(pinMotor[MOTOR_DERECHO][pin1],velocidad);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);
	}
	if (puenteH==PUENTE_LM298N_HEX){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);	
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);	
		analogWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],velocidad);	
		analogWrite(pinMotor[MOTOR_DERECHO][pinEN],velocidad);
	 }
}

void EduRov::retrocede(){
	if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],HIGH);	
		digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],HIGH);
	 }
	if (puenteH==PUENTE_LM298N){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],HIGH);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],HIGH);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],LOW);
	 }
	if (puenteH==PUENTE_LM298N_HEX){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],HIGH);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],LOW);	
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],HIGH);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],LOW);	
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],HIGH);
		digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],HIGH);
	 }
}

void EduRov::retrocede(int velocidad){
	if (velocidad>255) velocidad = 255;
	if (velocidad<0) velocidad = 0;
	
	if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],LOW);
		analogWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],velocidad);	
		analogWrite(pinMotor[MOTOR_DERECHO][pinEN],velocidad);
	 }
	if (puenteH==PUENTE_LM298N){ 
		velocidad=map(velocidad,0,255,255,0);
		analogWrite(pinMotor[MOTOR_IZQUIERDO][pin1],velocidad);	
		analogWrite(pinMotor[MOTOR_DERECHO][pin1],velocidad);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],HIGH);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],HIGH);
	 }
	if (puenteH==PUENTE_LM298N_HEX){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],HIGH);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],LOW);	
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],HIGH);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],LOW);	
		analogWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],velocidad);	
		analogWrite(pinMotor[MOTOR_DERECHO][pinEN],velocidad);
	 }
}
void EduRov::giraDerecha(){
	if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],HIGH);	
		digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],LOW);
	 }
	if (puenteH==PUENTE_LM298N){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);
	 }
	if (puenteH==PUENTE_LM298N_HEX){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);	
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],HIGH);
		digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],LOW);
	 }
}

void EduRov::giraDerecha(int velocidad){
	if (velocidad>255) velocidad = 255;
	if (velocidad<0) velocidad = 0;
	if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],HIGH);
		analogWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],velocidad);	
		digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],LOW);
	 }
	if (puenteH==PUENTE_LM298N){ 
		analogWrite(pinMotor[MOTOR_IZQUIERDO][pin1],velocidad);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);
	 }
	if (puenteH==PUENTE_LM298N_HEX){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);	
		analogWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],velocidad);;
		digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],LOW);
	 }
}
void  EduRov::giraIzquierda(){
	if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],HIGH);	
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],LOW);
	 }
	if (puenteH==PUENTE_LM298N){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);
	 }
	if (puenteH==PUENTE_LM298N_HEX){ 
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);	
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],LOW);
		digitalWrite(pinMotor[MOTOR_DERECHO][pinEN],HIGH);
	 }
}

void  EduRov::giraIzquierda(int velocidad){
	if (velocidad>255) velocidad = 255;
	if (velocidad<0) velocidad = 0;
	if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],HIGH);
		analogWrite(pinMotor[MOTOR_DERECHO][pinEN],velocidad);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],LOW);
	 }
	if (puenteH==PUENTE_LM298N){ 
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pin2],LOW);
		analogWrite(pinMotor[MOTOR_DERECHO][pin1],velocidad);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);
	 }
	if (puenteH==PUENTE_LM298N_HEX){ 
		digitalWrite(pinMotor[MOTOR_DERECHO][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_DERECHO][pin2],LOW);	
		digitalWrite(pinMotor[MOTOR_IZQUIERDO][pinEN],LOW);
		analogWrite(pinMotor[MOTOR_DERECHO][pinEN],velocidad);
	 }
}
void  EduRov::sumerge(){
	if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_CENTRAL][pinEN],HIGH);
		
	 }
	if (puenteH==PUENTE_LM298N){ 
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin2],LOW);
	 }
	if (puenteH==PUENTE_LM298N_HEX){
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin2],LOW);
		digitalWrite(pinMotor[MOTOR_CENTRAL][pinEN],HIGH);
	 }
}
void  EduRov::sumerge(int velocidad){
	if (velocidad>255) velocidad = 255;
	if (velocidad<0) velocidad = 0;
	
	if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],HIGH);
		analogWrite(pinMotor[MOTOR_CENTRAL][pinEN],velocidad);
		
	 }
	if (puenteH==PUENTE_LM298N){ 
		analogWrite(pinMotor[MOTOR_CENTRAL][pin1],velocidad);
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin2],LOW);
	 }
	if (puenteH==PUENTE_LM298N_HEX){
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],HIGH);
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin2],LOW);
		analogWrite(pinMotor[MOTOR_CENTRAL][pinEN],velocidad);
	 }
}
void  EduRov::emerge(){
	  if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_CENTRAL][pinEN],HIGH);
	 }
	if (puenteH==PUENTE_LM298N){ 
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin2],HIGH);
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],LOW);
	 }
	if (puenteH==PUENTE_LM298N_HEX){ 
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin2],HIGH);
		digitalWrite(pinMotor[MOTOR_CENTRAL][pinEN],HIGH);
	 }  
}
void  EduRov::emerge(int velocidad){
	if (velocidad>255) velocidad = 255;
	if (velocidad<0) velocidad = 0;
	velocidad=map(velocidad,0,255,255,0);
	
	  if (puenteH==PUENTE_EDUSHIELD_CANARIAS){ 
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],LOW);
		analogWrite(pinMotor[MOTOR_CENTRAL][pinEN],velocidad);
	 }
	if (puenteH==PUENTE_LM298N){ 
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin2],HIGH);
		analogWrite(pinMotor[MOTOR_CENTRAL][pin1],velocidad);
	 }
	if (puenteH==PUENTE_LM298N_HEX){ 
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin1],LOW);
		digitalWrite(pinMotor[MOTOR_CENTRAL][pin2],HIGH);
		analogWrite(pinMotor[MOTOR_CENTRAL][pinEN],velocidad);
	 }  
}
