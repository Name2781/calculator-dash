#include "background.hpp"

Background::Background(float px, float py, float pw, float ph, RenderWindow* pWindow)
{
    pos.x = px;
    pos.y = py;
    scale.x = pw;
    scale.y = ph;

    sPos.x = 0;
    sPos.y = 0;
    sScale.x = 1024;
    sScale.y = 1024;

    fScale.x = sScale.x * scale.x;
    fScale.y = sScale.y * scale.y;

    window = pWindow;
}

Background::~Background()
{
    delete window;
    SDL_DestroyTexture(texture);
}

void Background::LoadTexture(SDL_Texture* pTexture)
{
    texture = pTexture;
}

void Background::Update()
{

}

void Background::Draw()
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