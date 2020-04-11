#include "Simulation.h"

Simulation::Simulation()
{
	continueRunning = true;
}

void Simulation::startMoving(int keycode, Worm* wormArray)
{
	int i;
	for (i = 0; i < NUMBER_OF_WORMS ; i++)
	{
		wormArray[i].fsm(keycode,DOWN);
	}
	
}

void Simulation::stopMoving(int keycode,Worm* wormArray)
{
	int i;
	for (i = 0; i < NUMBER_OF_WORMS; i++)
	{
		wormArray[i].fsm(keycode,UP);
	}

}

void Simulation::refresh(Worm * wormArray)
{
	int i;
	for (i = 0; i < NUMBER_OF_WORMS; i++)
	{
		wormArray[i].WormNewFrame();
		wormArray[i].fsm(REFRESH, DOWN);
	}
}

void Simulation::quit(void)
{
	printf("QUIT\n");
	continueRunning = false;
}

bool Simulation::running(void)
{
	return continueRunning;
}