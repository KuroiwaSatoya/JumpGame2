#include "Collider.h"
#include <cmath>
#include <algorithm>
//#include <iostream> // ��ŏ���

using namespace std;

Collider::Collider(Player& _player, UnitManager* _unitManager, Camera& _camera) : player(_player), camera(_camera) {

    unitManager = _unitManager;

    units = unitManager->GetUnits();

    unitCount = unitManager->GetUnitCount();

    playerPosition = _player.GetPosition();

    playerSize = _player.GetSize();

    cameraY = camera.GetCameraY();
}

void Collider::Update() {

    // ���݈ʒu���X�V
    playerPosition = player.GetPosition();

    cameraY = camera.GetCameraY();

    bool hasCollision = false;

    if (playerPosition.y + playerSize.y - cameraY > SCREEN_HEIGHT - sqrt(3.0f) * 80) {
        GameOver();
        hasCollision = true;
    }

    for (int i = 0; i < unitCount; ++i) {
        Unit* unit = units[i];

        if (!unit || !unit->GetIsAppearing())
            continue;

        Vector2 unitPosition = unit->GetPosition();
        Vector2 unitSize = unit->GetSize();

        if (playerPosition.x < unitPosition.x + unitSize.x &&
            playerPosition.x + playerSize.x > unitPosition.x &&
            playerPosition.y < unitPosition.y + unitSize.y &&
            playerPosition.y + playerSize.y > unitPosition.y) {

            // �Փ˂��Ă���ꍇ
            HandleCollision(unit, unitPosition, unitSize);
            hasCollision = true;
            break;
        }
    }

    if (!hasCollision) {
        HandleNoCollisions();
    }
}

void Collider::HandleCollision(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize) {

    float overlapX = min(playerPosition.x + playerSize.x, _unitPosition.x + _unitSize.x) 
        - max(playerPosition.x, _unitPosition.x);
    float overlapY = min(playerPosition.y + playerSize.y, _unitPosition.y + _unitSize.y) 
        - max(playerPosition.y, _unitPosition.y);

    if (overlapY < overlapX) {
        if (playerPosition.y + playerSize.y / 2 < _unitPosition.y + _unitSize.y / 2) {
            HitFeet(_unit, _unitPosition);
        }
        else {
            HitHead(_unit, _unitPosition, _unitSize);
        }
    }
    else {
        if (playerPosition.x + playerSize.x / 2 < _unitPosition.x + _unitSize.x / 2) {
            HitRight(_unit, _unitPosition, _unitSize);
        }
        else {
            HitLeft(_unit, _unitPosition, _unitSize);
        }
    }
}

// ���������ꍇ�̏��� ������Ԃ���
void Collider::HitFeet(Unit* _unit, const Vector2& _unitPosition) {

    _unit->SetIsStop(true);

    // Player��isGround��true�ɂ���
    player.SetIsGround(true);

    // Player��Unit�ɂ߂荞�܂Ȃ��悤��Y���W�𒲐�
    player.SetPositionY(_unitPosition.y - playerSize.y);

}

// �����Ԃ����ꍇ
void Collider::HitHead(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize) {

    // Player��Unit����ɍs���Ȃ��悤��Y���W�𒲐�
    player.SetPositionY(_unitPosition.y + _unitSize.y);

    player.StopJump();

    player.SetIsGround(false);

}

// �̂̉E�����Ԃ������ꍇ
void Collider::HitRight(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize) {

    player.SetPositionX(_unitPosition.x - playerSize.x);

}

// �������Ԃ������ꍇ
void Collider::HitLeft(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize) {

    player.SetPositionX(_unitPosition.x + _unitSize.x);

}

// �������ĂȂ��ꍇ�̏���
void Collider::HandleNoCollisions() {

    player.SetIsGround(false);

}

void Collider::GameOver() {

    player.SetIsDead(true);

}