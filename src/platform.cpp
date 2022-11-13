#include "platform.hpp"

Platform::Platform(float px, float py, float pw, float ph, RenderWindow* pWindow)
{
    pos.x = px;
    pos.y = py;
    scale.x = pw;
    scale.y = ph;

    sPos.x = 64;
    sPos.y = 0;
    sScale.x = 64;
    sScale.y = 64;

    fScale.x = sScale.x * scale.x;
    fScale.y = sScale.y * scale.y;

    window = pWindow;
}

Platform::~Platform()
{
    delete window;
    SDL_DestroyTexture(texture);
}

void Platform::LoadTexture(SDL_Texture* pTexture)
{
    texture = pTexture;
}

void Platform::Update()
{

}

void Platform::Draw()
{
    SDL_Rect src;
    src.x = sPos.x;
    src.y = sPos.y;
    src.w = sScale.x;
    src.h = sScale.y;

    SDL_Rect dest;
    dest.x = pos.x;
    dest.y = pos.y;
    dest.w = sScale.x * scale.x;
    dest.h = sScale.y * scale.y;

    window->Draw(texture, src, dest);
}