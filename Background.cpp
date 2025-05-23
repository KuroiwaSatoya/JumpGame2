#include "Background.h"
#include "LoadImages.h"
#include "Parameter.h"
#include "DxLib.h"

Background::Background(LoadImages& _loadImages) {

	backgroundImage = _loadImages.backgroundImage;

	// GetGraphSize��int����Ȃ��Ǝg���Ȃ��̂ňꎞ�I�ȕϐ������
	int sizeX = 0, sizeY = 0;
	GetGraphSize(backgroundImage, &sizeX, &sizeY);

	size = Vector2(sizeX, sizeY);
}

void Background::Update() {

}

void Background::Display() {

	position.y = 0;
	while (position.y < SCREEN_HEIGHT) {
		position.x = 0;
		while (position.x < SCREEN_WIDTH) {
			DrawGraph(position.x, position.y,		// �`�悷����W 
				backgroundImage,					// �`�悷��摜�̃n���h��
				FALSE);								// �w�i�𓧉߂��邩�ǂ���
			position.x += size.x;
		}
		position.y += size.y;
	}

}