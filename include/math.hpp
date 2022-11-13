#pragma once

struct Math
{
    inline static float Clamp(float min, float max, float val)
    {
        if (val <= min)
        {
            return min;
        }
        else if (val >= max)
        {
            return max;
        }
        else
        {
            return val;
        }
    }
};