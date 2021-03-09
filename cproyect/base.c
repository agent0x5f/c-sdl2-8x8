#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

/*
TODO: punto, linea, rectangulo. read  y write mapp, mouse click, ui...
punto hecho!!
*/

struct punto
{
    int x;
    int y;
};

struct color
{
    int red;
    int green;
    int blue;
    int alpha;
};
struct color color1 = { 0,0,0,255 };
struct color color2 = { 0,0,255,255 };

int dpunto(SDL_Renderer* render,struct punto p,struct color c){
    SDL_SetRenderDrawColor(render,c.red,c.green,c.blue,c.alpha);
    SDL_RenderDrawPoint(render,p.x,p.y);
}
int dlinea();
int drectangulo();
int cargarbmap();
int guardarbmap();




