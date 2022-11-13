#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "renderwindow.hpp"
#include "gameobject.hpp"
#include "vector2.hpp"
#include "math.hpp"

class Player : GameObject
{
    private:
        float xVel = 0.0f;
        float yVel = 0.0f;
        float speed = 5.0f;
        float gravity = 0.5f;
        RenderWindow* window;
        SDL_Texture* texture;
    public:
        Player(float px, float py, float pw, float ph, RenderWindow* pWindow);
        ~Player();
        void LoadTexture(SDL_Texture* texture);
        void Update();
        void Draw();
};