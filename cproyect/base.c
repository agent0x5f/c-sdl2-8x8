#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define LARGO_VENTANA 1280
#define ALTO_VENTANA 720 

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


int setcolor(SDL_Renderer* render, struct color c){
    SDL_SetRenderDrawColor(render,c.red,c.green,c.blue,c.alpha);
    return 0;
}

int dpunto(SDL_Renderer* render,struct punto p,struct color c){
    setcolor(render,c);
    SDL_RenderDrawPoint(render,p.x,p.y);
    return 0;
}

int dlinea(SDL_Renderer* render,struct punto p1,struct punto p2,struct color c){
    setcolor(render,c);
    SDL_RenderDrawLine(render,p1.x,p1.y,p2.x,p2.y);
    return 0;
}

//p1 es arriba izq, p2 es abajo derecha.
int drectangulop(SDL_Renderer* render,struct punto p1,struct punto p2,struct color c){
    setcolor(render,c);
    SDL_RenderDrawLine(render,p1.x,p1.y,p2.x,p1.y);
    SDL_RenderDrawLine(render,p1.x,p1.y,p1.x,p2.y);
    SDL_RenderDrawLine(render,p1.x,p2.y,p2.x,p2.y);
    SDL_RenderDrawLine(render,p2.x,p2.y,p2.x,p1.y);
    return 0;
}

int drectangulom(SDL_Renderer* render,struct punto p1,int largo,int alto,struct color c){
    setcolor(render,c);
    SDL_RenderDrawLine(render,p1.x,p1.y,p1.x+largo,p1.y);
    SDL_RenderDrawLine(render,p1.x,p1.y,p1.x,p1.y+alto);
    SDL_RenderDrawLine(render,p1.x,p1.y+alto,p1.x+largo,p1.y+alto);
    SDL_RenderDrawLine(render,p1.x+largo,p1.y+alto,p1.x+largo,p1.y);
    return 0;
}

int hacer_fondo(SDL_Renderer* render, struct color c){
    SDL_SetRenderDrawColor(render, c.red,c.green,c.blue,c.alpha);
	SDL_RenderClear(render);
    return 0;
}

int hacer_cuadro(SDL_Renderer* render, struct color c){
    struct punto origen = {0,0};
    drectangulom(render,origen,10,ALTO_VENTANA,c);
    drectangulom(render,origen,LARGO_VENTANA,10,c);
    struct punto esquina = {LARGO_VENTANA,ALTO_VENTANA};
    drectangulom(render,esquina,-10,-ALTO_VENTANA,c);
    drectangulom(render,esquina,-LARGO_VENTANA,-10,c);
    return 0;
}

int hacer_ui(SDL_Renderer* render){
    struct color c = {128,128,128,255};
    hacer_fondo(render,c);
    hacer_cuadro(render,blue);
    return 0;
}

int dibuja(SDL_Renderer* render){
    SDL_RenderPresent(render);
    return 0;
}

int cargarbmap();
int guardarbmap();




