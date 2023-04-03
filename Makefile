prog:main.o image.o text.o struct.h perso.o perso.h
	gcc main.o image.o text.o perso.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer -lm
main.o:main.c
	gcc -c main.c -g
Image.o:image.c
	gcc -c image.c -g
texte.o:text.c
	gcc -c text.c -g
perso.o:perso.c
	gcc -c perso.c -g
