#include "Unit.h"
#include "Screen.h"
#include "DxLib.h"
#include <cstdlib>
//#include <iostream> // 後で消す

// 1つ目のUnitの初期化
Unit::Unit(Camera& _camera, bool _isAppearing) : camera(_camera) {

	// GetColor(255, 255, 255)と同じ(16進数の色表記でOK)
	unitColor = 0xFFFFFF;

	unitLineColor = 0x000000;

	size = Vector2(200, 30);

	position = Vector2((SCREEN_WIDTH - size.x) / 2, (SCREEN_HEIGHT - size.y) * 2 / 3);

	speed = 0, baseSpeed = 500.0f, addSpeed = 3.0f;

	// 右から来るか左から来るかをランダムに設定
	isComingFromLeft = rand() % 2 == 0;

	isAppearing = _isAppearing;

	isStop = false;

	cameraY = camera.GetCameraY();
}

void Unit::Update(float _deltaTime) {

	cameraY = camera.GetCameraY();

	if (isAppearing && !isStop) {

		if (isComingFromLeft) {

			position.x += speed * _deltaTime;

		}
		else {

			position.x -= speed * _deltaTime;

		}
	}
}

void Unit::Display() {

	if (isAppearing) {

		DrawBox(
			// 描画する四角形の左上頂点
			position.x, position.y - cameraY,
			// 右下頂点
			position.x + size.x, position.y + size.y - cameraY,
			//塗りつぶすか
			unitColor, TRUE);

		// 縁取り
		DrawBox(
			// 描画する四角形の左上頂点
			position.x, position.y - cameraY,
			// 右下頂点
			position.x + size.x, position.y + size.y - cameraY,
			//塗りつぶすか
			unitLineColor, FALSE);
	}
}

void Unit::Initialization() {

	// GetColor(255, 255, 255)と同じ(16進数の色表記でOK)
	unitColor = 0xFFFFFF;

	unitLineColor = 0x000000;

	size = Vector2(200, 30);

	// speedをbaseSpeed～baseSpeed+300の間に設定
	if (baseSpeed <= MAX_SPEED) {
		baseSpeed += addSpeed;
	}

	speed = baseSpeed + static_cast<float>(rand()) / RAND_MAX * 300.0f;

	// 右から来るか左から来るかをランダムに設定
	isComingFromLeft = rand() % 2 == 0;

	float y = cameraY + 250.0f + static_cast<float>(rand()) / RAND_MAX * 100.0f;

	//std::cout << cameraY << std::endl;

	if (isComingFromLeft) {

		position = Vector2(SCREEN_ORIGIN - size.x + 1, y);

	}
	else {
		position = Vector2(SCREEN_WIDTH - 1, y);
	}

	isAppearing = true;

	isStop = false;
}

void Unit::Deactivate() {

	isAppearing = false;

}