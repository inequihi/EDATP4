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

void Graph::destroy()
{
	if (background)
		al_destroy_bitmap(background);	
	if(display)
		al_destroy_display(display);
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
							if (al_init_primitives_addon())
							{
								return true;
							}
							else
								printf("ERROR al_init_primitives_addon");
						}
						else
							printf("ERROR al_instal_keyboard\n");
					}
					else
						printf("ERROR al_install_mouse\n");
				}
				else
					printf("ERROR load Images\n");
			}
			else
				printf("ERROR create display\n");
		}
		else
			printf("ERROR al_init_image_addon\n");
	}
	else
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
	if (!(background = al_load_bitmap("jardin.png")))				//Cambiemos este fondo o editemos el otro
																		//Pasa q Scenario no tiene fondo y cuando se imprime devuelta no despaarecen los worms
	{
		printf("ERROR loading background");
		return false;
	}
	al_draw_bitmap(background, 0, 0, 0);

	//Cargamos las imagenes de salto
	string str = "wjump\\wjump-F";
	string direccion;
	for (int i = 0; i < CANT_IMAGES_JUMP; i++)
	{
		direccion = str + to_string(i+1) + ".png";
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
	for (int i = 0; i < CANT_IMAGES_WALK; i++)
	{
		completeDireccion = direct + to_string(i+1) + ".png";
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

void Graph::printState(int state_flag, int tick, double pos_X, double pos_Y, int direccion)
{
	int flag = checkOrientacion(direccion);
	switch (state_flag)
	{
	case STILL_G:
		al_draw_bitmap(imWalk[tick], pos_X, pos_Y, flag);			//si esta quieto tick seria cero
		break;

	case JUMPING_G:
		al_draw_bitmap(imJump[tick], pos_X, pos_Y, flag);			
		break;

	case WALKING_G:
		al_draw_bitmap(imWalk[tick], pos_X, pos_Y, flag);			
		break;

	case PREMOVE_G:
		al_draw_bitmap(imWalk[tick], pos_X, pos_Y, flag);			//si esta en premove tick seria cero
		break;
	default:
		break;
	}

}

int Graph::checkOrientacion(int direccion)
{
	if (direccion > 0)		//si va para la derecha
	{
		return ALLEGRO_FLIP_HORIZONTAL;
	}
	else
		return 0;
}