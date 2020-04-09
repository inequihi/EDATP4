#include "Worm.h"

Worm::Worm()
{
	state = STILL;
	prevState = STILL;
	pos.x = 0;
	pos.y = 0;
	pos.dxdt = 0;
	pos.dxdtdt = 0;
	keyJump = '0';
	keyLeft = '0';
	keyRight = '0';
	wormDir = 1;
	ticks = 0;
}

Worm::Worm(char keyJump_, char keyLeft_, char keyRight_)
{
	pos.x = MIN_POSITION_X + static_cast <double> (rand()) / (static_cast <double> (RAND_MAX / (MAX_POSITION_X - MIN_POSITION_X)));
	pos.y = MIN_POSITION_Y; 
	keyJump = keyJump_;
	keyLeft = keyLeft_;
	keyRight = keyRight_;
	pos.dxdt = 27;			//Se mueve de a 27 pixeles por segundo 
	pos.dxdtdt = 0.24;
	state = STILL;
	prevState = STILL;
	wormDir = 1;
	ticks = 0;
}


/*******************************************
*			GETTERS							*
********************************************/
unsigned int Worm::getState(void) { return state; }
unsigned int Worm::getTick(void) { return ticks; }
double Worm::getPosX(void) {return pos.x;}
double Worm::getPosY(void) { return pos.y; }
int Worm::getDireccion(void) { return wormDir; }

void Worm::fsm(int keycode)
{
	EVENTO key_evento = turn_keycode_to_key(keycode);
	if (key_evento!=-1)
	{
		switch (this->state)
		{
		case STILL:
			if (key_evento == KEYJUMP)
			{
				this->ticks = 0;
				this->pos.dxdt = 4.5;
				WormJump();
				//WormNewFrame();
			}
			else if (key_evento == KEYLEFT || key_evento == KEYRIGHT)
				WormPreWalk();				//en preWalk set timer to 0 y camibio a estado premove
			else if(key_evento == REFRESH)
				this->ticks = 0;		//Nada se mueve
			break;

		case JUMPING:
			//Se ingora la tecla si se aprieta denuevo
			//Se ignoran todas las teclas si estamos saltando ya que hasta
			//no aterrizar el estado de jumping no hace nada mas que saltar
			WormJump();
			//WormNewFrame();
			break;

		case WALKING:
			if (key_evento == KEYJUMP)
			{
				this->ticks = 0;
				this->pos.dxdt = 4.5;
				WormJump();
				//WormNewFrame();
			}
			else if (key_evento == KEYLEFT || key_evento == KEYRIGHT || key_evento == REFRESH)
			{
				WormWalk();					//En worm walk vemos: -si tenemos q rotar o no 
									//-si pasaron los frames para movernos ?
			}
			//WormNewFrame();
			break;

		case PREMOVE:
			if (key_evento == KEYJUMP)
			{
				this->ticks = 0;
				this->pos.dxdt = 4.5;
				WormJump();		//Si estaba por moverse pero salto, cambio de estado a saltar
				//WormNewFrame();
			}
			else if (key_evento == REFRESH)
			{
				if (this->ticks > 100)			//ACA IRIA TIME CONDITION CON ALLEGRO TIMER
				{
					this->state = WALKING;
					this->ticks = 0;
					//SET TIMER DENUEVO A 0
				}
			}
			break;
		default:
			break;
		}
	}
}


int Worm::turn_keycode_to_key(int keycode)
{
	int key = -1;
	if (keycode == keyJump)
		key = KEYJUMP;
	else if (keycode == keyLeft)
		key = KEYLEFT;
	else if (keycode == keyRight)
		key = KEYRIGHT;
	else if (keycode == REFRESH)
		key = REFRESH;

	return key;
}

void Worm::WormJump() //Update caida no importa si estaempezando a saltar o continua en un salto
							//con dx y dy, posx posy podemos retomar movimiento sin problema 
{
	if (this->ticks >= 0 && this->ticks < CANT_IMAGES_JUMP)
	{
		state = JUMPING;
		if (!check4motion())		//si esta en el borde da la vuelta en el aire (nose)
		{
			this->wormDir *= -1;
		}

		this->pos.x += this->wormDir * cos(PI / 3)* pos.dxdt * this->ticks;			//4,5 es la velocidad de salto
			
		if (this->pos.y <= MIN_POSITION_Y)		//Eje en alegro es alreves por eso si es mas chico q base esta saltando
		{
			this->pos.y = MIN_POSITION_Y + this->pos.dxdt * ticks - this->pos.dxdtdt * 0.5 * this->ticks * this->ticks;
		}
		printf("JUMP, tick:%u\n",this->ticks);
	}
	else  //Back to still
	{
		this->pos.y = MIN_POSITION_Y;
		this->ticks = 0;
		this->state = STILL;
		this->pos.dxdt = 27;
		printf("END JUMP\n");
	}
}

bool Worm::check4motion()
{
	bool isOk = false;
	if (this->wormDir == RIGHT && this->pos.x < MAX_POSITION_X)
		isOk = true;
	if (this->wormDir == LEFT && this->pos.x > MIN_POSITION_X)
		isOk = true;
	
	return isOk;
}

void Worm::WormWalk()			//Aca verificar si tengo q cambiar sentido de direccion o no
{
	if (!check4motion())
	{
		this->wormDir *= -1;
	}

	this->pos.x += this->wormDir * this->pos.dxdt;
	printf("WALK\n");

}
void Worm::WormPreWalk()
{
	this->state = PREMOVE;

	//SET TIMER TO 0 
	printf("PRE WALK\n");
}

void Worm::WormNewFrame()
{
	this->ticks+= 1;				//NO ESTOY SEGURA SI ESTO ES LO QUE HACE REFRESH
	//printf("New Frame\n");
}

void Worm::WormStop()
{
	printf("STOP\n");
}

