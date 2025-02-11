#pragma once
#include "battle_game/core/unit.h"

namespace battle_game::unit {
class Rocket_Launcher : public Unit {
 public:
  Rocket_Launcher(GameCore *game_core, uint32_t id, uint32_t player_id);
  void Render() override;
  void Update() override;
  [[nodiscard]] bool IsHit(glm::vec2 position) const override;
  bool attack_speed_relevant_() override;
  void AddAttackSpeed() override;

 protected:
  void TankMove(float move_speed, float rotate_angular_speed);
  void TurretRotate();
  void Fire();
  [[nodiscard]] const char *UnitName() const override;
  [[nodiscard]] const char *Author() const override;

  float turret_rotation_{0.0f};
  float attack_speed_{0.8f};
  uint32_t fire_count_down_{0};
  uint32_t mine_count_down_{0};
};
}  // namespace battle_game::unit
