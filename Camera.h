#pragma once
#include "GameManagerMain.h"
#include "DeltaTime.h"

class Camera : public GameManagerMain {
public:

	Camera();

	void Update() override;

	float GetCameraY() const { return cameraY; };

private:

	// カメラの座標
	float cameraY;

	// カメラの移動速度
	float speed, addSpeed;

	const float MAX_SPEED = 100.0f;

	// デルタタイム
	float deltaTime;

	// 開始から3秒は動かないようにする
	bool isStartGame;

	float timer;

	float startMoveTime;
};
