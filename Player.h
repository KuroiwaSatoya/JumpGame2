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

	// �摜
	int image;

	// �v���C���[�̉摜�̊g�嗦
	float scale;

	// �v���C���[�̉摜�̏c���̃T�C�Y
	Vector2 size;

	// Player��x,y���W
	Vector2 position, previousPosition;

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

	// Player���n�ʂɒ����Ă��邩
	bool isGround;

	// GameOver���ǂ���
	bool isDead;

	// ���ړ�
	void Run();

	// �W�����v
	void Jump();

	// �d��
	void Gravity();

	// �C���X�^���X�̐錾
	Camera& camera;
};
