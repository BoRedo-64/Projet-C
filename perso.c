#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_keysym.h>
#include <SDL/SDL_mixer.h>
#include <math.h>
#include "perso.h"


void initPerso(perso *p)
{
	p->sprite = IMG_Load("Resources/sprite.png");
	p->pos.x = 600;
	p->pos.y = 514;
	p->pos.w = 52;
	p->pos.h = 85;
	p->posSprite.x = 0;
	p->posSprite.y = 0;
	p->posSprite.w = 52;
	p->posSprite.h = 85;
	p->vie = 0;
	p->score = 0;
	p->vitesse = 1; 
	p->acceleration = 0;
	p->direction = 0;
	p->up = 0;
	p->jumpcap = 314;
	p->jumpspeed = 15;
}

void afficherPerso(perso *p, SDL_Surface * fenetre)
{
	SDL_BlitSurface(p->sprite,&(p->posSprite),fenetre,&(p->pos));
	SDL_Flip(fenetre); //refrachir la fenetre
}

void movePerso (perso *p, Uint32 dt)
{
	switch (p->direction)
	{
	case 1:
	p->pos.x += ((fabs(p->acceleration / 2)) * (dt * dt) + (p->vitesse * dt));
	p->acceleration += 0.1;
	printf("acceleration: %f\n", fabs(p->acceleration));
	break;
	case 0:
	p->pos.x -= ((fabs(p->acceleration / 2)) * (dt * dt) + (p->vitesse * dt));
	p->acceleration -= 0.1;
	printf("acceleration: %f\n", fabs(p->acceleration));
	break;
	}
	if (p->pos.x>900 && p->direction==1)
	{
		p->pos.x=-2;
	}
	if (p->pos.x<1 && p->direction==0)
	{
		p->pos.x=900;
	}
	if (p->acceleration>20)
	{
		p->acceleration = 20;
	}
	if (p->acceleration<-20)
	{
		p->acceleration = -20;
	}
}

void animerPerso (perso* p)
{
	p->posSprite.y =p->direction * (p->posSprite.h);
  	if (p->posSprite.x == (364 - p->posSprite.w))
	{
        	p->posSprite.x  = 0;
	}
  	else
  	{
		p->posSprite.x  = p->posSprite.x + p->posSprite.w;
	}
}

void saut (perso* p, SDL_Surface *fenetre)
{
	int i;
	if (p->up==0)
	{
		p->up=1;
		for (i=0; i<30; i++)
		{
			printf("jumpspeed: %f\n", p->jumpspeed);
			p->pos.y -= p->jumpspeed;
			p->jumpspeed -= 0.5;
			SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,200,255,255));
			afficherPerso(p, fenetre);
			printf("jumpspeed: %f\n", p->jumpspeed);
			SDL_Delay(10);
		}
		p->jumpspeed=15.5;
		for (i=0; i<31; i++)
		{
			printf("jumpspeed: %f\n", p->jumpspeed);
			p->pos.y += p->jumpspeed;
			p->jumpspeed -= 0.5;
			SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,200,255,255));
			afficherPerso(p, fenetre);
			SDL_Delay(10);
		}
		SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,200,255,255));
		afficherPerso(p, fenetre);
		p->jumpspeed=15;
	}
	p->up=0;
	printf("y: %d\n", p->pos.y);
}
