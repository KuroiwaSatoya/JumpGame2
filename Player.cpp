#include "Player.h"
#include "DxLib.h"
#include <iostream>

Player::Player(LoadImages& _loadImages, Camera& _camera) : camera(_camera){

	image = _loadImages.playerImage;

	// Vector2��float�^�Ȃ̂ŁA�ꎞ�I�ɕϐ����쐬
	int width, height;
	GetGraphSize(image, &width, &height);
	scale = 0.15f;

	// float�ɕϊ�����Vector2�ɑ��
	size = Vector2(width * scale, height * scale);

	position = Vector2(600, 300);

	speed = 400;

	jumpForce = 500;

	jumpTimer = 0;

	isJump = false;

	gravity = 10;

	isGround = false;

	isDead = false;

	deltaTime = DeltaTime::GetInstance().GetDeltaTime();

	cameraY = camera.GetCameraY();

}

void Player::Update() {

	if (!isDead) {
		cameraY = camera.GetCameraY();
		//std::cout << isGround << std::endl;

		Run();
		Jump();
		Gravity();

		deltaTime = DeltaTime::GetInstance().GetDeltaTime();

		// direction.x,y�ɍ��킹�č��W��ύX
		if (direction.x <= 0 && position.x > SCREEN_ORIGIN) {

			position.x += direction.x * deltaTime;

		}
		else if (position.x <= SCREEN_ORIGIN) {

			position.x = SCREEN_ORIGIN;

		}

		if (direction.x >= 0 && position.x < SCREEN_WIDTH - size.x) {

			position.x += direction.x * deltaTime;

		}
		else if (position.x >= SCREEN_WIDTH - size.x) {

			position.x = SCREEN_WIDTH - size.x;

		}

		if (direction.y <= 0) {

			position.y += direction.y * deltaTime;

		}

		if (direction.y >= 0) {

			position.y += direction.y * deltaTime;

		}

		direction.x = 0;
		direction.y = 0;
	}
}

void Player::Display() {

	if (!isDead) {
		// �g�債�ĕ`��ł���
		DrawExtendGraphF(
			position.x, position.y - cameraY, // ������W
			position.x + size.x, position.y + size.y - cameraY, // �E�����W
			image, TRUE);
	}
	else {
		DrawExtendGraphF(
			position.x + size.x, position.y + size.y - cameraY,
			position.x, position.y - cameraY,
			image, TRUE);
	}

}

void Player::Run() {

	// A�A���L�[��������Ă����獶�ցAD�A���L�[��������Ă�����E�֍s���B
   // ������Ă��Ȃ��A�������͗���������Ă����瓮���Ȃ�
	if (CheckHitKey(KEY_INPUT_A) || CheckHitKey(KEY_INPUT_LEFT)) {

		if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT)) {

			direction.x = 0;

		}
		else {
			direction.x -= speed;
		}

	}
	else if (CheckHitKey(KEY_INPUT_D) || CheckHitKey(KEY_INPUT_RIGHT)) {

		direction.x += speed;

	}
	else {
		direction.x = 0;
	}

}

void Player::Jump() {

	// �X�y�[�X�L�[��������Ă�Ȃ�
	if (CheckHitKey(KEY_INPUT_SPACE) || CheckHitKey(KEY_INPUT_UP)) {

		if (isGround) {
			isJump = true;
		}

		jumpTimer += deltaTime;

		if (isJump) {
			if (jumpTimer <= JUMP_TIME) {
				addedDirection.y = -jumpForce;
			}
			else {
				isJump = false;
			}
		}
	}
	// ������Ă��Ȃ��Ȃ�directionY��0��
	else if (isGround) {
		jumpTimer = 0;
		StopJump();
	}
	else {
		isJump = false;
	}
	direction.y += addedDirection.y;
}

void Player::StopJump() {

	addedDirection.y = 0;

}

void Player::Gravity() {

	if (!isGround) {

		addedDirection.y += gravity;
	}
	direction.y += addedDirection.y;
}