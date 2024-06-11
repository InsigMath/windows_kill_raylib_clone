#ifndef PLAYER_FIRE_H
#define PLAYER_FIRE_H

class PlayerFire {
public:
  PlayerFire();
  PlayerFire(PlayerFire &&) = default;
  PlayerFire(const PlayerFire &) = default;
  PlayerFire &operator=(PlayerFire &&) = default;
  PlayerFire &operator=(const PlayerFire &) = default;
  ~PlayerFire();

private:
};

#endif // !PLAYER_FIRE_H
