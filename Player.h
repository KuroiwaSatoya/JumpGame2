#pragma once
#include "Vector2.h"

class LoadImages;
class Camera;

class Player {
public:

	Player(LoadImages& _loadImages, Camera& _camera);

	void Update();

	void Display();

	void StopJump();

	Vector2 GetPosition() const { return position; }

	Vector2 GetPreviousPosition() const { return previousPosition; }

	Vector2 GetAddedDirection() const { return addedDirection; }

	Vector2 GetSize() const { return size; }

	bool GetIsGround() const { return isGround; }

	void SetPositionX(float _positionX) { position.x = _positionX; }

	void SetPositionY(float _positionY) { position.y = _positionY; }

	void SetIsGround(bool _isGround) { isGround = _isGround; }

	void SetIsDead(bool _isDead) { isDead = _isDead; }

private:

	// 画像
	int image;

	// プレイヤーの画像の拡大率
	float scale;

	// プレイヤーの画像の縦横のサイズ
	Vector2 size;

	// Playerのx,y座標
	Vector2 position, previousPosition;

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

	// Playerが地面に着いているか
	bool isGround;

	// GameOverかどうか
	bool isDead;

	// 横移動
	void Run();

	// ジャンプ
	void Jump();

	// 重力
	void Gravity();

	// インスタンスの宣言
	Camera& camera;
};
