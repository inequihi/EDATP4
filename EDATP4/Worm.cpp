#include "Worm.h"

Worm::Worm()
{
	state = 0;
	pos.x = 0;
	pos.y = 0;
	pos.dx = 0;
	pos.dy = 0;
	keyJump = '0';
	keyLeft = '0';
	keyRight = '0';
}

Worm::Worm(char keyJump_, char keyLeft_, char keyRight_)
{
	pos.x = MIN_POSITION_X + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (MAX_POSITION_X - MIN_POSITION_X)));
	pos.y = MIN_POSITION_Y; 
	keyJump = keyJump_;
	keyLeft = keyLeft_;
	keyRight = keyRight_;
	pos.dx = 27;			//Se mueve de a 27 pixeles por segundo 

}

void Worm::WormJump() //Update caida no importa si estaempezando a saltar o continua en un salto
							//con dx y dy, posx posy podemos retomar movimiento sin problema 
{
	printf("JUMP\n");
}

void Worm::WormLanding()
{
	printf("LAND\n");
}

void Worm::WormWalk()			//Aca verificar si tengo q cambiar sentido de direccion o no
{
	printf("WALK\n");
}
void Worm::WormPreWalk()
{
	printf("PRE WALK\n");
}

void Worm::WormNewFrame()
{
	printf("New Frame\n");
}

void Worm::nothing2do()
{
	printf("DO NTH\n");
}

void Worm::WormStop()
{
	printf("STOP\n");
}
