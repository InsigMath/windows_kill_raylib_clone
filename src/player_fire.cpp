#include "player_fire.h"
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

PlayerFire::~PlayerFire()
{
}

void PlayerFire::Draw()
{
    rlPushMatrix();
    rlTranslatef(m_pos.x, m_pos.y, 0.0f);
    rlRotatef(-RAD2DEG * Vector2Angle(m_dir, Vector2{1.0, 0.0}), 0.0, 0.0, 1.0);
    rlTranslatef(-m_pos.x, -m_pos.y, 0.0f);
    DrawEllipse(m_pos.x, m_pos.y, 15.0f, 7.0f, WHITE);
    rlPopMatrix();
}

void PlayerFire::Update()
{
    m_pos = Vector2Add(m_pos, Vector2Scale(m_dir, m_fireSpeed * 1.0f / 60.0f));
}

PlayerFire::PlayerFire(Vector2 pos, Vector2 player_pos, float fireSpeed, float fireDamage, float splashDamage,
                       bool hasSplashDamage, bool hasPierceDamage)
    : m_pos(pos), m_fireSpeed(fireSpeed), m_splashDamage(splashDamage), m_hasSplashDamage(hasSplashDamage),
      m_hasPierceDamage(hasPierceDamage), m_active(true)
{
    m_dir = Vector2Normalize(Vector2Subtract(m_pos, player_pos));
    m_pos = Vector2Add(player_pos, Vector2Scale(m_dir, 50));
}

void PlayerFire::CheckCollisions()
{
    if (m_pos.x >= GetScreenWidth())
    {
        m_active = false;
        SetWindowSize(GetScreenWidth() + 10, GetScreenHeight());
    }
    if (m_pos.x < 0)
    {
        m_active = false;
    }
    if (m_pos.y >= GetScreenHeight())
    {
        m_active = false;
    }
    if (m_pos.y < 0)
    {
        m_active = false;
    }
}
