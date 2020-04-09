#include "Simulation.h"

Simulation::Simulation()
{
	continueRunning = true;
}

void Simulation::startMoving(int keycode)
{

}

void Simulation::stopMoving(int keycode)
{

}

void Simulation::refresh(void)
{

}

void Simulation::quit(void)
{
	continueRunning = false;
}

bool Simulation::running(void)
{
	return continueRunning;
}