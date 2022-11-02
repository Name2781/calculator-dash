#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "renderwindow.hpp"
#include "gameobject.hpp"
#include "vector2.hpp"
#include "background.hpp"

RenderWindow window("Calculator Dash", 800, 600);
bool gameRunning = true;
SDL_Event event;
Background background(100.0f, 100.0f, 0.25f, 0.25f, &window);

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

    background.Draw();

    window.Show();
}

void Clean()
{
    delete &window;
    delete &event;
    delete &background;
    SDL_Quit();
}