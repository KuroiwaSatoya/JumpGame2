#pragma once
#include "LoadImages.h"
#include "Screen.h"
#include "Vector2.h"
#include "DeltaTime.h"
#include "Camera.h"

class Player {
public:

	Player(LoadImages& _loadImages, Camera& _camera);

	void Update();

	void Display();

	void StopJump();

	Vector2 GetPosition() { return position; }

	Vector2 GetSize() { return size; }

	void SetPositionX(float _positionX) { position.x = _positionX; }

	void SetPositionY(float _positionY) { position.y = _positionY; }

	void SetIsGround(bool _isGround) { isGround = _isGround; }

	void SetIsDead(bool _isDead) { isDead = _isDead; }

	void SetDeltaTime(float _deltaTime) { deltaTime = _deltaTime; }

private:

	// 画像
	int image;

	// プレイヤーの画像の拡大率
	float scale;

	// プレイヤーの画像の縦横のサイズ
	Vector2 size;

	// Playerのx,y座標
	Vector2 position;

	// Playerの移動方向
	Vector2 direction, addedDirection;

	// 走る速度
	float speed;

	// ジャンプ力
	float jumpForce;

	// ジャンプ管理
	const float JUMP_TIME = 0.2f;
	float jumpTimer;
	bool isJump;

	// 重力加速度
	float gravity;

	// Playerが地面に着いているか
	bool isGround;

	// GameOverかどうか
	bool isDead;

	// デルタタイム
	float deltaTime;

	// カメラY
	float cameraY;

	// 横移動
	void Run();

	// ジャンプ
	void Jump();

	// 重力
	void Gravity();

	// インスタンスの宣言
	Camera& camera;
};
