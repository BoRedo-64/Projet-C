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
	p->sprite = IMG_Load("Resources/sprite2.png");
	p->pos.x = 10;
	p->pos.y = 500;
	p->pos.w = 52;
	p->pos.h = 85;
	p->posSprite.x = 0;
	p->posSprite.y = 0;
	p->posSprite.w = 52;
	p->posSprite.h = 85;
	p->vie = 0;
	p->score = 0;
	p->vitesse = 0; 
	p->acceleration = 2;
	p->direction = 1;
	p->up = 0;
	p->jumpcap = 400;
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
		p->pos.x += (p->acceleration / 2) * (dt * dt) + (p->vitesse * dt)+1;
		p->acceleration += 0.01;
		printf("acceleration: %f\n", (p->acceleration));
		break;
		case 0:
		p->pos.x -= (p->acceleration / 2) * (dt * dt) + (p->vitesse * dt);
		p->acceleration += 0.01;
		printf("acceleration: %f\n", (p->acceleration));
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
	if (p->acceleration>10)
	{
		p->acceleration = 10;
	}
	if (p->acceleration<-10)
	{
		p->acceleration = -10;
	}
}

void animerPerso (perso* p)
{
	p->posSprite.y =p->direction * (p->posSprite.h);
  	if (p->posSprite.x == (572 - p->posSprite.w))
	{
        	p->posSprite.x  = 0;
	}
  	else
  	{
		p->posSprite.x  = p->posSprite.x + p->posSprite.w;
	}
	SDL_Delay(20);
}

void saut (perso* p, SDL_Surface *fenetre)
{
/*
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
*/
	
	int a,c,x,y;
	a=3;
	c=5;
	x=1;
	y=p->pos.y;
	if (p->direction==1)
	{
		while (y>p->jumpcap)
		{
			y=y-(a*x+c);
			x+=2;
			p->pos.x += x+1;
			p->pos.y = y;
			SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,200,255,255));
			afficherPerso(p, fenetre);
			SDL_Flip(fenetre);
			SDL_Delay(45);
		}
		x+=4;
		p->pos.x += x;
		SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,200,255,255));
		afficherPerso(p, fenetre);
		SDL_Flip(fenetre);
		SDL_Delay(45);
		x=1;
		while (y<500)
		{
			y=y+(a*x+c);
			x+=2;
			p->pos.x += x+1;
			p->pos.y = y;
			SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,200,255,255));
			afficherPerso(p, fenetre);
			SDL_Flip(fenetre);
			SDL_Delay(45);
		}
	}
	else
	{
		while (y>p->jumpcap)
		{
			y=y-(a*x+c);
			x+=2;
			p->pos.x -= x;
			p->pos.y = y;
			SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,200,255,255));
			afficherPerso(p, fenetre);
			SDL_Flip(fenetre);
			SDL_Delay(45);
		}
		x+=4;
		p->pos.x -= x;
		SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,200,255,255));
		afficherPerso(p, fenetre);
		SDL_Flip(fenetre);
		SDL_Delay(45);
		x=1;
		x=1;
		while (y<500)
		{
			y=y+(a*x+c);
			x+=2;
			p->pos.x -= x;
			p->pos.y = y;
			SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,200,255,255));
			afficherPerso(p, fenetre);
			SDL_Flip(fenetre);
			SDL_Delay(45);
		}
	}
	
}

void freeperso (perso* p)
{
	free (p);
}

void deceleration (perso* p, int * decel, SDL_Surface *fenetre)
{
	while (decel)
	{
		if (p->acceleration>2)
		{
			p->acceleration -= 0.5;
			if (p->direction == 1)
			{
				p->pos.x += p->acceleration / 2;
			}
			else
			{
				p->pos.x -= p->acceleration / 2;
			}
			SDL_FillRect(fenetre,NULL,SDL_MapRGB(fenetre->format,200,255,255));
			animerPerso (p);
			afficherPerso(p, fenetre);
		}
		else
		{
			decel = 0;
		}
	}		
}

