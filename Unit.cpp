#include "Unit.h"
#include "Screen.h"
#include "DxLib.h"
#include <cstdlib>
//#include <iostream> // ��ŏ���

// 1�ڂ�Unit�̏�����
Unit::Unit(Camera& _camera, bool _isAppearing) : camera(_camera) {

	// GetColor(255, 255, 255)�Ɠ���(16�i���̐F�\�L��OK)
	unitColor = 0xFFFFFF;

	unitLineColor = 0x000000;

	size = Vector2(200, 30);

	position = Vector2((SCREEN_WIDTH - size.x) / 2, (SCREEN_HEIGHT - size.y) * 2 / 3);

	speed = 0, baseSpeed = 500.0f, addSpeed = 3.0f;

	// �E���痈�邩�����痈�邩�������_���ɐݒ�
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
			// �`�悷��l�p�`�̍��㒸�_
			position.x, position.y - cameraY,
			// �E�����_
			position.x + size.x, position.y + size.y - cameraY,
			//�h��Ԃ���
			unitColor, TRUE);

		// �����
		DrawBox(
			// �`�悷��l�p�`�̍��㒸�_
			position.x, position.y - cameraY,
			// �E�����_
			position.x + size.x, position.y + size.y - cameraY,
			//�h��Ԃ���
			unitLineColor, FALSE);
	}
}

void Unit::Initialization() {

	// GetColor(255, 255, 255)�Ɠ���(16�i���̐F�\�L��OK)
	unitColor = 0xFFFFFF;

	unitLineColor = 0x000000;

	size = Vector2(200, 30);

	// speed��baseSpeed�`baseSpeed+300�̊Ԃɐݒ�
	if (baseSpeed <= MAX_SPEED) {
		baseSpeed += addSpeed;
	}

	speed = baseSpeed + static_cast<float>(rand()) / RAND_MAX * 300.0f;

	// �E���痈�邩�����痈�邩�������_���ɐݒ�
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