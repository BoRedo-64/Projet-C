prog:main.o image.o text.o struct.h
	gcc main.o image.o text.o -o prog -lSDL -lSDL_ttf -g -lSDL_image -lSDL_mixer
main.o:main.c
	gcc -c main.c -g
Image.o:image.c
	gcc -c image.c -g
texte.o:text.c
	gcc -c text.c -g
