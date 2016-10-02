#include "libInclude.h"


int main(int argc, char *argv[])
{
	int play = 1;
	unsigned int frameLimit = SDL_GetTicks() + 30;


    while(play == 1){//Lance le jeu et boucle jusqu'à ce que l'utilisateur quitte le jeu

        if(Game.restart ==1) { printf("restarted\n"); }
        Game.restart = 0;
        Game.stade=0;
        init("Road rager");
        atexit(cleanup);
        
        play++;
        

        while (Game.restart != 1)//tant qu'une partie n'est pas relancée, on boucle
        {
	        updateScreen();
	        getInput();
		    Game.timer +=1;
            Game.backgroundFrame++;
            delay(frameLimit);
            frameLimit = SDL_GetTicks() + 30;
        }

    }

	exit(0);
}
