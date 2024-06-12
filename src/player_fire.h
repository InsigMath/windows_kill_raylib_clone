#ifndef PLAYER_FIRE_H
#define PLAYER_FIRE_H

#include "raylib.h"

class PlayerFire
{
  public:
    PlayerFire() = default;
    PlayerFire(Vector2 pos, Vector2 player_pos, float fireSpeed, float fireDamage, float splashDamage,
               bool hasSplashDamage, bool hasPierceDamage);

    PlayerFire(PlayerFire &&) = default;
    PlayerFire(const PlayerFire &) = default;
    PlayerFire &operator=(PlayerFire &&) = default;
    PlayerFire &operator=(const PlayerFire &) = default;
    ~PlayerFire();

  public:
    Vector2 m_pos;
    Vector2 m_dir;
    float m_fireSpeed;
    float m_fireDamage;
    float m_splashDamage;
    bool m_hasSplashDamage;
    bool m_hasPierceDamage;
    bool m_active;

  public:
    void Draw();
    void Update();
    int getID()
    {
        return m_ID;
    }

  private:
    int m_ID;
};

#endif // !PLAYER_FIRE_H
