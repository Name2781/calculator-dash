#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "renderwindow.hpp"
#include "gameobject.hpp"
#include "vector2.hpp"

class Background : GameObject
{
    private:
        RenderWindow* window;
        SDL_Texture* texture;
    public:
        Background(float px, float py, float pw, float ph, RenderWindow* pWindow);
        ~Background();
        void LoadTexture(SDL_Texture* pTexture);
        void Update();
        void Draw();
};