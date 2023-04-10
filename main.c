#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_keysym.h>
#include <SDL/SDL_mixer.h>
#include "perso.h"


int main (int argc, char *argv[])
{
	//Initialisation
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	Mix_OpenAudio (44100, MIX_DEFAULT_FORMAT, 2, 2048);
	int x, y, choix, e, loop2, loop, volume, no, volume2, full, isclicked, keyd, keya, decel, once;
	SDL_Surface *fenetre = NULL;
	Mix_Music *bgmusic = Mix_LoadMUS("Resources/menu.mp3");
	Mix_Chunk *hovermusic = Mix_LoadWAV("Resources/slash.wav");
	int Mix_VolumeMusic(int volume);
	int Mix_VolumeChunk(Mix_Chunk *hovermusic, int volume);
	SDL_Event event;
	Uint32 skyblue, prevTicks, dt;
	fenetre = SDL_SetVideoMode(900,600,32, SDL_HWSURFACE | SDL_DOUBLEBUF | SDL_RESIZABLE);
	
	//Creation texte
	SDL_Surface *texte2;
	SDL_Rect texte2Pos;
	TTF_Font *font2;
	font2 = TTF_OpenFont("Resources/Font.otf",30);
	SDL_Color fontBlack2 = {0,0,0};
	texte2Pos.x=4;
	texte2Pos.y=2;
	texte2 = TTF_RenderText_Blended(font2, "Walking", fontBlack2);
	
	choix=0;
	e=1;
	loop = 1;
	volume = MIX_MAX_VOLUME / 2;
	volume2 = MIX_MAX_VOLUME / 2;
	no=1;
	full=0;
	keyd = 1;
	keya = 1;
	skyblue = SDL_MapRGB(fenetre->format,200,255,255);	
	perso *p = malloc(sizeof(perso));
	prevTicks = SDL_GetTicks();

	//Boucle du jeu
	while (loop)
	{
		//Affichage
		switch (choix)
		{
			case 0:
				//Affichage par defaut
				if ((SDL_GetTicks()/1000)%3==0)
				{
					if (no)
					{
						Mix_PlayMusic(bgmusic, -1);
						no = 0;
					}
					background (fenetre);
					logo (fenetre);
					play (fenetre);
					options(fenetre);
					credits(fenetre);
					quit(fenetre);
					text (fenetre);
					break;
				}
				break;

			case 1: //play
				SDL_FillRect(fenetre,NULL,skyblue);
				SDL_BlitSurface(texte2,NULL,fenetre,&texte2Pos);
				initPerso(p);
				p->posSprite.x = 0;
				p->posSprite.y = (p->posSprite.h);
				afficherPerso(p, fenetre);
				once = 0;
				loop2=1;
				while (loop2)
				{
					SDL_PollEvent(&event);
					if (event.type==SDL_KEYDOWN)
					{
						if (event.key.keysym.sym==SDLK_ESCAPE)
						{
							loop2=0;
							choix=0;
						}
						if (event.key.keysym.sym==SDLK_d)
						{
							keyd = 0;
							dt = SDL_GetTicks() - prevTicks + 1;
							p->direction=1;
							movePerso (p,dt);
							SDL_FillRect(fenetre,NULL,skyblue);
							SDL_BlitSurface(texte2,NULL,fenetre,&texte2Pos);
							animerPerso (p);
							afficherPerso(p, fenetre);
							decel = 1;
							once = 1;
						}
						else if (event.key.keysym.sym==SDLK_a)
						{
							keya = 0;
							dt = SDL_GetTicks() - prevTicks + 1;
							p->direction=0;
							movePerso (p,dt);
							SDL_FillRect(fenetre,NULL,skyblue);
							SDL_BlitSurface(texte2,NULL,fenetre,&texte2Pos);
							animerPerso (p);
							afficherPerso(p, fenetre);
							decel = 1;
							once = 1;
						}
						if (event.key.keysym.sym==SDLK_w)
						{
							saut (p,fenetre);
							SDL_BlitSurface(texte2,NULL,fenetre,&texte2Pos);
							SDL_Flip(fenetre);
						}
						if (event.key.keysym.sym==SDLK_LSHIFT)
						{
							if (p->vitesse == 0)
							{
								p->vitesse = 2;
								texte2 = TTF_RenderText_Blended(font2, "Running", fontBlack2);
								SDL_FillRect(fenetre,NULL,skyblue);
								SDL_BlitSurface(texte2,NULL,fenetre,&texte2Pos);
								afficherPerso(p, fenetre);
								SDL_Delay(500);
							}
							else 
							{
								p->vitesse = 0;
								texte2 = TTF_RenderText_Blended(font2, "Walking", fontBlack2);
								SDL_FillRect(fenetre,NULL,skyblue);
								SDL_BlitSurface(texte2,NULL,fenetre,&texte2Pos);
								afficherPerso(p, fenetre);
								SDL_Delay(500);
							}
						}
					}
					if (event.type==SDL_KEYUP)
					{
						if (event.key.keysym.sym==SDLK_d)
						{
							keyd = 1;
							deceleration (p,&decel,fenetre);
							SDL_BlitSurface(texte2,NULL,fenetre,&texte2Pos);
						}
						if (event.key.keysym.sym==SDLK_a)
						{
							keya = 1;
							deceleration (p,&decel,fenetre);
							SDL_BlitSurface(texte2,NULL,fenetre,&texte2Pos);
						}

					}
					if (keya == 1 && keyd == 1)
					{
						if (once)
						{
							p->acceleration = 2;
							p->posSprite.x = 0;
							p->posSprite.y = p->direction * (p->posSprite.h);
							SDL_FillRect(fenetre,NULL,skyblue);
							SDL_BlitSurface(texte2,NULL,fenetre,&texte2Pos);
							afficherPerso(p, fenetre);
							once = 0;
						}
					}
				prevTicks = SDL_GetTicks();
				}
				event.key.keysym.sym=0;
				break;

			case 2: //options
				menuoption (fenetre,&choix,&volume,&volume2,&full);
				break;
			
			case 3: //credits
				break;

			case 4: //play hover
				if (e==1)
				{
					playhover (fenetre);
					options(fenetre);
					credits(fenetre);
					quit(fenetre);
					Mix_PlayChannel(-1, hovermusic, 0);
					e=0;
				}
				break;
			case 5:
				if (e==1)
				{
					play (fenetre);
					optionshover(fenetre);
					credits(fenetre);
					quit(fenetre);
					Mix_PlayChannel(-1, hovermusic, 0);
					e=0;
				}
				break;
			case 6:
				if (e==1)
				{
					play(fenetre);
					options(fenetre);
					creditshover(fenetre);
					quit(fenetre);
					Mix_PlayChannel(-1, hovermusic, 0);
					e=0;
				}
				break;
			case 7:
				if (e==1)
				{
					play(fenetre);
					options(fenetre);
					credits(fenetre);
					quithover(fenetre);
					Mix_PlayChannel(-1, hovermusic, 0);
					e=0;
				}
				break;

		}
		//Input
		if (choix != 1 && choix != 2 && choix != 3)
		{
		SDL_PollEvent(&event);
		switch (event.type)
		{
			case (SDL_QUIT):
				loop = 0;
				break;

			case (SDL_KEYDOWN):
				switch (event.key.keysym.sym)
				{
					case (SDLK_ESCAPE):
						loop = 0;
						break;
					case (SDLK_p):
						choix = 1;
						break;
					case (SDLK_o):
						choix = 2;
						break;
					case (SDLK_c):
						choix = 3;
						break;
					case (SDLK_q):
						loop = 0;
						break;
					case (SDLK_DOWN):
						if(choix==0)
						{
							choix=4;
							e=1;
							SDL_Delay(500);						
						}
						else if(choix==4)
						{
							choix=5;
							e=1;
							SDL_Delay(500);					
						}
						else if(choix==5)
						{
							choix=6;
							e=1;
							SDL_Delay(500);					
						}
						else if(choix==6)
						{
							choix=7;
							e=1;
							SDL_Delay(500);					
						}
						break;
					case (SDLK_UP):
						if(choix==7)
						{
							choix=6;
							e=1;
							SDL_Delay(500);						
						}
						else if(choix==6)
						{
							choix=5;
							e=1;
							SDL_Delay(500);					
						}
						else if(choix==5)
						{
							choix=4;
							e=1;
							SDL_Delay(500);					
						}
						else if(choix==0)
						{
							choix=7;
							e=1;
							SDL_Delay(500);					
						}
						break;
					case (SDLK_RETURN):
						if(choix==7)
						{
							loop = 0;
						}
						else if(choix==6)
						{
							choix=3;
						}
						else if(choix==5)
						{
							choix=2;				
						}
						else if(choix==4)
						{
							choix=1;				
						}
						break;

				}
				break;

			case (SDL_MOUSEMOTION):
				x = event.motion.x;
				y = event.motion.y;
				if ((281.5<=x && x<=570.5) && (200<=y && y<=269))
				{
					choix = 4;
					SDL_WaitEvent(&event);
					if (event.type==SDL_MOUSEBUTTONDOWN)
					{
						if (event.button.button==SDL_BUTTON_LEFT)
						{
							choix = 1;
						}
					}
				}
				else if ((330.5<=x && x<=617.5) && (280<=y && y<=348))
				{
					choix = 5;
					SDL_WaitEvent(&event);
					if (event.type==SDL_MOUSEBUTTONDOWN)
					{
						if (event.button.button==SDL_BUTTON_LEFT)
						{
							choix = 2;
						}
					}
				}
				else if ((281.5<=x && x<=570.5) && (360<=y && y<=430))
				{
					choix = 6;
					SDL_WaitEvent(&event);
					if (event.type==SDL_MOUSEBUTTONDOWN)
					{
						if (event.button.button==SDL_BUTTON_LEFT)
						{
							choix = 3;
						}
					}
				}
				else if ((330<=x && x<=618) && (450<=y && y<=509))
				{
					choix = 7;
					SDL_WaitEvent(&event);
					if (event.type==SDL_MOUSEBUTTONDOWN)
					{
						if (event.button.button==SDL_BUTTON_LEFT)
						{
							loop = 0;
						}
					}
				}
				else 
				{
					e=1;
					play (fenetre);
					options (fenetre);
					credits (fenetre);
					quit (fenetre);
					choix = 0;
				}
				break;				
		}
		}
		//Mise a jour
		SDL_Flip(fenetre);

	}

	//Liberation d'espace
	freeperso (p);
	SDL_FreeSurface(fenetre);
	SDL_FreeSurface(texte2);
	TTF_Quit();
	Mix_FreeMusic(bgmusic);
	Mix_FreeChunk(hovermusic);
	Mix_CloseAudio();
	SDL_Quit();
	return 0;
}


