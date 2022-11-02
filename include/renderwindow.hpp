#pragma once

#include <iostream>

#include <SDL.h>
#include <SDL_image.h>

#include "gameobject.hpp"

class RenderWindow
{
    private:
        SDL_Window* window = NULL;
        SDL_Renderer* renderer = NULL;
    public:
        RenderWindow(const char* title, int width, int height);
        ~RenderWindow();
        SDL_Texture* LoadTexture(const char* filepath);
        void Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
        void Clear();
        void Show();
        SDL_Renderer* GetRenderer();
};