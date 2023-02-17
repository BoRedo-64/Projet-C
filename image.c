#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include "struct.h"

void background (SDL_Surface *fenetre)
{
	//Creer le background
	SDL_Surface *bg;
	bg = IMG_Load("Resources/background.png");
	SDL_Rect bgPos;
	bgPos.x=-1;
	bgPos.y=-1;
	SDL_BlitSurface(bg,NULL,fenetre,&bgPos);
}

void logo (SDL_Surface *fenetre)
{
	//Creer le logo du jeu
	SDL_Surface *logo;
	logo = IMG_Load("Resources/gamelogo.png");
	SDL_Rect logoPos;
	logoPos.x=450-(logo->w)/2;
	logoPos.y=40;
	SDL_BlitSurface(logo,NULL,fenetre,&logoPos);
}

void play (SDL_Surface *fenetre)
{
	//Creer boutton play
	SDL_Surface *bp;
	bp = IMG_Load("Resources/buttonplay.png");
	SDL_Rect bpPos;
	bpPos.x=426-(bp->w)/2;
	bpPos.y=200;
	SDL_BlitSurface(bp,NULL,fenetre,&bpPos);
}

void playhover (SDL_Surface *fenetre)
{
	//Creer boutton play
	SDL_Surface *bph;
	bph = IMG_Load("Resources/buttonplayhover.png");
	SDL_Rect bphPos;
	bphPos.x=426-(bph->w)/2;
	bphPos.y=200;
	SDL_BlitSurface(bph,NULL,fenetre,&bphPos);
}

void options (SDL_Surface *fenetre)
{
	//Creer boutton options
	SDL_Surface *bo;
	bo = IMG_Load("Resources/buttonoptions.png");
	SDL_Rect boPos;
	boPos.x=474-(bo->w)/2;
	boPos.y=280;
	SDL_BlitSurface(bo,NULL,fenetre,&boPos);
}

void optionshover (SDL_Surface *fenetre)
{
	//Creer boutton options
	SDL_Surface *boh;
	boh = IMG_Load("Resources/buttonoptionshover.png");
	SDL_Rect bohPos;
	bohPos.x=474-(boh->w)/2;
	bohPos.y=280;
	SDL_BlitSurface(boh,NULL,fenetre,&bohPos);
}

void credits (SDL_Surface *fenetre)
{
	//Creer boutton credits
	SDL_Surface *bc;
	bc = IMG_Load("Resources/buttoncredits.png");
	SDL_Rect bcPos;
	bcPos.x=426-(bc->w)/2;
	bcPos.y=360;
	SDL_BlitSurface(bc,NULL,fenetre,&bcPos);
}

void creditshover (SDL_Surface *fenetre)
{
	//Creer boutton credits
	SDL_Surface *bch;
	bch = IMG_Load("Resources/buttoncreditshover.png");
	SDL_Rect bchPos;
	bchPos.x=426-(bch->w)/2;
	bchPos.y=360;
	SDL_BlitSurface(bch,NULL,fenetre,&bchPos);
}

void quit (SDL_Surface *fenetre)
{
	//Creer boutton quit
	SDL_Surface *bq;
	bq = IMG_Load("Resources/buttonquit.png");
	SDL_Rect bqPos;
	bqPos.x=474-(bq->w)/2;
	bqPos.y=440;
	SDL_BlitSurface(bq,NULL,fenetre,&bqPos);
}

void quithover (SDL_Surface *fenetre)
{
	//Creer boutton quit
	SDL_Surface *bqh;
	bqh = IMG_Load("Resources/buttonquithover.png");
	SDL_Rect bqhPos;
	bqhPos.x=474-(bqh->w)/2;
	bqhPos.y=440;
	SDL_BlitSurface(bqh,NULL,fenetre,&bqhPos);
}

void titreoption (SDL_Surface *fenetre)
{
	//Creer boutton quit
	SDL_Surface *to;
	to = IMG_Load("Resources/menuoptions.png");
	SDL_Rect toPos;
	toPos.x=450-(to->w)/2;
	toPos.y=10;
	SDL_BlitSurface(to,NULL,fenetre,&toPos);
	
	SDL_Surface *w;
	w = IMG_Load("Resources/window.png");
	SDL_Rect wPos;
	wPos.x=20;
	wPos.y=80;
	SDL_BlitSurface(w,NULL,fenetre,&wPos);
}

void resolution (SDL_Surface *fenetre)
{
	//Creer bouton quit
	SDL_Surface *br;
	br = IMG_Load("Resources/buttonresolution.png");
	SDL_Rect brPos;
	brPos.x=450-(br->w)/2;
	brPos.y=170+(br->h);
	SDL_BlitSurface(br,NULL,fenetre,&brPos);
	SDL_Flip(fenetre); //refrachir la fenetre
}

void brightness (SDL_Surface *fenetre)
{
	//Creer bouton quit
	SDL_Surface *bb;
	bb = IMG_Load("Resources/buttonbrightness.png");
	SDL_Rect bbPos;
	bbPos.x=450-(bb->w)/2;
	bbPos.y=274+(bb->h);
	SDL_BlitSurface(bb,NULL,fenetre,&bbPos);

}

void quitoptions (SDL_Surface *fenetre)
{
	//Creer bouton quit
	SDL_Surface *qo;
	qo = IMG_Load("Resources/quitoptions.png");
	SDL_Rect qoPos;
	qoPos.x=450-(qo->w)/2;
	qoPos.y=590-(qo->h);
	SDL_BlitSurface(qo,NULL,fenetre,&qoPos);
}

void quitoptionshover (SDL_Surface *fenetre)
{
	//Creer bouton quit
	SDL_Surface *qoh;
	qoh = IMG_Load("Resources/quitoptionshover.png");
	SDL_Rect qohPos;
	qohPos.x=450-(qoh->w)/2;
	qohPos.y=590-(qoh->h);
	SDL_BlitSurface(qoh,NULL,fenetre,&qohPos);
}

void volume (SDL_Surface *fenetre, int *vol)
{
	SDL_Surface *v1,*v2,*v3,*v4,*v5;
	v1 = IMG_Load("Resources/volume1.png");
	v2 = IMG_Load("Resources/volume2.png");
	v3 = IMG_Load("Resources/volume3.png");
	v4 = IMG_Load("Resources/volume4.png");
	v5 = IMG_Load("Resources/volume5.png");
	SDL_Rect Pos;
	Pos.x=23;
	Pos.y=40;
	switch (*vol)
	{	
		case 0:
			SDL_BlitSurface(v1,NULL,fenetre,&Pos);
			break;
		case 32:
			SDL_BlitSurface(v2,NULL,fenetre,&Pos);
			break;
		case 64:
			SDL_BlitSurface(v3,NULL,fenetre,&Pos);
			break;
		case 96:
			SDL_BlitSurface(v4,NULL,fenetre,&Pos);
			break;

		case 128:
			SDL_BlitSurface(v5,NULL,fenetre,&Pos);
			break;
	}
	SDL_Flip(fenetre);
}

void menuoption (SDL_Surface *fenetre, int *choix, int *once,  int *vol)
{
	SDL_Event event;
	int x,y,l=1;
	Mix_Chunk *hovermusic = Mix_LoadWAV("Resources/slash.wav");
	int Mix_VolumeChunk(Mix_Chunk *hovermusic, int volume);
	background (fenetre);
	titreoption (fenetre);
	quitoptions (fenetre);
	volume (fenetre,vol);
	while (l)
	{	
		SDL_PollEvent(&event);
		switch (event.type)
		{
			case (SDL_QUIT):
				l=0;
				break;
		
			case (SDL_KEYDOWN):
				switch (event.key.keysym.sym)
				{
					case (SDLK_ESCAPE):
							l=0;
							break;
					case (SDLK_f):
							break;
					case (SDLK_w):
							break;
					case (SDLK_LEFT):
							*vol -= MIX_MAX_VOLUME / 4;
							if (*vol<0)
							{
								*vol = 0;
							}
							Mix_Volume(-1, *vol);
							background (fenetre);
							titreoption (fenetre);
							quitoptions (fenetre);
							volume (fenetre,vol);
							Mix_PlayChannel(-1, hovermusic, 0);
							SDL_Delay(100);
							break;
					case (SDLK_RIGHT):
							*vol += MIX_MAX_VOLUME / 4;
							if (*vol>MIX_MAX_VOLUME)
							{
								*vol = MIX_MAX_VOLUME;
							}
							Mix_Volume(-1, *vol);
							background (fenetre);
							titreoption (fenetre);
							quitoptions (fenetre);
							volume (fenetre,vol);
							Mix_PlayChannel(-1, hovermusic, 0);
							SDL_Delay(100);
							break;
				}
			case (SDL_MOUSEMOTION):
					x = event.motion.x;
					y = event.motion.y;
					if ((370.5<=x && x<=529.5) && (525<=y && y<=590))
					{
						quitoptionshover (fenetre);
						SDL_WaitEvent(&event);
						if (event.type==SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button==SDL_BUTTON_LEFT)
							{
								l=0;
							}
						}
					}
/*
					else if (184<=y && y<=268 && 440<=x && x<=470)
					{
						SDL_WaitEvent(&event);
						if (event.type==SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button==SDL_BUTTON_LEFT)
							{
								*vol = 64;
								Mix_Volume(-1, *vol);
								background (fenetre);
								titreoption (fenetre);
								quitoptions (fenetre);
								volume (fenetre,vol);
								Mix_PlayChannel(-1, hovermusic, 0);
							}
						}
					}
					else if (184<=y && y<=268 && 244<=x && x<=274)
					{
						SDL_WaitEvent(&event);
						if (event.type==SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button==SDL_BUTTON_LEFT)
							{
								*vol = 0;
								Mix_Volume(-1, *vol);
								background (fenetre);
								titreoption (fenetre);
								quitoptions (fenetre);
								volume (fenetre,vol);
								Mix_PlayChannel(-1, hovermusic, 0);
							}
						}
					}
					else if (184<=y && y<=268 && 274<=x && x<=304)
					{
						SDL_WaitEvent(&event);
						if (event.type==SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button==SDL_BUTTON_LEFT)
							{
								*vol = 32;
								Mix_Volume(-1, *vol);
								background (fenetre);
								titreoption (fenetre);
								quitoptions (fenetre);
								volume (fenetre,vol);
								Mix_PlayChannel(-1, hovermusic, 0);
							}
						}
					}
*/
					else
					{
						quitoptions (fenetre);
					}
					break;

			}

	SDL_Flip(fenetre);
	}
	*choix = 0;
	*once = 1;
}
