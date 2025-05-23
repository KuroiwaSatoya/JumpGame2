#include "Player.h"
#include "DxLib.h"
#include <iostream>

Player::Player(LoadImages& _loadImages, Camera& _camera) : camera(_camera){

	image = _loadImages.playerImage;

	// Vector2はfloat型なので、一時的に変数を作成
	int width, height;
	GetGraphSize(image, &width, &height);
	scale = 0.15f;

	// floatに変換してVector2に代入
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

		// direction.x,yに合わせて座標を変更
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
		// 拡大して描画できる
		DrawExtendGraphF(
			position.x, position.y - cameraY, // 左上座標
			position.x + size.x, position.y + size.y - cameraY, // 右下座標
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

	// A、←キーが押されていたら左へ、D、→キーが押されていたら右へ行く。
   // 押されていない、もしくは両方押されていたら動かない
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

	// スペースキーが押されてるなら
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
	// 押されていないならdirectionYを0に
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