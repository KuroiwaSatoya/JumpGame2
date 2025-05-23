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

	// �摜
	int image;

	// �v���C���[�̉摜�̊g�嗦
	float scale;

	// �v���C���[�̉摜�̏c���̃T�C�Y
	Vector2 size;

	// Player��x,y���W
	Vector2 position;

	// Player�̈ړ�����
	Vector2 direction, addedDirection;

	// ���鑬�x
	float speed;

	// �W�����v��
	float jumpForce;

	// �W�����v�Ǘ�
	const float JUMP_TIME = 0.2f;
	float jumpTimer;
	bool isJump;

	// �d�͉����x
	float gravity;

	// Player���n�ʂɒ����Ă��邩
	bool isGround;

	// GameOver���ǂ���
	bool isDead;

	// �f���^�^�C��
	float deltaTime;

	// �J����Y
	float cameraY;

	// ���ړ�
	void Run();

	// �W�����v
	void Jump();

	// �d��
	void Gravity();

	// �C���X�^���X�̐錾
	Camera& camera;
};
