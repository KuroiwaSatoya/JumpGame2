#pragma once
#include "Vector2.h"
#include "StageMain.h"
#include "Camera.h"

class Unit {
public:

	Unit(Camera& _camera, bool _isAppearing);

	~Unit() = default;

	void Update(float _deltaTime);

	void Display();

	void Initialization();

	void Deactivate();

	Vector2 GetPosition() const { return position; }

	Vector2 GetSize() const { return size; }

	bool GetIsAppearing() const { return isAppearing; }

	void SetIsStop(bool _isStop) { isStop = _isStop; }

private:

	// 台の色
	int unitColor, unitLineColor;

	// 台の座標
	Vector2 position;

	// 台の縦幅と横幅
	Vector2 size;

	// 台のスピード
	float speed, baseSpeed, addSpeed;
	const float MAX_SPEED = 700.0f;

	// 台が左右どちらから来るか
	bool isComingFromLeft;

	// 出現しているかどうか
	bool isAppearing;

	// ストップするかどうか
	bool isStop;

	// cameraY
	float cameraY;

	// インスタンスの宣言
	Camera& camera;
};
