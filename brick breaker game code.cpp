#include <SDL.h>
#include <stdio.h>
#include <time.h>
#include<windows.h>
SDL_Renderer *rend;
SDL_Surface *block;
SDL_Surface *ball;
SDL_Surface *win;
void destroy();
SDL_Surface *bat;
SDL_Surface *bg;

void gameover();
void winning();
void nextlevel();
void moveball(); 
void ballcollision(); 
void ball_block_collision();

int currentlevel = 1;
SDL_Texture *wintexture;
SDL_Texture *blocktexture;
SDL_Texture *balltexture;
SDL_Texture *bgtexture;
SDL_Texture *battexture;
bool quit = false;
bool inmenu = true;
SDL_Event event;
float dbc = 0;
	float no_of_blocks = 21;
float blockw = 80;
float blockh = 35;
float bgw = 800;
float bgh = 600;
float bgwmin = 0;
float bghmin = 0;
float ballx = bgw / 2;
float bally = bgh - 80;
float batx = bgw / 2;
float baty = bgh - 30;

SDL_Rect blockrect[3][7];
SDL_Rect ballrect;

float ballvelx = 0.5;
float ballvely = 0.5;
void initializeblock()
{
	if (currentlevel ==1)
{
	
   blockrect[0][0]={50,50,blockw,blockh};
	blockrect[0][1]={150,50,blockw,blockh};
	blockrect[0][2]={250,50,blockw,blockh};
	blockrect[0][3]={350,50,blockw,blockh};
	blockrect[0][4]={450,50,blockw,blockh};
	blockrect[0][5]={550,50,blockw,blockh};
	blockrect[0][6]={650,50,blockw,blockh};
	blockrect[1][0]={50,100,blockw,blockh};
	blockrect[1][1]={150,100,blockw,blockh};
	blockrect[1][2]={250,100,blockw,blockh};
	blockrect[1][3]={350,100,blockw,blockh};
	blockrect[1][4]={450,100,blockw,blockh};
	blockrect[1][5]={550,100,blockw,blockh};
	blockrect[1][6]={650,100,blockw,blockh};
	blockrect[2][0]={50,150,blockw,blockh};
	blockrect[2][1]={150,150,blockw,blockh};
	blockrect[2][2]={250,150,blockw,blockh};
	blockrect[2][3]={350,150,blockw,blockh};
	blockrect[2][4]={450,150,blockw,blockh};
	blockrect[2][5]={550,150,blockw,blockh};
	blockrect[2][6]={650,150,blockw,blockh};
}
if (currentlevel == 2)
{
    blockrect[0][0] = {50, 50, blockw, blockh};
    blockrect[0][1] = {150, 50, blockw, blockh};
    blockrect[0][2] = {250, 50, blockw, blockh};
    blockrect[0][3] = {350, 50, blockw, blockh};
    blockrect[0][4] = {450, 50, blockw, blockh};
    blockrect[0][5] = {550, 50, blockw, blockh};
    blockrect[0][6] = {650, 50, blockw, blockh};
    blockrect[1][0] = {50, 100, blockw, blockh};
    blockrect[1][1] = {150, 100, blockw, blockh};
    blockrect[1][2] = {250, 100, blockw, blockh};
    blockrect[1][3] = {350, 100, blockw, blockh};
    blockrect[1][4] = {450, 100, blockw, blockh};
    blockrect[1][5] = {550, 100, blockw, blockh};
    blockrect[1][6] = {650, 100, blockw, blockh};
    blockrect[2][0] = {50, 150, blockw, blockh};
    blockrect[2][1] = {150, 150, blockw, blockh};
    blockrect[2][2] = {250, 150, blockw, blockh};
    blockrect[2][3] = {350, 150, blockw, blockh};
    blockrect[2][4] = {450, 150, blockw, blockh};
    blockrect[2][5] = {550, 150, blockw, blockh};
    blockrect[2][6] = {650, 150, blockw, blockh};
}

if (currentlevel ==3)
{
	 blockrect[0][0]={50,50,blockw,blockh};
	blockrect[0][1]={150,50,blockw,blockh};
	blockrect[0][2]={250,50,blockw,blockh};
	blockrect[0][3]={350,50,blockw,blockh};
	blockrect[0][4]={450,50,blockw,blockh};
	blockrect[0][5]={550,50,blockw,blockh};
	blockrect[0][6]={650,50,blockw,blockh};
	blockrect[1][0]={50,150,blockw,blockh};
	blockrect[1][1]={150,150,blockw,blockh};
	blockrect[1][2]={250,150,blockw,blockh};
	blockrect[1][3]={350,150,blockw,blockh};
	blockrect[1][4]={450,150,blockw,blockh};
	blockrect[1][5]={550,150,blockw,blockh};
	blockrect[1][6]={650,150,blockw,blockh};
	blockrect[2][0]={50,190,blockw,blockh};
	blockrect[2][1]={150,190,blockw,blockh};
	blockrect[2][2]={250,190,blockw,blockh};
	blockrect[2][3]={350,190,blockw,blockh};
	blockrect[2][4]={450,190,blockw,blockh};
	blockrect[2][5]={550,190,blockw,blockh};
	blockrect[2][6]={650,190,blockw,blockh};

}
}
	
void nextlevel()
{
    ballx = bgw / 2;
    bally = bgh - 80;
    batx = bgw / 2;

    currentlevel++;

    if (currentlevel > 3)
    {
        winning();
    }
    else
    {
    	dbc = 0;
    	ballvelx=0.7;
    	ballvely=0.7;
        initializeblock();
        moveball();
        ballcollision();
        ball_block_collision();
    }
}


void eventhandler()
{
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT)
    {
        quit = true;
    }
    else if (inmenu && event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_s)
        {
            inmenu = false;
        }
        else if (event.key.keysym.sym == SDLK_e)
        {
            quit = true;
        }
    }
    else if (!inmenu && event.type == SDL_KEYDOWN)
    {
        if (event.key.keysym.sym == SDLK_LEFT && batx > 0)
        {
            batx = batx - 1;
        }
        if (event.key.keysym.sym == SDLK_RIGHT && batx < bgw - 80)
        {
            batx = batx + 1;
        }
    }
}

void moveball()
{
    ballx = ballx + ballvelx;
    bally = bally + ballvely;
    if (bgh == ballx && bgw == bally)
    {
        ballvelx = -ballvelx;
        ballvely = -ballvely;
    }
}

void ballcollision()
{
    if (ballx < bgwmin || ballx > bgw - 30)
    {
        ballvelx = -ballvelx;
    }
    if (bally < bghmin)
    {
        ballvely = -ballvely;
    }
    if (bally > bgh - 10) 
    {
        initializeblock();
        gameover();
    }

    int ballscaling = 20;

    if (bally + ballscaling >= baty && bally <= baty + 30)
    {
        if (ballx + ballscaling >= batx && ballx <= batx + 80)
        {
            ballvely = -ballvely;
            bally = baty - ballscaling - 1;
        }
    }
}
//created by ahad
bool ball_block_collision_detect(SDL_Rect rect1, SDL_Rect rect2)
{
    if (rect1.x > rect2.x + rect2.w)
    {
        return false;
    }
    if (rect1.x + rect1.w < rect2.x)
    {
        return false;
    }
    if (rect1.y > rect2.y + rect2.h)
    {
        return false;
    }
    if (rect1.y + rect1.h < rect2.y)
    {
        return false;
    }
    return true;
}

void ball_block_collision()
{
    bool a;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 7; j++)
        {
            a = ball_block_collision_detect(blockrect[i][j], ballrect);
            if (a == true)
            {
                blockrect[i][j].x = 3000;
                ballvely = -ballvely;
                dbc++;
            }
        }
    }
}

void destroy()
{
    SDL_DestroyTexture(battexture);
    SDL_DestroyTexture(blocktexture);
    SDL_DestroyTexture(bgtexture);
    SDL_DestroyTexture(balltexture);
    SDL_FreeSurface(bat);
    SDL_FreeSurface(ball);
    SDL_FreeSurface(bg);
    SDL_DestroyRenderer(rend);
}

void winning()
{
    win = SDL_LoadBMP("win.bmp");
    wintexture = SDL_CreateTextureFromSurface(rend, win);
    SDL_Rect winrect = {0, 0, bgw, bgh};
    SDL_RenderCopy(rend, wintexture, NULL, &winrect);
    SDL_RenderPresent(rend);
    SDL_Delay(1000);
    SDL_Quit();
    destroy();
	}


void gameover()
{
    SDL_Surface *go = SDL_LoadBMP("gameover.bmp");
    SDL_Texture *gotexture = SDL_CreateTextureFromSurface(rend, go);
    SDL_Rect gorect = {0, 0, bgw, bgh};
SDL_RenderCopy(rend, gotexture, NULL, &gorect);
   SDL_RenderPresent(rend);  
   SDL_Delay(4000);  
   destroy();
    SDL_Quit();
	
}

void menu()
{
    SDL_Surface *menu = SDL_LoadBMP("menu.bmp");
    SDL_Texture *menutexture = SDL_CreateTextureFromSurface(rend, menu);
    SDL_Rect menurect = {0, 0, bgw, bgh};
    SDL_RenderCopy(rend, menutexture, NULL, &menurect);
}

int main(int argc, char **argv)
{	 
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Break & Bounce", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
	rend = SDL_CreateRenderer(window, -1, 0);
    

    initializeblock();
    bg = SDL_LoadBMP("background.bmp");
    SDL_Rect bgrect = {0, 0, 800, 600};
    ball = SDL_LoadBMP("ball.bmp");
    bat = SDL_LoadBMP("bat.bmp");
    block = SDL_LoadBMP("block.bmp");
    bgtexture = SDL_CreateTextureFromSurface(rend, bg);
    battexture = SDL_CreateTextureFromSurface(rend, bat);
    blocktexture = SDL_CreateTextureFromSurface(rend, block);
    balltexture = SDL_CreateTextureFromSurface(rend, ball);
    while (!quit)
    {
        eventhandler();
        ballrect = {ballx, bally, 20, 30};
        SDL_Rect batrect = {batx, baty, 80, 30};

        if (inmenu)
        {
            menu();
        }
        else
        {
            moveball();
            ballcollision();
            ball_block_collision();
            if (dbc == no_of_blocks)
            {
                nextlevel();
            }

            SDL_RenderCopy(rend, bgtexture, NULL, &bgrect);
            SDL_RenderCopy(rend, balltexture, NULL, &ballrect);
            SDL_RenderCopy(rend, battexture, NULL, &batrect);

            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 7; j++)
                {
                    SDL_RenderCopy(rend, blocktexture, NULL, &blockrect[i][j]);
                }
            }
        }

        SDL_RenderPresent(rend);
        SDL_RenderClear(rend);
    }

    destroy();
    SDL_Quit();

    return 0;
}
