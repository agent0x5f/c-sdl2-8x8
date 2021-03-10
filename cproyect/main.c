#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "base.c"
//main logic loop
int main(int argv, char** args)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window *window = SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, 0);
	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Event event;
	bool quit=false;

	while (quit == false)
	{
		while (SDL_PollEvent(&event))
		{
			if(event.type == SDL_KEYDOWN)
				quit = true;	

			
			SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
			SDL_RenderClear(renderer);
			
			
			struct punto p1 = {50,50};
			struct punto p2 = {100,50};	
			struct punto p3 = {180,80};
			struct punto p5 = {1200,700};
			dpunto(renderer,p5,yellow);	
			struct punto p4 = {300,200};
			dlinea(renderer,p1,p5,white);
			drectangulop(renderer,p1,p4,green);
			drectangulom(renderer,p3,200,100,magenta);

			SDL_RenderPresent(renderer);
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
