#include "framerate.hpp"
#include <SDL3/SDL.h>

namespace FRAMERATE {
    bool FRATE::doDelay() {
        auto currentTime = SDL_GetTicks();
        static auto previous = currentTime;
        static auto previousComputeStepTime = currentTime;
        static uint64_t nextExpectedFrameTime = currentTime + (1000.0 / FPS);
        static double extraTick = 0;
        double fpsinc = 1000.0 / FPS;

        computeTime = currentTime - previousComputeStepTime;
        previousComputeStepTime = currentTime;

        if (currentTime < nextExpectedFrameTime) return false;

        auto dif = currentTime - nextExpectedFrameTime;
        nextExpectedFrameTime += (int32_t)fpsinc + (int32_t)extraTick;
        extraTick += (fpsinc - (int32_t)fpsinc) - (int32_t)extraTick;
        if (dif > fpsinc * 2) return false;


        previous = currentTime;
        return true;
    }
}
