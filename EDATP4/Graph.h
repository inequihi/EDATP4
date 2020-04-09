#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include "Prototypes.h"
#include <string>

using namespace std;

class Graph
{
public:
	Graph();
	~Graph();
	bool wasGood(void);
	bool AllegroInit(void);
private:
	ALLEGRO_DISPLAY* display;
	ALLEGRO_EVENT_QUEUE* eventqueue;
	ALLEGRO_BITMAP* background;
	ALLEGRO_BITMAP* imJump[CANT_IMAGES_JUMP+1];
	ALLEGRO_BITMAP* imWalk[CANT_IMAGES_JUMP + 1];
	bool all_ok;
	bool createDisplay(void);
	bool loadImages(void);
};

