all: compile execute clean

graphics.o: src/graphics.c src/libInclude.h
	gcc -Wall -std=c99 -c src/graphics.c -O3
	
init.o: src/init.c src/libInclude.h
	gcc -Wall -std=c99 -c src/init.c -O3
		
input.o: src/input.c src/libInclude.h
	gcc -Wall -std=c99 -c src/input.c -O3	
		
main.o: src/main.c src/libInclude.h
	gcc -Wall -std=c99 -c src/main.c -O3
	
sound.o: src/sound.c src/libInclude.h
	gcc -Wall -std=c99 -c src/sound.c -O3
	
player.o: src/player.c src/libInclude.h
	gcc -Wall -std=c99 -c src/player.c -O3
	
traffic.o: src/traffic.c src/libInclude.h
	gcc -Wall -std=c99 -c src/traffic.c -O3

compile: graphics.o init.o input.o main.o sound.o player.o traffic.o
	gcc -o projC3A main.o graphics.o init.o input.o sound.o player.o traffic.o `sdl-config --cflags --libs` -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -O3
	
execute: 
	./projC3A

clean:
	rm *.o projC3A 
