#include "Simulation.h"

Simulation::Simulation()
{
	continueRunning = true;
}

void Simulation::startMoving(int keycode)
{
	printf("START MOVING\n");
}

void Simulation::stopMoving(int keycode)
{
	printf("STOP MOVING\n");
}

void Simulation::refresh(void)
{
	printf("REFRESH\n");
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