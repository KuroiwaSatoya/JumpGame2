#pragma once
#include "Vector2.h"
#include "StageMain.h"

class Unit {
public:

	Unit(bool _isAppearing);

	~Unit() = default;

	void Update(float _deltaTime);

	void Display(float _cameraY);

	void Initialization(float _playerPositionY);

	void Deactivate();

	Vector2 GetPosition() const { return position; }

	Vector2 GetSize() const { return size; }

	bool GetIsAppearing() const { return isAppearing; }

	void SetIsStop(bool _isStop) { isStop = _isStop; }

private:

	// ��̐F
	int unitColor, unitLineColor;

	// ��̍��W
	Vector2 position;

	// ��̏c���Ɖ���
	Vector2 size;

	// ��̃X�s�[�h
	float speed, baseSpeed, addSpeed;
	const float MAX_SPEED = 700.0f;

	// �䂪���E�ǂ��炩�痈�邩
	bool isComingFromLeft;

	// �o�����Ă��邩�ǂ���
	bool isAppearing;

	// �X�g�b�v���邩�ǂ���
	bool isStop;
};
