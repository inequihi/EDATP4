#include <stdio.h>
#include <iostream>
#include "Prototypes.h"
#include "EventGen.h"
#include "Simulation.h"
#include "Graph.h"
#include "Worm.h"

using namespace std;

bool initialize(Graph** grapher, EventGen** eventgen);
void deinit(Graph* grapher, EventGen* eventgen);
void dispatch(Evento evento, Simulation* sim);

int main(void)
{
	Graph* grapher = NULL;
	EventGen* eventgen = NULL;
	Simulation sim;
	Worm worm[NUMBER_OF_WORMS];


	if (!initialize(&grapher, &eventgen))
	{
		printf("Error de inicializacion");
		return -1;
	}
	while (sim.running())
	{
		if ((*eventgen).hayEvento())
		{
			dispatch((*eventgen).getEvento(), &sim);
		}
	}
	deinit(grapher, eventgen);
	return 0;
}

bool initialize(Graph** grapher,EventGen ** eventgen)
{
	*grapher = new Graph();
	*eventgen = new EventGen();
	if (!(*(*grapher)).wasGood() || !(*(*eventgen)).wasGood())
	{
		return false;
	}
	return true;
}

void deinit(Graph* grapher, EventGen* eventgen)
{
	delete grapher;
	delete eventgen;
}


void dispatch(Evento evento, Simulation* sim)
{
		switch (evento.getType())
		{
			case KEY_DOWN:
				sim->startMoving(evento.getKey());		
			break;

			case KEY_UP:
				sim->stopMoving(evento.getKey());
			break;

			case TIMER:
				sim->refresh();				
			break;

			case CLOSE:
				sim->quit();
			break;
		}
}






















/*notas de la clase*/

/*
init();
while(simulation.running())
{
	if(eventGen.hayEvento())
	{
		dispatch(eventGen.getEvento(),simulation);
	}

}
deinit();

hayEvento()
{
	return al_getNextEvent(&event.eventQueue);
}

dispatch()
{
	switch(evento)
	case AL_KEY_DOWN:
		simulate.StartMoving(evento.getkey());		//clase evento
		break;

	case AL_KEY_UP:
		simulate.stopMoving(evento.getKey());
		break;

	case ALLEGRO_TIMER:
		simulate.refresh();				//aca guardo timer. despende del estado del worm actualizo movimienot
		break;

	case ALLEGROQUIT?
		simulate.Quit(event.getKey());
		break;

}

Simulation::startMoving(int )
{
	//tengo que primero ver que paso el tiempo, el tiempo es inherente a cada worm
	for(i=0 < i<wormsArr.count() ; i++)
		wormsArr[i].move(key);	

	//donde acumulo tiempo para saber que tengo que seguir moviendo poruqe no 
	//llego ningun key up: (como cuento esos 5 frames) 
		// --> a cada 20ms se llama a refresh, a la quintaq vexz q llaman me muevo (cambio mi estado) 
		//armar mini fsm en cada worm

	//tiempo empieza a contarse cuando recibis keydown. 

}


que worm herede de clase graphic.

CLASES:
	-EVENTO
	-GRAFICA	
	-WORMS	//arma mini fsm. usa funciones de grafica dependiendo de su estado anterior y timer
	-SIMULAITION

*/
