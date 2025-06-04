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

    // Unit�̍ő�̐�
    static const int MAX_UNITS = 10;
    int unitCount;

    // �ړ������ɉ����ďo��
    float movement, lastCameraY;
    const float SPAWN_INTERVAL = 50.0f;

    float deltaTime;

    // �o��������Unit��Position
    Vector2 position;

    // �C���X�^���X�̐錾
    Unit* units[MAX_UNITS];
    Camera& camera;
    Player& player;

    void SpawnUnit();
};
