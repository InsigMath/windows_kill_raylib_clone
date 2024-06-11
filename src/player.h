#ifndef PLAYER_H

#include "raylib.h"

class Player {
public:
  Player() = default;
  Player(Player &&) = default;
  Player(const Player &) = default;

  Player(Vector2 pos) : m_pos(pos), m_health(10), m_mov_speed(500) {}

  Player &operator=(Player &&) = default;
  Player &operator=(const Player &) = default;
  ~Player() = default;

public:
  void Draw();
  void Update();

public:
  Vector2 m_pos;
  int m_health;
  float m_mov_speed;

private:
};

#endif // !PLAYER_H
