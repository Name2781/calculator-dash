#include <iostream>
#include <vector>

#include <SDL.h>
#include <SDL_image.h>

#include "renderwindow.hpp"
#include "gameobject.hpp"
#include "vector2.hpp"
#include "background.hpp"
#include "ground.hpp"
#include "player.hpp"
#include "platform.hpp"

RenderWindow window("Calculator Dash", 800, 600);
bool gameRunning = true;
SDL_Event event;
Background background(0.0f, 0.0f, 1.0f, 1.0f, &window);
Ground ground(0.0f, 450.0f, 1.0f, 1.0f, &window);
Player player(0.0f, 0.0f, 1.0f, 1.0f, &window);
std::vector<Platform> platforms; //broken

Platform pl1 = Platform(200.0f, 300.0f, 1.0f, 1.0f, &window); //broken
Platform pl2 = Platform(400.0f, 300.0f, 1.0f, 1.0f, &window); //broken

void Init();
void Update();
void Draw();
void Clean();

int main(int argc, char* args[])
{
    if (SDL_Init(SDL_INIT_VIDEO) > 0)
    {
        std::cout << "SDL_INIT_VIDEO FAILED. ERROR: " << SDL_GetError() << std::endl;
    }

    if (!IMG_Init(IMG_INIT_PNG))
    {
        std::cout << "IMG_INIT_PNG FAILED. ERROR: " << IMG_GetError() << std::endl;
    }

    Init();

    const float timeStep = 1.0f / 60.0f;
    float accumulator = 0.0f;
    float currentTime = SDL_GetTicks() * 0.001f;

    while (gameRunning == true)
    {
        float newTime = SDL_GetTicks() * 0.001f;
        float frameTime = newTime - currentTime;

        currentTime = newTime;
        accumulator += frameTime;
        while (accumulator >= timeStep)
        {
            while (SDL_PollEvent(&event))
            {
                if (event.type == SDL_QUIT)
                {
                    gameRunning = false;
                }
            }

            accumulator -= timeStep;
        }

        //const float alpha = accumulator / timeStep;
        
        Update();
        Draw();
    }

    Clean();

    return 0;
}

void Init()
{
    background.LoadTexture(window.LoadTexture("res/images/game_background.png"));
    ground.LoadTexture(window.LoadTexture("res/images/game_ground.png"));
    player.LoadTexture(window.LoadTexture("res/images/game_spritesheet.png"));

    pl1.LoadTexture(window.LoadTexture("res/images/game_spritesheet.png")); //broken
    platforms.push_back(pl1); //broken

    pl2.LoadTexture(window.LoadTexture("res/images/game_spritesheet.png")); //broken
    platforms.push_back(pl2); //broken
}

void Update()
{
    background.Update();
    ground.Update();
    player.Update();
    for (int i = 0; i < platforms.size() - 1; i++) //broken
    {
        platforms[i].Update(); //broken
    }
}

void Draw()
{
    window.Clear();

    background.Draw();
    ground.Draw();
    player.Draw();
    for (int i = 0; i < platforms.size() - 1; i++) //broken
    {
        platforms[i].Draw(); //broken
    }

    window.Show();
}

void Clean()
{
    delete &window;
    delete &event;
    delete &background;
    delete &ground;
    delete &player;

    delete &pl1;
    delete &pl2;
    SDL_Quit();
}