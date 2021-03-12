#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "base.c"

#define LARGO_VENTANA 1280
#define ALTO_VENTANA 720 

//main logic loop
int main(int argv, char** args)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, LARGO_VENTANA, ALTO_VENTANA, 0);
	SDL_Renderer *canvas = SDL_CreateRenderer(window, -1, 0);
	SDL_Event event;
	bool quit=false;
	int click=0;

	while (quit == false)
	{
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_KEYDOWN: 
			if(event.key.keysym.sym == SDLK_RETURN)
					{quit = true;} 
			break;

			case SDL_MOUSEBUTTONDOWN: 
			click=1;
			break;
			
			default:
				break;
			}

			hacer_ui(canvas,click);
			dibuja(canvas);
		}
	}

	SDL_DestroyRenderer(canvas);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
