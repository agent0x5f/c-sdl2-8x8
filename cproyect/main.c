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

			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
			


			SDL_RenderClear(renderer);
			SDL_SetRenderDrawColor(renderer, 0,0,0,255);
			SDL_RenderDrawLine(renderer,100,100,500,500);
				

			struct punto p1 = {50,50};
			dpunto(renderer,p1,cyan);	
			struct punto p2 = {100,100};
			dpunto(renderer,p2,magenta);	
			struct punto p3 = {150,150};
			dpunto(renderer,p3,yellow);	

			SDL_RenderPresent(renderer);
		}
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
