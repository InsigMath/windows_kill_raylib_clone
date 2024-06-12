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
    float fireRate;
    float fireDamage;
    float splashDamage;
    float pierceDamage;
};
