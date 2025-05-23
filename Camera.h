#pragma once
#include "GameManagerMain.h"
#include "DeltaTime.h"

class Camera : public GameManagerMain {
public:

	Camera();

	void Update() override;

	float GetCameraY() const { return cameraY; };

private:

	// �J�����̍��W
	float cameraY;

	// �J�����̈ړ����x
	float speed, addSpeed;

	const float MAX_SPEED = 100.0f;

	// �f���^�^�C��
	float deltaTime;

	// �J�n����3�b�͓����Ȃ��悤�ɂ���
	bool isStartGame;

	float timer;

	float startMoveTime;
};
