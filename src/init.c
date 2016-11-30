#include "libInclude.h"


void init(char *title)              // Initialisation de la fenêtre, des bibliothèques utilisées et des variables utiles au début du jeu
{
    //int i;
	if(Game.restart == 0) {
		 if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) == -1)  //Initialisation de l'API Mixer (bibliothèque audio)
	    {
	        printf("%s", Mix_GetError());
	    }

	    if (SDL_Init(SDL_INIT_VIDEO) < 0)   // Initialisation des fonctions Image dans SDL
	    {
	        printf("Could not initialize SDL: %s\n", SDL_GetError());
	        exit(1);
	    }

	    Game.screen = SDL_SetVideoMode(SCREEN_WIDTH, SCREEN_HEIGHT, 0, SDL_HWPALETTE); // Chargement en mémoire d'une fenêtre de 1280x720 pixels

	    if (Game.screen == NULL)
	    {
	        printf("Couldn't set screen mode to 1280 x 720: %s\n", SDL_GetError());
	        exit(1);
	    }

	    if (TTF_Init() < 0)
	    {
	        printf("Couldn't initialize SDL TTF: %s\n", SDL_GetError());
	        exit(1);
	    }
            
	    SDL_WM_SetCaption(title, NULL); // Titre de la fenêtre
	}


/*************************Initalisation des variables utiles au début du jeu*****************************/


    Game.stade = 0;
    Game.countdown = 300;
    Game.timer = 0;
    Game.nbActiveCars = 0;
    Game.score =0;
    Game.bestScore=0;
    Game.firstFreeID = 100;
	Game.lastLanePoped =0;
    for(int carID = 0; carID < MAX_NB_CARS; carID++) {
        Game.Traffic[carID].active = 0;
    }
    loadAllSprites();
    loadAllMusic();
    initPlayer();
    Mix_PlayMusic(Game.music, -1);
    

/*************************Initalisation des variables utiles au début du jeu*****************************/
}





void cleanup() // Libération des bibliothèques et images chargées en mémoire
{
    //freeSprites();

    freeMusic();

    TTF_Quit();

    SDL_Quit();
}
