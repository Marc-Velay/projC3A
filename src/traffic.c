#include "libInclude.h"



int isLineClear( int selectedLine) {
    for(int i = 0; i < MAX_NB_CARS; i++) {
            if(Game.Traffic[i].active == 1) {
                    if(Game.Traffic[i].y == (FIRST_LANE + LANE_WIDTH*selectedLine) && Game.Traffic[i].x >= (SCREEN_WIDTH - CAR_WIDTH*2) && Game.Traffic[i].x <= (SCREEN_WIDTH + CAR_WIDTH*6/2)) {
                            return 0;
                    }
            } else {
                    if(i <= Game.firstFreeID) { 
                        Game.firstFreeID = i;
                    }
            }
    }
    return 1;
}



void initCar(int selectedLine) {
    time_t t;
    srand((unsigned) time(&t));
    
    Game.nbActiveCars++;
    
    Game.Traffic[Game.firstFreeID].y= FIRST_LANE + LANE_WIDTH*selectedLine;
    Game.Traffic[Game.firstFreeID].x= SCREEN_WIDTH + CAR_HEIGHT*3/2;
    Game.Traffic[Game.firstFreeID].speed = (rand()%2)+7+(2-selectedLine);
    Game.Traffic[Game.firstFreeID].active = 1;
    if(Game.nbActiveCars%2 == 0) {
            Game.Traffic[Game.firstFreeID].sprite = getSprite(CAR1);
    } else {
            Game.Traffic[Game.firstFreeID].sprite = getSprite(CAR2);        
    }
    
    Game.firstFreeID = 100;
}


void killcar(int carID) {
    Game.Traffic[carID].x= 0;
    Game.Traffic[carID].y= 0;
    Game.Traffic[carID].speed = 0;
    Game.Traffic[carID].active = 0;
    Game.nbActiveCars--;
}



void collision(int carID) {
        if(Game.Traffic[carID].y >= Game.Player.y && Game.Traffic[carID].y <= (Game.Player.y + CAR_HEIGHT) && (( Game.Traffic[carID].x >= Game.Player.x &&  Game.Traffic[carID].x <= (Game.Player.x + CAR_WIDTH))
            || ((Game.Traffic[carID].x + CAR_WIDTH) >= (Game.Player.x) && (Game.Traffic[carID].x + CAR_WIDTH) <= (Game.Player.x + CAR_WIDTH)))) {
            killcar(carID);
            SDL_Delay(200);
            Game.stade++;
        } else {
            for(int cars =0; cars < MAX_NB_CARS; cars++){
                if(Game.Traffic[cars].active == 1 && cars != carID) {
                    if(Game.Traffic[carID].y >= Game.Traffic[cars].y && Game.Traffic[carID].y <= (Game.Traffic[cars].y + CAR_HEIGHT) && (( Game.Traffic[carID].x >= (Game.Traffic[cars].x -20) &&  Game.Traffic[carID].x <= (Game.Traffic[cars].x + CAR_WIDTH -20))
                        || ((Game.Traffic[carID].x + CAR_WIDTH) >= (Game.Traffic[cars].x -20) && (Game.Traffic[carID].x + CAR_WIDTH) <= (Game.Traffic[cars].x + CAR_WIDTH -20)))) {
                        if(Game.Traffic[cars].y > Game.Traffic[carID].y) {
                                Game.Traffic[cars].speed = Game.Traffic[carID].speed -1;
                        } else {
                                Game.Traffic[carID].speed = Game.Traffic[cars].speed -1;                            
                        }
                    }    
                }
            }
        }
}



void addCars() {
    
    time_t t;
    srand((unsigned) time(&t));
    int selectedLine = 0;
    
    if(Game.nbActiveCars < MAX_NB_CARS) {
                selectedLine = rand() %MAX_LINES;
                if(isLineClear(selectedLine) == 1 && selectedLine != Game.lastLanePoped) {
                        Game.lastLanePoped = selectedLine;
                        initCar(selectedLine);
                } else if((selectedLine+1)<MAX_LINES && isLineClear(selectedLine +1) == 1 && (selectedLine+1) != Game.lastLanePoped ) {
                        Game.lastLanePoped = selectedLine+1;
                        initCar(selectedLine+1);
                } else if((selectedLine-1)>0 && isLineClear(selectedLine-1) == 1 && (selectedLine-1) != Game.lastLanePoped) {
                        Game.lastLanePoped = selectedLine-1;
                        initCar(selectedLine-1);
                }
    }
}



void moveTraffic() {
    for(int carID =0; carID < MAX_NB_CARS; carID++) {
        if(Game.Traffic[carID].active == 1) {
                Game.Traffic[carID].x -= ((Game.Player.speed +5)/8 - Game.Traffic[carID].speed);
                
                if(Game.Traffic[carID].x <= -5*CAR_WIDTH || Game.Traffic[carID].x >= SCREEN_WIDTH + 5*CAR_WIDTH) {
                    if(Game.Traffic[carID].x < 0) {
                        Game.score += 50;
                    } else {
                        Game.score -= 100;
                    }
                    killcar(carID);                    
                } else {
                    collision(carID);
                }
        }
    }
}



void drawCars() {
    for(int carID =0; carID < MAX_NB_CARS; carID++) {
        if(Game.Traffic[carID].active == 1) {
                drawImage(Game.Traffic[carID].sprite, Game.Traffic[carID].x, Game.Traffic[carID].y);
        }
    }
}


