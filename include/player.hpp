#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "renderwindow.hpp"
#include "gameobject.hpp"
#include "vector2.hpp"

class Player : GameObject
{
    private:
        RenderWindow* window;
        SDL_Texture* texture;
    public:
        Player(float px, float py, float pw, float ph, RenderWindow* pWindow);
        ~Player();
        void LoadTexture(SDL_Texture* texture);
        void Update();
        void Draw();
};