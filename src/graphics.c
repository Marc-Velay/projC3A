#include "libInclude.h"


SDL_Surface *loadImage(char *name)
{
    /* Load the image using SDL Image */

    SDL_Surface *temp = IMG_Load(name);
    SDL_Surface *image=  NULL;

    if (temp == NULL)
    {
        printf("Failed to load image %s\n", name);
        return NULL;
    }

    image = SDL_DisplayFormat(temp);

    SDL_FreeSurface(temp);

    if (image == NULL)
    {
        printf("Failed to convert image %s to native format\n", name);

        return NULL;
    }

    if( image != NULL )
    {
        //Map the color key, 3* 0xFF pour transparent, without white background
        Uint32 colorkey = SDL_MapRGB( (*image).format, 0x00, 0x00, 0x00 );
        SDL_SetColorKey( image, SDL_SRCCOLORKEY, colorkey );
    }


    /* Return the processed image */
    return image;
}

SDL_Surface *loadImageFULL(char *name)
{
    /* Load the image using SDL Image */

    SDL_Surface *temp = IMG_Load(name);
    SDL_Surface *image=  NULL;

    if (temp == NULL)
    {
        printf("Failed to load image %s\n", name);
        return NULL;
    }

    image = SDL_DisplayFormat(temp);

    SDL_FreeSurface(temp);

    if (image == NULL)
    {
        printf("Failed to convert image %s to native format\n", name);

        return NULL;
    }

    /* Return the processed image, without touching white background */
    return image;
}

TTF_Font *loadFont(char *name, int size)
{
    /* Use SDL_TTF to load the font at the specified size */

    TTF_Font *Font = TTF_OpenFont(name, size);

    if (Font == NULL)
    {
        printf("Failed to open Font %s: %s\n", name, TTF_GetError());

        exit(1);
    }

    return Font;
}


void drawImage(SDL_Surface *image, int x, int y)
{
    SDL_Rect dest;

    /* Set the blitting rectangle to the size of the src image */

    dest.x = x;
    dest.y = y;
    dest.w = (*image).w;
    dest.h = (*image).h;

    /* Blit the entire image onto the screen at coordinates x and y */
    SDL_BlitSurface(image, NULL, Game.screen, &dest);
}


void drawString(char *text, int x, int y, TTF_Font *Font)
{
    SDL_Rect dest;
    SDL_Surface *surface;
    SDL_Color foregroundColor, backgroundColor;

    /* Black text on a white background */

    foregroundColor.r = 0;
    foregroundColor.g = 0;
    foregroundColor.b = 0;

    backgroundColor.r = 255;
    backgroundColor.g = 255;
    backgroundColor.b = 255;

    /* Use SDL_TTF to generate a string image, this returns an SDL_Surface */

    surface = TTF_RenderUTF8_Shaded(Font, text, foregroundColor, backgroundColor);

    if( surface != NULL )
    {
        //Map the color key, 3* 0xFF pour transparent, sans font blanc
        Uint32 colorkey = SDL_MapRGB( (*surface).format, 0, 0, 0 );
        SDL_SetColorKey( surface, SDL_SRCCOLORKEY, colorkey );
    }

    if (surface == NULL)
    {
        printf("Couldn't create String %s: %s\n", text, SDL_GetError());

        return;
    }

    /* Blit the entire surface to the screen */

    dest.x = x - (*surface).w / 2;
    dest.y = y - (*surface).h / 2;
    dest.w = (*surface).w;
    dest.h = (*surface).h;

    SDL_BlitSurface(surface, NULL, Game.screen, &dest);

    /* Free the generated string image */

    SDL_FreeSurface(surface);
}



void loadSprite(int index, char *name)
{
    /* Load the image into the next slot in the sprite bank */
    if (index >= MAX_SPRITES || index < 0)
    {
        printf("Invalid index for sprite! Index: %d Maximum: %d\n", index, MAX_SPRITES);

        exit(1);
    }

    Game.sprite[index].image = loadImage(name);

    if (Game.sprite[index].image == NULL)
    {
        exit(1);
    }
}



SDL_Surface *getSprite(int index)       // Vérifie si l'image que l'on appelle existe
{
    if (index >= MAX_SPRITES || index < 0)
    {
        printf("Invalid index for sprite! Index: %d Maximum: %d\n", index, MAX_SPRITES);

        exit(1);
    }

    return Game.sprite[index].image;
}

void freeSprites()
{
    int i;

    /* Loop through the sprite bank and clear the images */

    for (i=0; i<MAX_SPRITES; i++)
    {
        if (Game.sprite[i].image != NULL)
        {
            SDL_FreeSurface(Game.sprite[i].image);
        }
    }
}

void loadAllSprites()       // Chargement de toutes les images utilisées dans le programme et les polices d'écriture
{
    /*TitleFont = loadFont("sfd/PIXEL.ttf", 90);
    SubTitleFont = loadFont("sfd/PIXEL.ttf", 50);
    compteurFont = loadFont("sfd/PIXEL.ttf", 30);
    ClassicFont = loadFont("sfd/PIXEL.ttf", 40);*/
    printf("loading\n");
    Game.textFont = loadFont("fonts/FreeSans.ttf", 15);
    Game.Background[0] = loadImageFULL("img/road1.png");
    Game.Background[1] = loadImageFULL("img/road2.png");
    Game.Background[2] = loadImageFULL("img/road3.png");
    Game.Background[3] = loadImageFULL("img/road4.png");
    Game.Background[4] = loadImageFULL("img/road5.png");
    Game.Background[5] = loadImageFULL("img/road6.png");
    Game.Background[6] = loadImageFULL("img/road7.png");
    Game.Background[7] = loadImageFULL("img/road8.png");
    Game.Background[8] = loadImageFULL("img/road9.png");
    Game.Background[9] = loadImageFULL("img/road10.png");
    Game.Background[10] = loadImageFULL("img/road11.png");
    loadSprite(PLAYER_CAR, "img/playerCar.png");
    loadSprite(CAR1, "img/car1.png");
    loadSprite(CAR2, "img/car2.png");
    loadSprite(GAMEOVER, "img/gameOver.png");
    loadSprite(STARTGAME, "img/startGame.png");
    
}

void drawText(char *text, int x, int y, TTF_Font *textFont, int r, int g, int b)    // Paramètres d'affichage de l'interface sur la carte noir/bleu
{
    SDL_Rect dest;
    SDL_Surface *surface;
    SDL_Color foregroundColor, backgroundColor;

    /* White text on a black background */

    foregroundColor.r = 0;
    foregroundColor.g = 0;
    foregroundColor.b = 0;

    backgroundColor.r = r;
    backgroundColor.g = g;
    backgroundColor.b = b;

    /* Use SDL_TTF to generate a string image, this returns an SDL_Surface */

    surface = TTF_RenderUTF8_Shaded(textFont, text, foregroundColor, backgroundColor);

    if (surface == NULL)
    {
        printf("Couldn't create String %s: %s\n", text, SDL_GetError());

        return;
    }

    /* Blit the entire surface to the screen */

    dest.x = x;
    dest.y = y;
    dest.w = (*surface).w;
    dest.h = (*surface).h;


    SDL_BlitSurface(surface, NULL, Game.screen, &dest);

    /* Free the generated string image */

    SDL_FreeSurface(surface);
}


void drawInterface() {    // Affichage de l'interface d'information sur la carte
	char string[20] ;
        
    if(Game.stade == 1) {
        sprintf(string,"%d", Game.Player.speed);
        drawText("Speed: ", 50, 25, Game.textFont,196,154,108);
        drawText(string, 100, 25, Game.textFont,196,154,108);

        sprintf(string,"%d", Game.score);
        drawText("Score: ", 50, 50, Game.textFont,196,154,108);
        drawText(string, 100, 50, Game.textFont,196,154,108);

        sprintf(string,"%d", Game.nbActiveCars);
        drawText("NB cars active: ", 50, 75, Game.textFont,196,154,108);
        drawText(string, 150, 75, Game.textFont,196,154,108);
    } else if(Game.stade == 2) {

    }
}



void delay(unsigned int frameLimit)     // Limite le nombre de frames par seconde du jeu
{
	unsigned int ticks = SDL_GetTicks();

	if (frameLimit < ticks)
	{
		return;
	}

	if (frameLimit > ticks + 32)
	{
		SDL_Delay(32);
	}

	else
	{
		SDL_Delay(frameLimit - ticks);
	}
}



void updateScreen() // Actualise l'affichage de la fenêtre en fonction de l'état du jeu
{
    SDL_FillRect(Game.screen, NULL, 0);

    switch(Game.stade)
    {
    case 0:                             // Affichage du Menu
        drawImage(getSprite(STARTGAME), 0, 0);
        break;

    case -1:                            // Affichage de la saisie du nom du joueur
        
        break;
    case 1:                             // Affichage du jeu (Start Game)      
        
        drawImage(Game.Background[Game.backgroundFrame%11], 0, 0);
        drawInterface();
        drawPlayer();
        drawCars();
        addCars();        
        moveTraffic();
        doScore();
        break;


    case 2:                             // Affichage de fin de jeu (Game Over)
        drawImage(getSprite(GAMEOVER), 0, 0);
        drawInterface();
        break;

    case 3: 
        drawImage(Game.Background[Game.backgroundFrame%11], 0, 0);
        drawInterface();
        drawPlayer();
        drawCars();
        addCars();        
        moveTraffic();
        doScore();

        break;
    }


    SDL_Flip(Game.screen);
}
