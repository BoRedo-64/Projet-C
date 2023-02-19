#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include "struct.h"

void background (SDL_Surface *fenetre)
{
	//Creer le background
	SDL_Surface *bg;
	SDL_Rect bgPos;
	bgPos.x=0;
	bgPos.y=0;

	if ((SDL_GetTicks()/1000)%4==0 && (SDL_GetTicks()/1000)!=0)
	{
		bg = IMG_Load("Resources/background2.png");
		SDL_BlitSurface(bg,NULL,fenetre,&bgPos);
	}
	else
	{
		bg = IMG_Load("Resources/background.png");
		SDL_BlitSurface(bg,NULL,fenetre,&bgPos);
	}

}

void logo (SDL_Surface *fenetre)
{
	//Creer le logo du jeu
	SDL_Surface *logo;
	logo = IMG_Load("Resources/gamelogo.png");
	SDL_Rect logoPos;
	logoPos.x=450-(logo->w)/2;
	logoPos.y=60;
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
	bqPos.y=450;
	SDL_BlitSurface(bq,NULL,fenetre,&bqPos);
}

void quithover (SDL_Surface *fenetre)
{
	//Creer boutton quit
	SDL_Surface *bqh;
	bqh = IMG_Load("Resources/buttonquithover.png");
	SDL_Rect bqhPos;
	bqhPos.x=474-(bqh->w)/2;
	bqhPos.y=450;
	SDL_BlitSurface(bqh,NULL,fenetre,&bqhPos);
}

void titreoption (SDL_Surface *fenetre)
{
	//Creer boutton quit
	SDL_Surface *to;
	to = IMG_Load("Resources/menuoptions.png");
	SDL_Rect toPos;
	toPos.x=450-(to->w)/2;
	toPos.y=30;
	SDL_BlitSurface(to,NULL,fenetre,&toPos);
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

void volume (SDL_Surface *fenetre, int *vol, int *vol2)
{
	SDL_Surface *v1,*v2,*v3,*v4,*v5, *music, *sound;
	v1 = IMG_Load("Resources/volume1.png");
	v2 = IMG_Load("Resources/volume2.png");
	v3 = IMG_Load("Resources/volume3.png");
	v4 = IMG_Load("Resources/volume4.png");
	v5 = IMG_Load("Resources/volume5.png");
	music = IMG_Load("Resources/musicicon.png");
	sound = IMG_Load("Resources/soundicon.png");
	SDL_Rect soundPos;
	soundPos.x=93;
	soundPos.y=150;	
	SDL_Rect musicPos;
	musicPos.x=93;
	musicPos.y=250;
	SDL_Rect Pos;
	Pos.x=83;
	Pos.y=0;
	SDL_Rect Pos2; //
	Pos2.x=83;//
	Pos2.y=100;//
	SDL_BlitSurface(sound,NULL,fenetre,&soundPos);
	SDL_BlitSurface(music,NULL,fenetre,&musicPos);
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
	switch (*vol2)//
	{	
		case 0:
			SDL_BlitSurface(v1,NULL,fenetre,&Pos2);
			break;
		case 32:
			SDL_BlitSurface(v2,NULL,fenetre,&Pos2);
			break;
		case 64:
			SDL_BlitSurface(v3,NULL,fenetre,&Pos2);
			break;
		case 96:
			SDL_BlitSurface(v4,NULL,fenetre,&Pos2);
			break;

		case 128:
			SDL_BlitSurface(v5,NULL,fenetre,&Pos2);
			break;
	}//
	SDL_Flip(fenetre);
}

void fullscreen (SDL_Surface *fenetre,int *full)
{
	SDL_Surface *f;
	f = IMG_Load("Resources/fullscreen.png");
	SDL_Rect fPos;
	fPos.x=100;
	fPos.y=410;

	SDL_BlitSurface(f,NULL,fenetre,&fPos);
	SDL_Surface *fb;
	if (*full)
	{
		fb = IMG_Load("Resources/fbutton.png");
	}
	else
	{
		fb = IMG_Load("Resources/wbutton.png");
	}
	SDL_Rect fbPos;
	fbPos.x=500;
	fbPos.y=405;
	SDL_BlitSurface(fb,NULL,fenetre,&fbPos);
}

void menuoption (SDL_Surface *fenetre, int *choix,  int *vol, int *vol2, int *full)
{
	SDL_Event event;
	int x,y,l=1,refresh=0;
	Mix_Chunk *hovermusic = Mix_LoadWAV("Resources/slash.wav");
	int Mix_VolumeChunk(Mix_Chunk *hovermusic, int volume);
	background (fenetre);
	titreoption (fenetre);
	quitoptions (fenetre);
	volume (fenetre,vol,vol2);
	fullscreen (fenetre, full);
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
							fenetre = SDL_SetVideoMode(0,0,32, SDL_FULLSCREEN | SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
							refresh=1;
							*full=1;
							break;
					case (SDLK_w):
							fenetre = SDL_SetVideoMode(900,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
							*full=0;
							refresh=1;
							break;
					case (SDLK_LEFT):
							*vol -= MIX_MAX_VOLUME / 4;
							if (*vol<0)
							{
								*vol = 0;
							}
							Mix_Volume(-1, *vol);
							refresh=1;
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
							refresh=1;
							Mix_PlayChannel(-1, hovermusic, 0);
							SDL_Delay(100);
							break;
					case (SDLK_UP):
							*vol2 += MIX_MAX_VOLUME / 4;
							if (*vol2>MIX_MAX_VOLUME)
							{
								*vol2 = MIX_MAX_VOLUME;
							}
							Mix_VolumeMusic(*vol2);
							refresh=1;
							SDL_Delay(100);
							break;
					case (SDLK_DOWN):
							*vol2 -= MIX_MAX_VOLUME / 4;
							if (*vol2<0)
							{
								*vol2 = 0;
							}
							Mix_VolumeMusic(*vol2);
							refresh=1;
							SDL_Delay(100);
							break;
				}
			case (SDL_MOUSEMOTION):
					x = event.motion.x;
					y = event.motion.y;
					if ((320.5<=x && x<=570) && (525<=y && y<=590))
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
						refresh=1;
					}
					else if (150<=y && y<=231 && 225<=x && x<=300)
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
								volume (fenetre,vol,vol2);
								fullscreen (fenetre, full);
								Mix_PlayChannel(-1, hovermusic, 0);
							}
						}
					}
					else if (150<=y && y<=231 && 315<=x && x<=440)
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
								volume (fenetre,vol,vol2);
								fullscreen (fenetre, full);
								Mix_PlayChannel(-1, hovermusic, 0);
							}
						}
					}
					else if (150<=y && y<=231 && 455<=x && x<=590)
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
								volume (fenetre,vol,vol2);
								fullscreen (fenetre, full);
								Mix_PlayChannel(-1, hovermusic, 0);
							}
						}
					}
					else if (150<=y && y<=231 && 580<=x && x<=710)
					{
						SDL_WaitEvent(&event);
						if (event.type==SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button==SDL_BUTTON_LEFT)
							{
								*vol = 96;
								Mix_Volume(-1, *vol);
								background (fenetre);
								titreoption (fenetre);
								quitoptions (fenetre);
								volume (fenetre,vol,vol2);
								fullscreen (fenetre, full);
								Mix_PlayChannel(-1, hovermusic, 0);
							}
						}
					}
					else if (150<=y && y<=231 && 690<=x && x<=780)
					{
						SDL_WaitEvent(&event);
						if (event.type==SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button==SDL_BUTTON_LEFT)
							{
								*vol = 128;
								Mix_Volume(-1, *vol);
								background (fenetre);
								titreoption (fenetre);
								quitoptions (fenetre);
								volume (fenetre,vol,vol2);
								fullscreen (fenetre, full);
								Mix_PlayChannel(-1, hovermusic, 0);
							}
						}
					}
					else if (250<=y && y<=331 && 225<=x && x<=300)
					{
						SDL_WaitEvent(&event);
						if (event.type==SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button==SDL_BUTTON_LEFT)
							{
								*vol2 = 0;
								Mix_VolumeMusic(*vol2);
								background (fenetre);
								titreoption (fenetre);
								quitoptions (fenetre);
								volume (fenetre,vol,vol2);
								fullscreen (fenetre, full);
							}
						}
					}
					else if (250<=y && y<=331 && 315<=x && x<=440)
					{
						SDL_WaitEvent(&event);
						if (event.type==SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button==SDL_BUTTON_LEFT)
							{
								*vol2 = 32;
								Mix_VolumeMusic(*vol2);
								background (fenetre);
								titreoption (fenetre);
								quitoptions (fenetre);
								volume (fenetre,vol,vol2);
								fullscreen (fenetre, full);
							}
						}
					}
					else if (250<=y && y<=331 && 455<=x && x<=590)
					{
						SDL_WaitEvent(&event);
						if (event.type==SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button==SDL_BUTTON_LEFT)
							{
								*vol2 = 64;
								Mix_VolumeMusic(*vol2);
								background (fenetre);
								titreoption (fenetre);
								quitoptions (fenetre);
								volume (fenetre,vol,vol2);
								fullscreen (fenetre, full);
							}
						}
					}
					else if (250<=y && y<=331 && 580<=x && x<=710)
					{
						SDL_WaitEvent(&event);
						if (event.type==SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button==SDL_BUTTON_LEFT)
							{
								*vol2 = 96;
								Mix_VolumeMusic(*vol2);
								background (fenetre);
								titreoption (fenetre);
								quitoptions (fenetre);
								volume (fenetre,vol,vol2);
								fullscreen (fenetre, full);
							}
						}
					}
					else if (250<=y && y<=331 && 690<=x && x<=780)
					{
						SDL_WaitEvent(&event);
						if (event.type==SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button==SDL_BUTTON_LEFT)
							{
								*vol2 = 128;
								Mix_VolumeMusic(*vol2);
								background (fenetre);
								titreoption (fenetre);
								quitoptions (fenetre);
								volume (fenetre,vol,vol2);
								fullscreen (fenetre, full);
							}
						}
					}
					else if (405<=y && y<=465 && 500<=x && x<=560)
					{
						SDL_WaitEvent(&event);
						if (event.type==SDL_MOUSEBUTTONDOWN)
						{
							if (event.button.button==SDL_BUTTON_LEFT)
							{
								if (*full==0)
								{
									fenetre = SDL_SetVideoMode(0,0,32, SDL_FULLSCREEN | SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
									refresh=1;
									*full=1;
								}
								else
								{
									fenetre = SDL_SetVideoMode(900,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
									*full=0;
									refresh=1;
								}
							}
						}
					}
					else
					{
						if (refresh){
						background (fenetre);
						titreoption (fenetre);
						quitoptions (fenetre);
						volume (fenetre,vol,vol2);
						fullscreen (fenetre, full);
						refresh=0;
						}
					}
					break;

			}

	SDL_Flip(fenetre);
	}
	*choix = 0;
}
