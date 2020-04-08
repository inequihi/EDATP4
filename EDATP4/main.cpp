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
