#include "EventGen.h"

EventGen::EventGen(ALLEGRO_DISPLAY* display)
{
	event_queue = NULL;
	timer = NULL;
	ev_ok = true;
	event_queue = al_create_event_queue();
	timer = al_create_timer(1.0 / FPS);
	if (!event_queue || !timer)				//elimino !al_install_keyboard() de la ocndicion para q esto se haga en graph class init
	{
		ev_ok = false;
		printf("ERROR with event_queue || timer\n");
	}
	else
	{
		al_register_event_source(event_queue, al_get_display_event_source(display));
		al_register_event_source(event_queue, al_get_timer_event_source(timer));
		al_register_event_source(event_queue, al_get_keyboard_event_source());
		al_register_event_source(event_queue, al_get_mouse_event_source());
		al_start_timer(timer);  //revisar si se pone aca o donde se pondria
	}
}

EventGen::~EventGen()
{
	if (event_queue)
	{
		al_destroy_event_queue(event_queue);
		event_queue = NULL;
	}
		
	if (timer)
	{
		al_destroy_timer(timer);
		timer = NULL;
	}
				
}

bool EventGen::hayEvento()
{
	return !al_is_event_queue_empty(event_queue);
}

Evento EventGen::getEvento()
{
	ALLEGRO_EVENT ev;
	al_get_next_event(event_queue, &ev);
	switch (ev.type)
	{
	case ALLEGRO_EVENT_KEY_DOWN:
		evento.setType(KEY_DOWN);
		evento.setKeycode(ev.keyboard.keycode);
		break;
	case ALLEGRO_EVENT_KEY_UP:
		evento.setType(KEY_UP);
		evento.setKeycode(ev.keyboard.keycode);
		break;
	case ALLEGRO_EVENT_TIMER:
		evento.setType(TIMER);
		break;
	case ALLEGRO_EVENT_DISPLAY_CLOSE:
		evento.setType(CLOSE);
		break;
	}
	return evento;
}


bool EventGen::wasGood(void)
{
	return ev_ok;
}