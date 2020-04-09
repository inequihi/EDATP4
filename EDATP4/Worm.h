#ifndef WORM_H
#define WORM_H

#include "Prototypes.h"
#include "Graph.h"

#define LEFT -1
#define RIGHT 1
#define PI 3.14159265

typedef struct
{
	double x;
	double y;
	double dxdt;		//velocidad
	double dxdtdt;			//aceleracion

}position_t;

typedef unsigned int EVENTO;
typedef unsigned int ESTADO;

typedef struct
{
	EVENTO evento;
	ESTADO proximoEstado;
	void(*p_rut_accion)(void);
}STATE;

enum States {STILL, JUMPING, WALKING, PREMOVE, LANDING, MAXSTATES};
enum Keys {KEYJUMP, KEYLEFT, KEYRIGHT, REFRESH, NOKEY=-1};

class Worm
{
public:
	Worm();
	Worm(char, char, char);
	void WormJump();
	void WormWalk();
	void WormPreWalk();
	void WormNewFrame();
	void WormStop();
	void fsm(int newevent);
	int turn_keycode_to_key(int keycode);
	bool check4motion(void);

	/****************
	*   getters		*
	*****************/
	unsigned int getState(void);
	unsigned int getTick(void);
	double getPosX(void);
	double getPosY(void);
	int getDireccion(void);

protected:
	unsigned int state;
	unsigned int prevState;
	char keyJump;
	char keyLeft;
	char keyRight;
	unsigned int wormDir;
	position_t pos;
	unsigned int ticks;

};

#endif


/*
//TABLAS DE ESTADOS

//MAQUINA DE ESTADOS CON CADA RUTINA DE ACCION
	STATE array[5][5] =
	{
		//state: STILL  [0]
		{	{KEYJUMP,JUMPING,WormJump},
			{KEYLEFT,PREMOVE,this->WormPreWalk},
			{KEYRIGHT,PREMOVE,&(this->WormPreWalk)},
			{NOKEY, STILL, &(WormNewFrame)},

			{FIN, STILL, WormNewFrame} //sigue en mismo estado solo actualiza el frame
		}
		//state: JUMPING
		{	{KEYJUMP,JUMPING,WormJump},
			{KEYLEFT, JUMPING,WormJump},
			{KEYRIGHT, JUMPING, &(this->WormJump)},
			{NOKEY, JUMPING, &(this->WormNewFrame)},  //sigue en mismo estado solo actualiza el frame
			{FIN, JUMPING, &(this->WormNewFrame)}
		}
		//state: WALKING
		{
			{KEYJUMP,JUMPING,& (this->WormJump)},
			{KEYLEFT,WALKING, &(this->WormWalk)},	//wormwalk verifica si hay q cambiar orientacion
			{KEYRIGHT,WALKING, &(this->WormWalk)},
			{NOKEY,STILL, &(this->WormStop)},
			{FIN,WALKING, &(this->WormNewFrame)}		//sigue en mismo estado solo actualiza el frame
		}
		//state: PREMOVE
		{
			{KEYJUMP,JUMPING,& (this->WormJump)},
			{KEYLEFT, WALKING, &(this->WormWalk)},			//WormWalk verifica si pasaron los frames
			{KEYRIGHT, WALKING, &(this->WormWalk)},				//Si no pasaron todavcia devuelve estado PREMOVE
			{NOKEY, STILL, &(this->WormStop)},
			{FIN, PREMOVE, &(this->WormNewFrame)} 		//sigue en mismo estado solo actualiza el frame
		}
		//state: LANDING
		{	{KEYJUMP,LANDING,& (this->nothing2do)},			//Si estoy aterrizando y vuelvo a saltar espero a terminar de aterrizar
			{KEYLEFT, LANDING, &(this->nothing2do)},
			{KEYRIGHT, e_landing, &(this->nothing2do)},
			{NOKEY, LANDING, &(this->nothing2do)},
			{FIN, LANDING, &(this->WormNewFrame)}
		}

	}
	
intento de maquina

ESTADO Worm::StateMachine(ESTADO estado_actual, EVENTO evento_actual)
{
	//Recorro tablas de estado hasta encontrar rutina de accion

	while (p_tabla_estado->evento != evento_actual && p_tabla_estado->evento != FIN)
		++p_tabla_estado;

	//Cuando ya encuentro lo que tengo que hacer

	(*p_tabla_estado->p_rut_accion)();	//ejecuto accion

	p_tabla_estado= p_tabla_estado->proximoEstado;
}
*/