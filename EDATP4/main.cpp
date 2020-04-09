#include <stdio.h>
#include <iostream>
#include "Prototypes.h"
#include "EventGen.h"
#include "Simulation.h"
#include "Graph.h"
#include "Worm.h"

bool initialize(Graph** grapher, EventGen** eventgen);
void deinit(Graph** grapher, EventGen** eventgen);
void dispatch(Evento evento, Simulation* sim, Worm* wormArray, Graph* grapher);

int main(void)
{
	Graph* grapher = NULL;
	EventGen* eventGen = NULL;
	Simulation sim;
	Worm worm[NUMBER_OF_WORMS];

	worm[0] = Worm(ALLEGRO_KEY_UP, ALLEGRO_KEY_LEFT, ALLEGRO_KEY_RIGHT);
	worm[1] = Worm(ALLEGRO_KEY_W, ALLEGRO_KEY_A, ALLEGRO_KEY_D);

	if (!(initialize(&grapher, &eventGen)))
	{
		printf("Error de inicializacion");
		return -1;
	}
	while (sim.running())
	{
		if (eventGen->hayEvento())
		{
			dispatch(eventGen->getEvento(), &sim,worm, grapher);
		}
	}
	deinit(&grapher, &eventGen);
	return 0;
}

bool initialize(Graph** grapher,EventGen ** eventGen)
{
	*grapher = new Graph();
	if (!*grapher)
		return false;
	*eventGen = new EventGen((*grapher)->display);

	if (!(*grapher)->wasGood() || !(*eventGen)->wasGood())
	{
		return false;
	}
	return true;
}

void deinit(Graph** grapher, EventGen** eventgen)
{
	delete *eventgen;
	if (*grapher)
	{
		delete* grapher;
		*grapher = NULL;
	}
}


void dispatch(Evento evento, Simulation* sim, Worm* wormArray, Graph* grapher)
{
		switch (evento.getType())
		{
			case KEY_DOWN:
				sim->startMoving(evento.getKey(),wormArray);		
			break;

			case KEY_UP:
				sim->stopMoving(evento.getKey(),wormArray);
			break;

			case TIMER:
				sim->refresh(wormArray);	
				int j;
				for (j = 0; j < NUMBER_OF_WORMS; j++)
				{
					grapher->printState(wormArray[j].getState(),wormArray[j].getTick(), wormArray[j].getPosX(), wormArray[j].getPosY(), wormArray[j].getDireccion());
				}
				
				sim->startMoving(REFRESH, wormArray);
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
	keyboard.keycode.key 

	return al_getNextEvent(&event.eventQueue);
}

dispatch()
{
	switch(evento)
	case AL_KEY_DOWN :
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
	EVENTO 
	-GRAFICA [ine]	
	-WORMS	//arma mini fsm. usa funciones de grafica dependiendo de su estado anterior y timer
	-SIMULAITION [bren]

*/
