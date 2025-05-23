#include "Camera.h"
#include "DeltaTime.h"
//#include <iostream> // Œã‚ÅÁ‚·

Camera::Camera() {

	cameraY = 0;

	speed = 30;

	addSpeed = 1.0f;

	deltaTime = DeltaTime::GetInstance().GetDeltaTime();

	timer = 0;

	isStartGame = false;
}

void Camera::Update() {

	deltaTime = DeltaTime::GetInstance().GetDeltaTime();

	if (!isStartGame) {
		timer += deltaTime;
		if (timer >= START_MOVE_TIME) {
			isStartGame = true;
		}
	}
	else {
		if (speed <= MAX_SPEED) {
			speed += addSpeed * deltaTime;
		}
		cameraY -= speed * deltaTime;
	}

	//std::cout << speed << std::endl;
}