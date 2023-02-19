#ifndef STRUCT_H_
#define STRUCT_H_
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_ttf.h>
#define SCREEN_H 600
#define SCREEN_W 900

typedef struct 
{
char *url;
SDL_Rect pos_img_affiche;
    SDL_Rect pos_img_ecran;
SDL_Surface *img;
} image;

typedef struct 
{
SDL_Surface *txt;
SDL_Rect pos_txt;
SDL_Colour color_txt;
TTF_Font *police;
} texte;

void background (fenetre);
void text (fenetre);
void logo (fenetre);
void play (fenetre);
void playhover (fenetre);
void options(fenetre);
void optionshover(fenetre);
void credits(fenetre);
void creditshover(fenetre);
void quit(fenetre);
void quithover(fenetre);
void titreoption (fenetre);
void volume (fenetre,vol,vol2);
void quitoptions (fenetre);
void quitoptionshover (fenetre);
void fullscreen (fenetre,full);
void menuoption(fenetre,choix,volume,volume2,full);

#endif

