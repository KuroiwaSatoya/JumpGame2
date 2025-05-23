#include "UnitManager.h"
#include <cstdlib>
//#include <iostream> // ��ŏ���

UnitManager::UnitManager(Camera& _camera) : camera(_camera) {

    movement = 49;
    cameraY = camera.GetCameraY();
    lastCameraY = cameraY;
    unitCount = MAX_UNITS;

    deltaTime = DeltaTime::GetInstance().GetDeltaTime();

    for (int i = 0; i < MAX_UNITS; ++i) {
        units[i] = new Unit(camera, i == 0); // �ŏ�����true
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

    // �J�����̈ړ������ɉ����ăX�|�[��
    cameraY = camera.GetCameraY();
    
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

            // ��ʊO�ɏo����폜
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
            units[i]->Initialization();
            break;
        }
    }
}

void UnitManager::Display() {
    for (int i = 0; i < MAX_UNITS; ++i) {
        if (units[i]) {
            units[i]->Display();
        }
    }
}