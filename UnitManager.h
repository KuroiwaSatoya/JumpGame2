#pragma once
#include "Unit.h"

class Camera;
class Unit;
class Player;

class UnitManager : public StageMain {
public:

    UnitManager(Player& _player, Camera& _camera);
    ~UnitManager();

    void Update() override;

    void Display() override;

    Unit* const* GetUnits() const { return units; }
    int GetUnitCount() const { return unitCount; }

private:

    // Unitの最大の数
    static const int MAX_UNITS = 10;
    int unitCount;

    // 移動距離に応じて出現
    float movement, lastCameraY;
    const float SPAWN_INTERVAL = 50.0f;

    float deltaTime;

    // 出現させるUnitのPosition
    Vector2 position;

    // インスタンスの宣言
    Unit* units[MAX_UNITS];
    Camera& camera;
    Player& player;

    void SpawnUnit();
};
