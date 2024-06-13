#ifndef GAME_H
#define GAME_H

#include "raylib.h"

enum class STATE
{
    PLAYING = 0,
    PAUSE,
    UPGRADE_MENU,
    END_GAME,
};

struct Game
{
    bool gotPierceDamage;
    bool gotSplashDamage;
    bool gotMultiFire;
    bool increaseWinSz;
    float fireRate;
    float fireDamage;
    float splashDamage;
    float pierceDamage;
    int screenWidth;
    int screenHeight;
    STATE state;
};

#endif // !GAME_H
