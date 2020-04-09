#include "Evento.h"

Evento::Evento()
{
	type = 0;
}

void Evento::setType(int type)
{
	this->type = type;
}

void Evento::setKeycode(int keycode)
{
	this->keycode = keycode;
}

int Evento::getKey(void)
{
	return keycode;
}

int Evento::getType(void)
{
	return type;
}