#include "gameobject.hpp"

GameObject::GameObject(float px, float py, float pw, float ph, int psx, int psy, int psw, int psh)
{
    x = px;
    y = py;
    w = pw;
    h = ph;
    sx = psx;
    sy = psy;
    sw = psw;
    sh = psh;

    fw = sw * w;
    fh = sh * h;
}

GameObject::~GameObject()
{
    SDL_DestroyTexture(texture);
}

void GameObject::Update()
{
    x += 10;
}

void GameObject::LoadTexture(SDL_Texture* ptexture)
{
    texture = ptexture;
}

float GameObject::GetX()
{
    return x;
}

float GameObject::GetY()
{
    return y;
}

float GameObject::GetW()
{
    return w;
}

float GameObject::GetH()
{
    return h;
}

int GameObject::GetSX()
{
    return sx;
}

int GameObject::GetSY()
{
    return sy;
}

int GameObject::GetSW()
{
    return sw;
}

int GameObject::GetSH()
{
    return sh;
}

SDL_Texture* GameObject::GetTexture()
{
    return texture;
}