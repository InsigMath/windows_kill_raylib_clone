#include "player_fire.h"
#include "raymath.h"

PlayerFire::~PlayerFire()
{
}

void PlayerFire::Draw()
{
}

void PlayerFire::Update()
{
}

PlayerFire::PlayerFire(Vector2 pos, Vector2 player_pos, float fireSpeed, float fireDamage, float splashDamage,
                       bool hasSplashDamage, bool hasPierceDamage)
    : m_pos(pos), m_fireSpeed(fireSpeed), m_splashDamage(splashDamage), m_hasSplashDamage(hasSplashDamage),
      m_hasPierceDamage(hasPierceDamage)
{
    m_dir = Vector2Normalize(Vector2Subtract(m_pos, player_pos));
}
