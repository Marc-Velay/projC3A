#include "libInclude.h"

void initPlayer()   // Initialisation des variables dde la voiture au début du jeu (Start Game)
{
    Game.Player.sprite = getSprite(PLAYER_CAR); // Chargement de l'image du personnage
    Game.Player.x = PLAYER_INIT_X;      // Positionnement du personnage
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

int getCarLeft() {
    int closestLeft=10000;

    for(int carID =0; carID < MAX_NB_CARS; carID++) {
        if(Game.Traffic[carID].y == Game.Player.y - LANE_WIDTH) {
            if(Game.Traffic[carID].x > PLAYER_INIT_X-CAR_WIDTH && Game.Traffic[carID].x < closestLeft) closestLeft = Game.Traffic[carID].x; 
        }
    }

    return closestLeft;
}

int getCarRight() {
    int closestRight=10000;

    for(int carID =0; carID < MAX_NB_CARS; carID++) {
        if(Game.Traffic[carID].y == Game.Player.y + LANE_WIDTH) {
            if(Game.Traffic[carID].x > PLAYER_INIT_X-CAR_WIDTH && Game.Traffic[carID].x < closestRight) closestRight = Game.Traffic[carID].x; 
        }
    }

    return closestRight;
}

int getCarFront() {
    int closestCenter=10000;

    for(int carID =0; carID < MAX_NB_CARS; carID++) {
        if(Game.Traffic[carID].y == Game.Player.y) {
            if(Game.Traffic[carID].x > PLAYER_INIT_X-CAR_WIDTH-10 && Game.Traffic[carID].x < closestCenter) closestCenter = Game.Traffic[carID].x; 
        }
    }

    return closestCenter;
}

void playerAutoInput(Input *in) {
    //modifiable: SDLK_DOWN, UP, LEFT, RIGHT
    int carLeftX = getCarLeft();
    int carRightX = getCarRight();
    int carCenterX = getCarFront();

    printf("left: %d, center: %d, right: %d\n", carLeftX, carCenterX, carRightX);


    if(carLeftX > carCenterX && Game.Player.y != FIRST_LANE) {
            (*in).key[SDLK_UP] = 1;
            printf("go left\n");
    } else 
     if(carRightX > carCenterX) {
            (*in).key[SDLK_DOWN] = 1;
            printf("go right\n");
    }

    if(carCenterX > PLAYER_INIT_X + 3*CAR_WIDTH) {
        (*in).key[SDLK_RIGHT] = 1;
        printf("accelerate to %d\n", Game.Player.speed);
    } else if(carCenterX < PLAYER_INIT_X + 3*CAR_WIDTH) {
        (*in).key[SDLK_LEFT] = 1;
        printf("decelerate\n");
    }

    Game.Player.carInFrontLastX = carCenterX;
    Game.Player.carToLeftLastX = carLeftX;
    Game.Player.carToRightlastX = carRightX;
}