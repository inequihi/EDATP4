#ifndef SIMULATION_H
#define SIMULATION_H

#include <stdio.h>	///Incluyo solo para debug
#include "Prototypes.h"
#include "Worm.h"

class Simulation : public Worm
{
public:
	Simulation();
	void startMoving(int, Worm*);
	void stopMoving(int, Worm*);
	void refresh(Worm*);
	void quit(void);
	bool running(void);
private:
	bool continueRunning;
};

#endif //SIMULATION_H