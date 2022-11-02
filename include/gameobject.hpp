#pragma once

#include <SDL.h>
#include <SDL_image.h>

#include "vector2.hpp"

class GameObject
{
    public:
        Vector2 pos;
        Vector2 scale;
        Vector2 sPos;
        Vector2 sScale;
        Vector2 fScale;
};