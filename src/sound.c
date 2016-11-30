#include "libInclude.h"

void loadAllMusic(){                // Chargement de toutes les musiques utilisées dans le programme

    Game.music = Mix_LoadMUS("sound/ambiantMusic.mp3");
    /*** Musiques ***/

    Mix_AllocateChannels(1);                // Création de deux canaux audio (superposition des effets sonores)
    Mix_VolumeMusic(MIX_MAX_VOLUME/5);      // Réglage du volume de la musique
}


void freeMusic(){              // Libère la musique chargée en mémoire

    
    Mix_FreeMusic(Game.music);
}