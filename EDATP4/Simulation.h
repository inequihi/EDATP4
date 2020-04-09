#pragma once

#include <stdio.h>	///Incluyo solo para debug

class Simulation
{
public:
	Simulation();
	void startMoving(int);
	void stopMoving(int);
	void refresh(void);
	void quit(void);
	bool running(void);
private:
	bool continueRunning;
};