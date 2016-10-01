#include "libInclude.h"

void initPlayer()   // Initialisation des variables dde la voiture au début du jeu (Start Game)
{
    Game.Player.sprite = getSprite(PLAYER_CAR); // Chargement de l'image du personnage
    Game.Player.x = 30;      // Positionnement du personnage
    Game.Player.y = MID_LANE;
    Game.Player.speed = MIN_SPEED +20;
    
    Game.Player.nameInd = 0;
}

void drawPlayer() 
{
    drawImage(Game.Player.sprite, Game.Player.x, Game.Player.y);
}


void doScore() {
    
}