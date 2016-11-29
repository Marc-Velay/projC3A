all: compile execute clean

graphics.o: src/graphics.c src/libInclude.h
	gcc -Wall -std=c99 -c src/graphics.c
	
init.o: src/init.c src/libInclude.h
	gcc -Wall -std=c99 -c src/init.c
		
input.o: src/input.c src/libInclude.h
	gcc -Wall -std=c99 -c src/input.c	
		
main.o: src/main.c src/libInclude.h
	gcc -Wall -std=c99 -c src/main.c
	
sound.o: src/sound.c src/libInclude.h
	gcc -Wall -std=c99 -c src/sound.c
	
player.o: src/player.c src/libInclude.h
	gcc -Wall -std=c99 -c src/player.c
	
traffic.o: src/traffic.c src/libInclude.h
	gcc -Wall -std=c99 -c src/traffic.c

compile: graphics.o init.o input.o main.o sound.o player.o traffic.o
	gcc -o projC3A main.o graphics.o init.o input.o sound.o player.o traffic.o `sdl-config --cflags --libs` -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
	
execute: 
	./projC3A

clean:
	rm *.o projC3A 
