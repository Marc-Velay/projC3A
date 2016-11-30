#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
#include "SDL/SDL_mixer.h"

#define MAX_SPRITES 8

#define SCREEN_WIDTH 1700		//Defini la taille de la fenetre
#define SCREEN_HEIGHT 1080
#define LANE_WIDTH 120
#define FIRST_LANE 274
#define MID_LANE 514
#define NB_LANE 5
#define PLAYER_INIT_X 30
#define CAR_HEIGHT 50
#define CAR_WIDTH 95

#define MAX_SPEED 400
#define MIN_SPEED 50
#define MAX_NB_CARS 15
#define MAX_LINES 5

#define AUTO_SPEED_INCREMENTS 10

// Strip images using		 pngcrush -rem allb RogerShadeClean_64x64.png Roger_Clean.png

typedef struct Input			//structure utilisée pour récuperer les touches clavier/ sourie appuyées
{
    char key[SDLK_LAST];
    int mousex,mousey;
    int mousexrel,mouseyrel;
    char mousebuttons[8];
    char quit;
} Input;



typedef struct Sprites          // structure des images (sprites)
{
    SDL_Surface *image;
} Sprites;



typedef struct player			// structure du conducteur
{
    char name[14];
    int speed;
    int x, y;
    SDL_Surface *sprite;
    int nameInd;
    int turnedLeft;
    int turnedRight;
    int carInFrontLastX;
    int carToLeftLastX;
    int carToRightlastX;
} player;




typedef struct car {
    int speed;
    int x, y;
    int active;
    SDL_Surface *sprite;
} car;



typedef struct game			//toutes les variables du rungame, utilisee pour faire tourner le jeu
{
    int stade;
    int countdown;
    int timer;
    int backgroundFrame;
    int restart;
    int nbActiveCars;
    int firstFreeID;
    int lastLanePoped;
    unsigned int score;
    unsigned int bestScore;
    Sprites sprite[MAX_SPRITES];
    player Player;
    car Traffic[MAX_NB_CARS];
    SDL_Surface *screen, *Background[11], *Text;  //initialise les surfaces de la fenetre, fond et où on affiche le texte
    TTF_Font *textFont; /****** pointeurs de polices *****/
    TTF_Font *textFont2; /****** pointeurs de polices *****/
    Mix_Music *music;
} game;



enum{
    BACKGROUND_TOP,
    PLAYER_CAR,
    CAR1,
    CAR2,
    GAMEOVER,
    STARTGAME,
    BOOM,
    COMMANDS
};


game Game;

/**********sound.c*************/
void loadAllMusic();
void freeMusic();

/**********input.c*************/
void UpdateEvents(Input* in);
void getInput();

/*********init.c***************/
void init(char *title);
void cleanup();

/********graphics.c***********/
SDL_Surface *loadImage(char *name);
SDL_Surface *loadImageFULL(char *name);
TTF_Font *loadFont(char *name, int size);
void drawImage(SDL_Surface *image, int x, int y);
void drawString(char *text, int x, int y, TTF_Font *Font);
void drawText(char *text, int x, int y, TTF_Font *textFont, int r, int g, int b);
void loadSprite(int index, char *name);
SDL_Surface *getSprite(int index);
void freeSprites();
void loadAllSprites();
void delay(unsigned int frameLimit);
void drawInterface();
void updateScreen();

/*******player.c**************/
void initPlayer();
void drawPlayer();
void doScore();
void doBestScore();
void playerAutoInput(Input *in);

/*******traffic.c*************/
void addCars();
void moveTraffic();
void drawCars();
int isLineClear( int selectedLine);
void initCar(int selectedLine);

/*******sound.c*************/
void loadAllMusic();
void freeMusic();