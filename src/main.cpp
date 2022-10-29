#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "renderwindow.hpp"
#include "gameobject.hpp"

RenderWindow window("Calculator Dash", 800, 600);;
bool gameRunning = true;
SDL_Event event;
GameObject background(200, 200, 0.125f, 0.125f, 0, 0, 1024, 1024);

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
}

void Update()
{
    background.Update();
}

void Draw()
{
    window.Clear();

    window.DrawObject(background);

    window.Show();
}

void Clean()
{
    delete &window;
    delete &event;
    delete &background;
    SDL_Quit();
}