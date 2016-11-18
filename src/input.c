#include "libInclude.h"

//capture toutes les entrées utilisateur (clavier et souris)
void UpdateEvents(Input* in)
{	//remplis un tableau, où chaque case correspond à une touche par des 1 si la case a été appuyé.
    SDL_Event event;
    while(SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_KEYDOWN:
            (*in).key[event.key.keysym.sym]=1;
            break;
        case SDL_KEYUP:
            (*in).key[event.key.keysym.sym]=0;
            if(event.key.keysym.sym == SDLK_UP) Game.Player.turnedLeft = 0;
            if(event.key.keysym.sym == SDLK_DOWN) Game.Player.turnedRight = 0;
            break;
        case SDL_MOUSEMOTION:		//Les entrees de la souris.
            (*in).mousex=event.motion.x;
            (*in).mousey=event.motion.y;
            (*in).mousexrel=event.motion.xrel;
            (*in).mouseyrel=event.motion.yrel;
            break;
        case SDL_MOUSEBUTTONDOWN:
            (*in).mousebuttons[event.button.button]=1;
            break;
        case SDL_MOUSEBUTTONUP:
            (*in).mousebuttons[event.button.button]=0;
            break;
        case SDL_QUIT:
            (*in).quit = 1;
            break;
        default:
            break;
        }
    }
}


//Gère les intéractions du joueur avec le jeu (navigation dans le menu, poser tourelle, tirer, ecrire son nom...)
void getInput()
{
    Input in;
    memset(&in,0,sizeof(in));
    UpdateEvents(&in);

    if(in.key[SDLK_ESCAPE] || in.quit)
    {
        printf("quitting game\n");
	    SDL_Quit();
	    exit(0);
    }

    int moux;
    int mouy;	// coordonnées de la souris
    Game.Player.turnedLeft = 0;
    Game.Player.turnedRight = 0;
    unsigned int frameLimit = SDL_GetTicks() + 30;
    SDL_GetMouseState(&moux,&mouy);	// rentre les coord en x et y de la souris dans les deux entiers moux et mouy

    


    /************************************GET Text*********************************/

    //strlen (const char *cs);
    if(Game.stade == -1)    //mode pour obtenir les informations du joueur
    {
        if(Game.Player.nameInd < 13)//Si le nom comporte moins de 13 lettres, ajouter lettre préssée
        {
            if(in.key[SDLK_a])
            {
                Game.Player.name[Game.Player.nameInd] = 'A';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_b])
            {
                Game.Player.name[Game.Player.nameInd] = 'B';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_c])
            {
                Game.Player.name[Game.Player.nameInd] = 'C';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_d])
            {
                Game.Player.name[Game.Player.nameInd] = 'D';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_e])
            {
                Game.Player.name[Game.Player.nameInd] = 'E';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_f])
            {
                Game.Player.name[Game.Player.nameInd] = 'F';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_g])
            {
                Game.Player.name[Game.Player.nameInd] = 'G';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_h])
            {
                Game.Player.name[Game.Player.nameInd] = 'H';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_i])
            {
                Game.Player.name[Game.Player.nameInd] = 'I';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_j])
            {
                Game.Player.name[Game.Player.nameInd] = 'J';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_k])
            {
                Game.Player.name[Game.Player.nameInd] = 'K';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_l])
            {
                Game.Player.name[Game.Player.nameInd] = 'L';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_m])
            {
                Game.Player.name[Game.Player.nameInd] = 'M';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_n])
            {
                Game.Player.name[Game.Player.nameInd] = 'N';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_o])
            {
                Game.Player.name[Game.Player.nameInd] = 'O';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_p])
            {
                Game.Player.name[Game.Player.nameInd] = 'P';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_q])
            {
                Game.Player.name[Game.Player.nameInd] = 'Q';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_r])
            {
                Game.Player.name[Game.Player.nameInd] = 'R';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_s])
            {
                Game.Player.name[Game.Player.nameInd] = 'S';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_t])
            {
                Game.Player.name[Game.Player.nameInd] = 'T';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_u])
            {
                Game.Player.name[Game.Player.nameInd] = 'U';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_v])
            {
                Game.Player.name[Game.Player.nameInd] = 'V';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_w])
            {
                Game.Player.name[Game.Player.nameInd] = 'W';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_x])
            {
                Game.Player.name[Game.Player.nameInd] = 'X';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_y])
            {
                Game.Player.name[Game.Player.nameInd] = 'Y';
                Game.Player.nameInd++;
            }
            else if(in.key[SDLK_z])
            {
                Game.Player.name[Game.Player.nameInd] = 'Z';
                Game.Player.nameInd++;
            }
        }       //Si la touche retour est préssé, effacer lettre et décrémenter indice chaine
            if(in.key[SDLK_BACKSPACE] && Game.Player.nameInd > 0)
            {
                Game.Player.name[Game.Player.nameInd-1] = ' ' ;
                Game.Player.nameInd--;
            } //Si touche entrée pressé, lancer la partie et la musique de jeu
            else if(in.key[SDLK_RETURN])
            {

            }




    } else if(Game.stade == 1) {    //mode manuel du jeu
        
        if(in.mousebuttons[SDL_BUTTON_LEFT]) {      //fonction de debug, afin de savoir les positions des objects
            printf("x: %d, y: %d\n", moux, mouy);
        } else if(in.key[SDLK_UP] && Game.Player.y > 300) {
                Game.Player.y -= LANE_WIDTH; 
        } else if(in.key[SDLK_DOWN]  && Game.Player.y < 750) {
                Game.Player.y += LANE_WIDTH; 
        }
            
        while(in.key[SDLK_LEFT] || in.key[SDLK_RIGHT]) {
            if(in.key[SDLK_UP] && Game.Player.y > 300 && Game.Player.turnedLeft == 0) {
                    Game.Player.y -= LANE_WIDTH;
                    Game.Player.turnedLeft = 1;
            } else if(in.key[SDLK_DOWN]  && Game.Player.y < 750 && Game.Player.turnedRight == 0) {
                    Game.Player.y += LANE_WIDTH;
                    Game.Player.turnedRight = 1; 
            } else if(in.key[SDLK_RIGHT]  && Game.Player.speed < MAX_SPEED) {
                    Game.Player.speed ++; 
            } else if(in.key[SDLK_LEFT]  && Game.Player.speed > MIN_SPEED) {
                    Game.Player.speed --; 
            }
            
            updateScreen();
            Game.timer +=1;
            Game.backgroundFrame++;
            delay(frameLimit);
            UpdateEvents(&in);
            frameLimit = SDL_GetTicks() + 30;
        }




    } else if(Game.stade == 0) {    //menu
        if(in.mousebuttons[SDL_BUTTON_LEFT] && moux >730 && mouy > 790 && moux < 980 && mouy < 860) { //Position du bouton start game
            Game.stade++;
        }
        if(in.mousebuttons[SDL_BUTTON_LEFT]) {
            printf("x: %d, y: %d\n", moux, mouy);
        }
        if(in.key[SDLK_o]) {
            Game.stade=3;
        }



    } else if(Game.stade == 2){



    } else if(Game.stade == 3) {    //mode automatique
        memset(&in,0,sizeof(in));
        playerAutoInput(&in);
        if(in.key[SDLK_UP] && Game.Player.y > 300) {
                Game.Player.y -= LANE_WIDTH; 
        } else if(in.key[SDLK_DOWN]  && Game.Player.y < 750) {
                Game.Player.y += LANE_WIDTH; 
        }
            
        while(in.key[SDLK_LEFT] || in.key[SDLK_RIGHT]) {
            if(in.key[SDLK_UP] && Game.Player.y > 300 && Game.Player.turnedLeft == 0) {
                    Game.Player.y -= LANE_WIDTH;
                    Game.Player.turnedLeft = 1;
            } else if(in.key[SDLK_DOWN]  && Game.Player.y < 750 && Game.Player.turnedRight == 0) {
                    Game.Player.y += LANE_WIDTH;
                    Game.Player.turnedRight = 1; 
            } else if(in.key[SDLK_RIGHT]  && Game.Player.speed < MAX_SPEED) {
                    Game.Player.speed ++; 
            } else if(in.key[SDLK_LEFT]  && Game.Player.speed > MIN_SPEED) {
                    Game.Player.speed --; 
            }
            
            updateScreen();
            Game.timer +=1;
            Game.backgroundFrame++;
            delay(frameLimit);
            UpdateEvents(&in);
            frameLimit = SDL_GetTicks() + 30;
        }
    }
}
    

