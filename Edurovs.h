#define MOTOR_DERECHO 2
#define MOTOR_IZQUIERDO 1
#define MOTOR_CENTRAL 0
#define pin1 0
#define pin2 1
#define pinEN 2

//Tipos de puentes H
#define PUENTE_EDUSHIELD_CANARIAS 0 //Puente para las placas de motores y motor abordo de EduShield Canarias
#define PUENTE_LM298N 1      //Puente LM298 N con enables conectados a 1 ó L9110S.
#define PUENTE_LM298N_HEX 2  //Puentes con pines de enable a controlar. LM298N, sin jumpers, LM298N HEX, 6612FNG

class EduRov {
public:
  EduRov();
  EduRov(uint8_t puente);
  EduRov(uint8_t puente, uint8_t nMotores);
  void darPinesMotor(int motor,uint8_t pines[3]);
  void paraMotores();
  void paraMotor(int motor);
  void avanza();
  void avanza(int velocidad);
  void retrocede();
  void retrocede(int velocidad);
  void giraDerecha();
  void giraDerecha(int velocidad);
  void giraIzquierda();
  void giraIzquierda(int velocidad);
  void sumerge();
  void sumerge(int velocidad);
  void emerge();
  void emerge(int velocidad);

private:
  uint8_t puenteH=PUENTE_EDUSHIELD_CANARIAS; //Tipo de puente 0=Puente EduShiel Canarias
  int pinMotor[3][3]={
	{12,0,11},  //motor central
	{7,0,5},  //motor izquierdo
	{4,0,6}   //motor derecho
		};
    uint8_t motores=3;
};
