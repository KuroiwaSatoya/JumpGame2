#include "Collider.h"
#include "Unit.h"
#include "UnitManager.h"
#include "Player.h"
#include "Camera.h"
#include "Parameter.h"
#include <cmath>
#include <algorithm>
#include <iostream> // 後で消す

using namespace std;

Collider::Collider(Player& _player, UnitManager* _unitManager, Camera& _camera) : player(_player), camera(_camera) {

    unitManager = _unitManager;

    units = unitManager->GetUnits();

    unitCount = unitManager->GetUnitCount();

    playerPosition = _player.GetPosition();

    playerSize = _player.GetSize();

}

void Collider::Update() {

    std::cout << player.GetAddedDirection().y << std::endl;

    // プレイヤーの位置を取得
    Vector2 playerPosition = player.GetPosition();
    float cameraY = camera.GetCameraY();

    // 衝突判定
    bool hasCollision = false;

    // 地面判定
    bool isGround = false;

    // 乗ったユニットの中の最も下にあるもののY座標
    float closestFootY = FLT_MAX;

    // プレイヤーを補正するためのY
    float correctedY = playerPosition.y;

    Vector2 previousPlayerPosition = player.GetPreviousPosition();
    Vector2 currentPlayerPosition = player.GetPosition();

    float previousBottomY = previousPlayerPosition.y + playerSize.y;
    float currentBottomY = currentPlayerPosition.y + playerSize.y;

    // Needleに衝突した場合
    if (playerPosition.y + playerSize.y - cameraY > SCREEN_HEIGHT - sqrt(3.0f) * 80) {
        GameOver();
        return;
    }

    for (int i = 0; i < unitCount; ++i) {
        Unit* unit = units[i];
        if (!unit || !unit->GetIsAppearing()) continue;

        Vector2 unitPosition = unit->GetPosition();
        Vector2 unitSize = unit->GetSize();

        if (playerPosition.x < unitPosition.x + unitSize.x &&
            playerPosition.x + playerSize.x > unitPosition.x &&
            playerPosition.y < unitPosition.y + unitSize.y &&
            playerPosition.y + playerSize.y > unitPosition.y) {

            float overlapX = min(playerPosition.x + playerSize.x, unitPosition.x + unitSize.x)
                - max(playerPosition.x, unitPosition.x);
            float overlapY = min(playerPosition.y + playerSize.y, unitPosition.y + unitSize.y)
                - max(playerPosition.y, unitPosition.y);

            if (overlapY < overlapX) {
                // 上から当たっている（足場）
                if (previousBottomY <= unitPosition.y && currentBottomY >= unitPosition.y) {
                    if (currentPlayerPosition.y > previousPlayerPosition.y) {
                        if (unitPosition.y < closestFootY) {
                            closestFootY = unitPosition.y;
                            correctedY = unitPosition.y - playerSize.y;
                            isGround = true;
                            unit->SetIsStop(true);
                        }
                    }
                }
                //else {
                //    //HitHead(unit, unitPosition, unitSize);
                //}
            }
            //else {
            //    if (playerPosition.x + playerSize.x / 2 < unitPosition.x + unitSize.x / 2) {
            //        //HitRight(unit, unitPosition, unitSize);
            //    }
            //    else {
            //        //HitLeft(unit, unitPosition, unitSize);
            //    }
            //}

            hasCollision = true;
        }
    }

    if (isGround) {
        player.SetIsGround(true);
        player.SetPositionY(correctedY);
    }
    else {
        player.SetIsGround(false);
    }

    if (!hasCollision) {
        HandleNoCollisions();
    }
}

//void Collider::HandleCollision(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize) {
//
//    float overlapX = min(playerPosition.x + playerSize.x, _unitPosition.x + _unitSize.x) 
//        - max(playerPosition.x, _unitPosition.x);
//    float overlapY = min(playerPosition.y + playerSize.y, _unitPosition.y + _unitSize.y) 
//        - max(playerPosition.y, _unitPosition.y);
//
//    if (overlapY < overlapX) {
//        if (playerPosition.y + playerSize.y / 2 < _unitPosition.y + _unitSize.y / 2) {
//            HitFeet(_unit, _unitPosition);
//        }
//        else {
//            HitHead(_unit, _unitPosition, _unitSize);
//        }
//    }
//    else {
//        if (playerPosition.x + playerSize.x / 2 < _unitPosition.x + _unitSize.x / 2) {
//            HitRight(_unit, _unitPosition, _unitSize);
//        }
//        else {
//            HitLeft(_unit, _unitPosition, _unitSize);
//        }
//    }
//}

//// 当たった場合の処理 足からぶつけた
//void Collider::HitFeet(Unit* _unit, const Vector2& _unitPosition) {
//
//    _unit->SetIsStop(true);
//
//    // PlayerのisGroundをtrueにする
//    player.SetIsGround(true);
//
//    // PlayerがUnitにめり込まないようにY座標を調整
//    player.SetPositionY(_unitPosition.y - playerSize.y);
//
//}

//// 頭をぶつけた場合
//void Collider::HitHead(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize) {
//
//    // PlayerがUnitより上に行かないようにY座標を調整
//    player.SetPositionY(_unitPosition.y + _unitSize.y);
//
//    player.StopJump();
//
//    player.SetIsGround(false);
//
//}
//
//// 体の右側がぶつかった場合
//void Collider::HitRight(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize) {
//
//    player.SetPositionX(_unitPosition.x - playerSize.x);
//
//}
//
//// 左側がぶつかった場合
//void Collider::HitLeft(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize) {
//
//    player.SetPositionX(_unitPosition.x + _unitSize.x);
//
//}

// 当たってない場合の処理
void Collider::HandleNoCollisions() {

    player.SetIsGround(false);

}

void Collider::GameOver() {

    player.SetIsDead(true);

}