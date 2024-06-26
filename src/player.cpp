#include "player.h"
#include "raylib.h"
#include "raymath.h"
#include "rlgl.h"

#include <algorithm>
#include <cmath>

void Player::Draw() {
  rlBegin(RL_TRIANGLES);
  rlColor4ub(255, 255, 255, 255);
  for (float i = 0.0f; i < 360.0f; i += 0.01f) {
    float xMajR1 = 30.0f * std::clamp(cosf(DEG2RAD * i), -1.0f, 1.0f) + m_pos.x;
    float yMajR1 = 30.0f * std::clamp(sinf(DEG2RAD * i), -1.0f, 1.0f) + m_pos.y;
    float xMinR1 = 23.0f * std::clamp(cosf(DEG2RAD * i), -1.0f, 1.0f) + m_pos.x;
    float yMinR1 = 23.0f * std::clamp(sinf(DEG2RAD * i), -1.0f, 1.0f) + m_pos.y;

    float xMajR2 =
        30.0f * std::clamp(cosf(DEG2RAD * (i + 1.0f)), -1.0f, 1.0f) + m_pos.x;
    float yMajR2 =
        30.0f * std::clamp(sinf(DEG2RAD * (i + 1.0f)), -1.0f, 1.0f) + m_pos.y;
    float xMinR2 =
        23.0f * std::clamp(cosf(DEG2RAD * (i + 1.0f)), -1.0f, 1.0f) + m_pos.x;
    float yMinR2 =
        23.0f * std::clamp(sinf(DEG2RAD * (i + 1.0f)), -1.0f, 1.0f) + m_pos.y;

    rlVertex2f(xMinR1, yMinR1);
    rlVertex2f(xMajR1, yMajR1);
    rlVertex2f(xMajR2, yMajR2);

    rlVertex2f(xMinR1, yMinR1);
    rlVertex2f(xMinR2, yMinR2);
    rlVertex2f(xMajR2, yMajR2);
  }
  rlEnd();
}

void Player::Update() {
  auto velocity = Vector2Zero();
  if (IsKeyDown(KEY_D)) {
    velocity.x = 1.0f;
  }
  if (IsKeyDown(KEY_A)) {
    velocity.x = -1.0f;
  }
  if (IsKeyDown(KEY_W)) {
    velocity.y = -1.0f;
  }
  if (IsKeyDown(KEY_S)) {
    velocity.y = 1.0f;
  }

  if (Vector2Length(velocity) > 1.0f) {
    velocity = Vector2Normalize(velocity);
  }

  m_pos = Vector2Add(m_pos, Vector2Scale(velocity, m_mov_speed * 1.0f / 60.0f));
}
