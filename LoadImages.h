#pragma once
#include "DxLib.h"

// �摜��ǂݍ��ނ��߂̃N���X
// �����摜��������ǂݍ��܂�邱�Ƃ�h��
class LoadImages {
public:

	LoadImages(){

		playerImage = LoadGraph("Images/Player.png");

		backgroundImage = LoadGraph("Images/Background.png");
	}

	// �v���C���[�̉摜
	int playerImage;

	// �w�i�̉摜
	int backgroundImage;
};