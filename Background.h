#pragma once
#include "GameManagerMain.h"
#include "LoadImages.h"
#include "Vector2.h"

class Background : public GameManagerMain {
public:

	Background(LoadImages& _loadImages);

	void Update() override;

	void Display() override;

private:
	// �w�i�̉摜
	int backgroundImage;

	// �w�i�摜�̏c���̑傫��
	Vector2 size;

	// �w�i��`�悷����W
	Vector2 position;
};
