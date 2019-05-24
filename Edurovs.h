#define MOTOR_DERECHO 2
#define MOTOR_IZQUIERDO 1
#define MOTOR_CENTRAL 0
//Tipos de puentes H
#define PUENTE_EDUSHIELD_CANARIAS 0 //Puente para las placas de motores y motor abordo de EduShield Canarias
#define PUENTE_LM298N 1      //Puente LM298 N con enables conectados a 1 ó L9110S.
#define PUENTE_LM298N_HEX 2  //Puentes con pines de enable a controlar. LM298N, sin jumpers, LM298N HEX, 6612FNG

class EduRov {
public:
  EduRov();
  EduRov(byte puente);
  void darPinesMotor(int motor,byte pines[3]);
  void paraMotores();
  void paraMotor(int motor);
  void avanza();
  void retrocede();
  void giraDerecha();
  void giraIzquierda();
  void sumerge();
  void emerge();

private:
  uint8_t puenteH=PUENTE_EDUSHIELD_CANARIAS; //Tipo de puente 0=Puente EduShiel Canarias
  int pinMotorIzq=7;
  int pinMotorIzqEna=5;  
  int pinMotorDer=4;
  int pinMotorDerEna=6;
  int pinMotorSum=12;
  int pinMotorSumEna=11;
  int pinMotorIzq2;
  int pinMotorDer2;
  int pinMotorSum2;
};
