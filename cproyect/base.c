#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define LARGO_VENTANA 1280
#define ALTO_VENTANA 720 

/*
TODO: punto, linea, rectangulo. read  y write mapp, mouse click, ui...
punto hecho!!
primitivas de dibujo
basicos componentes de ui
letras y colores
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

int drectangulo(SDL_Renderer* render,struct punto p1,int largo, int alto,struct color c){
    setcolor(render,c);
    SDL_Rect aux = {p1.x,p1.y,largo,alto};
    SDL_RenderFillRect(render,&aux);
    return 0;
}

int hacer_fondo(SDL_Renderer* render, struct color c){
    SDL_SetRenderDrawColor(render, c.red,c.green,c.blue,c.alpha);
	SDL_RenderClear(render);
    return 0;
}

int hacer_cuadro(SDL_Renderer* render, struct color c){
    struct punto origen = {0,0};
    const margen = 5;
    drectangulo(render,origen,margen,ALTO_VENTANA,c);
    drectangulo(render,origen,LARGO_VENTANA,margen,c);
    struct punto esquina = {LARGO_VENTANA,ALTO_VENTANA};
    drectangulo(render,esquina,-margen,-ALTO_VENTANA,c);
    drectangulo(render,esquina,-LARGO_VENTANA,-margen,c);
    struct punto sep = {margen+100,0};
    drectangulo(render,sep,margen,ALTO_VENTANA,c);
    struct punto seph = {0,50};
    drectangulo(render,seph,LARGO_VENTANA,margen,c);
    seph.y = seph.y+50;
    while(seph.y<ALTO_VENTANA){
        drectangulo(render,seph,100+margen,margen,c);
        seph.y = seph.y+50;
    }
    return 0;
}

int hacer_8x8(SDL_Renderer* render){
    struct punto origen = {150,100};
    struct punto final = {550,100};
    //ejes horizontales
    for(int x=0;x<=8;x++)
    {
        dlinea(render,origen,final,black);
        origen.y += 50;
        final.y += 50;
    }

    struct punto origenv = {150,100};
    struct punto finalv = {150,500};
    //ejes verticales
    for(int x=0;x<=8;x++)
    {
        dlinea(render,origenv,finalv,black);
        origenv.x += 50;
        finalv.x += 50;
    }
    return 0;
}

int hacer_ui(SDL_Renderer* render){
    struct color c = {128,128,128,255};
    hacer_fondo(render,c);
    hacer_cuadro(render,blue);
    hacer_8x8(render);
    return 0;
}

int dibuja(SDL_Renderer* render){
    SDL_RenderPresent(render);
    return 0;
}

int cargarbmap();
int guardarbmap();




