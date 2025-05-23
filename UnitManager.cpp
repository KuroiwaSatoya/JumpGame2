#include "UnitManager.h"
#include "Parameter.h"
#include "DeltaTime.h"
#include "Camera.h"
#include "Player.h"
#include <cstdlib>
//#include <iostream> // 後で消す

UnitManager::UnitManager(Player& _player, Camera& _camera) : camera(_camera), player(_player) {

    movement = 49;
    lastCameraY = camera.GetCameraY();
    unitCount = MAX_UNITS;

    deltaTime = DeltaTime::GetInstance().GetDeltaTime();

    for (int i = 0; i < MAX_UNITS; ++i) {
        units[i] = new Unit(i == 0); // 最初だけtrue
    }
}

UnitManager::~UnitManager() {
    for (int i = 0; i < MAX_UNITS; ++i) {
        delete units[i];
        units[i] = nullptr;
    }
}

void UnitManager::Update() {

    deltaTime = DeltaTime::GetInstance().GetDeltaTime();

    // カメラの移動距離に応じてスポーン
    float cameraY = camera.GetCameraY();
    
    movement += abs(lastCameraY - cameraY);
    //std::cout << movement << std::endl;
    lastCameraY = cameraY;

    if (movement >= SPAWN_INTERVAL) {
        SpawnUnit();
        movement = 0;
    }

    for (int i = 0; i < MAX_UNITS; ++i) {
        if (units[i]) {
            units[i]->Update(deltaTime);

            // 画面外に出たら削除
            Vector2 position = units[i]->GetPosition();
            Vector2 size = units[i]->GetSize();
            if (position.x > SCREEN_WIDTH || position.x + size.x < SCREEN_ORIGIN
                || position.y - cameraY > SCREEN_HEIGHT || position.y + size.y - cameraY < SCREEN_ORIGIN) {
                units[i]->Deactivate();
            }
        }
    }

}

void UnitManager::SpawnUnit() {
    for (int i = 0; i < MAX_UNITS; ++i) {
        if (!units[i]->GetIsAppearing()) {
            units[i]->Initialization(player.GetPosition().y);
            break;
        }
    }
}

void UnitManager::Display() {
    for (int i = 0; i < MAX_UNITS; ++i) {
        if (units[i]) {
            units[i]->Display(camera.GetCameraY());
        }
    }
}