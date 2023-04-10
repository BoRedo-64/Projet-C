#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>

typedef struct
{
	SDL_Surface *sprite;
	SDL_Rect pos;
	SDL_Rect posSprite;
	int vie;
	int score;
	double vitesse, acceleration;
	int direction;
	int up, jumpcap;
	float jumpspeed;
}perso;

void initPerso(perso *p);
void afficherPerso(perso *p, SDL_Surface * fenetre);
void movePerso (perso *p, Uint32 dt);
void animerPerso (perso* p);
void saut (perso* p, SDL_Surface *fenetre);
void freeperso (perso* p);
void deceleration (perso* p, int * decel, SDL_Surface *fenetre);

#endif
