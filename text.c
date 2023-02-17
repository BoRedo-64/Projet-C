#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL_ttf.h>

void text(SDL_Surface *fenetre)
{
	//Creer Police
	TTF_Font *font;
	font = TTF_OpenFont("Resources/Font.otf",20);
	SDL_Color fontBlack = {250,250,250};
	//Creer texte
	SDL_Surface *texte;
	texte = TTF_RenderText_Blended(font, "(c) Digimakers", fontBlack);
	SDL_Rect textePos;
	textePos.x=0;
	textePos.y=600-(texte->h);
	SDL_BlitSurface(texte,NULL,fenetre,&textePos);
	SDL_Flip(fenetre); //refrachir la fenetre
}
