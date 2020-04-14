#ifndef SIMULATION_H
#define SIMULATION_H

#include "Prototypes.h"
#include "Worm.h"
#include "Graph.h"

class Simulation : public Worm
{
public:
	Simulation();
	void startMoving(int, Worm*);
	void stopMoving(int, Worm*);
	void refresh(Worm*, Graph*);
	void quit(void);
	bool running(void);
private:
	bool continueRunning;
};

#endif //SIMULATION_H