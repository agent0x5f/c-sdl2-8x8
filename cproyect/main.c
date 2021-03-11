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

	while (quit == false)
	{
		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_KEYDOWN)
				quit = true;	

			
			hacer_ui(canvas);
			
			
			struct punto p1 = {50,50};
			struct punto p2 = {100,50};	
			struct punto p3 = {180,80};
			struct punto p5 = {1200,700};
			dpunto(canvas,p5,yellow);	
			struct punto p4 = {300,200};
			dlinea(canvas,p1,p5,white);
			drectangulop(canvas,p1,p4,green);
			drectangulom(canvas,p3,200,100,magenta);

			drectangulo(canvas,p4,200,100,green);
			

			dibuja(canvas);
		}
	}

	SDL_DestroyRenderer(canvas);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
