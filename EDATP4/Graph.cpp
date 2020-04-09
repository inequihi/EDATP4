#include "Graph.h"

Graph::Graph()
{
	display = NULL;
	eventqueue = NULL;
	all_ok = true;
	
	if (!AllegroInit())
	{
		all_ok = false;
	}
}

Graph::~Graph()
{
	if (display)
		al_destroy_display(display);	
	if (background)
		al_destroy_bitmap(background);	
	al_uninstall_keyboard();
}

bool Graph::wasGood(void)
{
	return all_ok;
}


bool Graph::AllegroInit()
{
	if(al_init())
	{
		if (al_init_image_addon())
		{
			if (createDisplay())
			{
				if (loadImages())
				{
					if (al_install_mouse())
					{
						if (al_install_keyboard())
						{
							return true;
						}else
							printf("ERROR al_instal_keyboard\n");
					}else
						printf("ERROR al_install_mouse\n");
				}else
					printf("ERROR load Images\n");
			}else
				printf("ERROR create display\n");
		}else
			printf("ERROR al_init_image_addon\n");
	}else
		printf("ERROR al_init\n");
	return false;

}

bool Graph::createDisplay(void)
{
	display = al_create_display(SIZE_SCREEN_X, SIZE_SCREEN_Y);
	if(!display)
		return false;
	return true;
}

bool Graph::loadImages(void)
{
	//Cargamos el fondo
	if (!(background = al_load_bitmap("jardin.jpg")))
	{
		printf("ERROR loading background");
		return false;
	}
	al_draw_bitmap(background, 0, 0, 0);

	//Cargamos las imagenes de salto
	string str = "wjump\\wjump-F";
	string direccion;
	for (int i = 1; i <= CANT_IMAGES_JUMP; i++)
	{
		direccion = str + to_string(i) + ".png";
		imJump[i] = al_load_bitmap(direccion.c_str());
		if (!imJump[i])
		{
			printf("ERROR loading jumping bitmaps\n");
			return false;
		}
	}

	//Cargamos las imagenes de caminata
	string direct = "wwalking\\wwalk-F";
	string completeDireccion;
	for (int i = 1; i <= CANT_IMAGES_WALK; i++)
	{
		completeDireccion = direct + to_string(i) + ".png";
		imWalk[i] = al_load_bitmap(completeDireccion.c_str());
		if (!imWalk[i])
		{
			printf("ERROR loading moving bitmap");
			return false;
		}
	}
	al_flip_display();
	return true;
}