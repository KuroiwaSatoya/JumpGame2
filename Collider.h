#pragma once
#include "Vector2.h"
#include "GameManagerMain.h"
#include "Player.h"
#include "UnitManager.h"
#include "Unit.h"
#include "Camera.h"

class Collider : public GameManagerMain {
public:

    Collider(Player& _player, UnitManager* _unitManager, Camera& _camera);

    void Update() override;

private:

    int unitCount;

    float cameraY;

    // Player, Unit�̍��W
    Vector2 playerPosition;

    // Player, Unit�̉摜�T�C�Y
    Vector2 playerSize;

    // �e�N���X�̃C���X�^���X�̕ێ�
    Player& player;
    UnitManager* unitManager;
    Unit** units;
    Camera& camera;

    void HandleCollision(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize);

    void HitFeet(Unit* _unit, const Vector2& _unitPosition);

    void HitHead(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize);

    void HitRight(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize);

    void HitLeft(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize);

    void HandleNoCollisions();

    void GameOver();
};