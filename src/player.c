#include "libInclude.h"

void initPlayer()   // Initialisation des variables dde la voiture au début du jeu (Start Game)
{
    Game.Player.sprite = getSprite(PLAYER_CAR); // Chargement de l'image du personnage
    Game.Player.x = 30;      // Positionnement du personnage
    Game.Player.y = MID_LANE;
    Game.Player.speed = 100;
    Game.Player.carInFrontLastX = 0;
    Game.Player.carToLeftLastX = 0;
    Game.Player.carToRightlastX = 0;
    Game.Player.nameInd = 0;
}

void drawPlayer() 
{
    drawImage(Game.Player.sprite, Game.Player.x, Game.Player.y);
}


void doScore() {
    Game.score += Game.Player.speed/150;
}

void playerAutoInput(Input *in) {
    //modifiable: SDLK_DOWN, UP, LEFT, RIGHT
    (*in).key[SDLK_DOWN] =1;
    if(Game.Player.y == MID_LANE + 2*LANE_WIDTH) {
        (*in).key[SDLK_UP]=1;
    }
    if(Game.Player.x == MID_LANE - 2*LANE_WIDTH) {
        (*in).key[SDLK_DOWN]=1;
    } else {
        int dir = rand() %2;
        if(dir == 0) {
            (*in).key[SDLK_UP]=1;            
        } else if(dir == 1) {
            (*in).key[SDLK_DOWN]=1;
        }
    }
}