#pragma once
#include "Vector2.h"
#include "GameManagerMain.h"

class Player;
class UnitManager;
class Unit;
class Camera;

// 下から来た場合すり抜ける

class Collider : public GameManagerMain {
public:

    Collider(Player& _player, UnitManager* _unitManager, Camera& _camera);

    void Update() override;

private:

    int unitCount;

    // Player, Unitの座標
    Vector2 playerPosition;

    // Player, Unitの画像サイズ
    Vector2 playerSize;

    // 各クラスのインスタンスの保持
    Player& player;
    UnitManager* unitManager;
    Unit* const* units;
    Camera& camera;

    //void HandleCollision(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize);

    /*void HitFeet(Unit* _unit, const Vector2& _unitPosition);*/

    //void HitHead(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize);

    //void HitRight(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize);

    //void HitLeft(Unit* _unit, const Vector2& _unitPosition, const Vector2& _unitSize);

    void HandleNoCollisions();

    void GameOver();
};