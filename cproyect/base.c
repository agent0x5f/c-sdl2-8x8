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

//3bit colors in rgb.
struct color black = { 0,0,0,255 };
struct color white = { 255,255,255,255 };
struct color red = { 255,0,0,255 };
struct color green = { 0,255,0,255 };
struct color blue = { 0,0,255,255 };
struct color cyan = { 0,255,255,255 };
struct color magenta = { 229,9,127,255 };
struct color yellow = { 255,255,0,255 };



int dpunto(SDL_Renderer* render,struct punto p,struct color c){
    SDL_SetRenderDrawColor(render,c.red,c.green,c.blue,c.alpha);
    SDL_RenderDrawPoint(render,p.x,p.y);
}
int dlinea();
int drectangulo();
int cargarbmap();
int guardarbmap();




