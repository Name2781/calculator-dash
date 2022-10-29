#include "renderwindow.hpp"

RenderWindow::RenderWindow(const char* title, int width, int height)
{
    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    if (window == NULL)
    {
        std::cout << "WINDOW INIT FAILED. ERROR: " << SDL_GetError() << std::endl;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

RenderWindow::~RenderWindow()
{
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
}

SDL_Texture* RenderWindow::LoadTexture(const char* filepath)
{
    SDL_Texture* texture = NULL;
    texture = IMG_LoadTexture(renderer, filepath);
    if (texture == NULL)
    {
        std::cout << "TEXTURE LOAD FAILED. FILEPATH: " << filepath << " ||| ERROR: " << IMG_GetError();
    }

    return texture;
}

void RenderWindow::Draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
    SDL_RenderCopy(renderer, texture, &src, &dest);
}

void RenderWindow::DrawObject(GameObject& gameObject)
{
    SDL_Rect src;
    src.x = gameObject.GetSX();
    src.y = gameObject.GetSY();
    src.w = gameObject.GetSW();
    src.h = gameObject.GetSH();

    SDL_Rect dest;
    dest.x = gameObject.GetX();
    dest.y = gameObject.GetY();
    dest.w = gameObject.GetSW() * gameObject.GetW();
    dest.h = gameObject.GetSH() * gameObject.GetH();

    SDL_RenderCopy(renderer, gameObject.GetTexture(), &src, &dest);
}

void RenderWindow::Clear()
{
    SDL_RenderClear(renderer);
}

void RenderWindow::Show()
{
    SDL_RenderPresent(renderer);
}