#pragma once

#include <SDL.h>
#include <SDL_image.h>

class GameObject
{
    public:
        float x = 0;
        float y = 0;
        float w = 1;
        float h = 1;
        int sx = 0;
        int sy = 0;
        int sw = 64;
        int sh = 64;
        float fw = 0;
        float fh = 0;
        SDL_Texture* texture;
        
        GameObject(float px, float py, float pw, float ph, int psx, int psy, int psw, int psh);
        ~GameObject();
        void Update();
        void LoadTexture(SDL_Texture* ptexture);

        SDL_Texture* GetTexture();
};