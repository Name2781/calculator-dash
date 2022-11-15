#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "renderwindow.hpp"
#include "gameobject.hpp"
#include "vector2.hpp"

class Platform : GameObject
{
    private:
        RenderWindow* window;
        SDL_Texture* texture;
    public:
        Platform(float px, float py, float pw, float ph, RenderWindow* pWindow);
        Platform()
        {
            
        }
        ~Platform();
        void LoadTexture(SDL_Texture* pTexture);
        void Update();
        void Draw();
};