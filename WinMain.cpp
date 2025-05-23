#include <windows.h>
#include <ctime>
//#include <iostream> // ��ŏ���
#include "DxLib.h"
#include "DeltaTime.h"
#include "Parameter.h"
#include "LoadImages.h"
#include "GameManagerMain.h"
#include "Background.h"
#include "Camera.h"
#include "Collider.h"
#include "StageMain.h"
#include "UnitManager.h"
#include "Needle.h"
#include "Player.h"


bool InitDX() {

	// ��ʃ��[�h�̐ݒ�
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_DEPTH);

	// �E�B���h�E���[�h�̐ݒ�
	ChangeWindowMode(TRUE);

	// ��ʔ䗦��ς����邩�ǂ���
	SetWindowSizeChangeEnableFlag(TRUE);

	// DX���C�u��������������
	if (DxLib_Init() == -1)
	{
		return false;
	}

	// �`���𗠉�ʂɂ���
	SetDrawScreen(DX_SCREEN_BACK);

	return true;
}

void GameManagerDraw(GameManagerMain* _gameManagerMain) {
	_gameManagerMain->Display();
}

// �v���O�����̊J�n
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	//std::cout << "�R���\�[�����N��" << std::endl;
	srand(time(nullptr));

	if (!InitDX()) {
		//std::cout << "InitDX�����s" << std::endl;
		return -1;
	}
	//std::cout << "InitDX���N��" << std::endl;

	// �e�N���X�̃C���X�^���X�𐶐����邽�߂̗񋓌^�����
	// ���Ԃ́AUpdate�𔭓������鏇
	enum GameManagerClassName {
		GAMEMANAGER_BACKGROUND,
		GAMEMANAGER_CAMERA,
		GAMEMANAGER_COLLIDER,
		GAMEMANAGER_ARRAY_SIZE // ����Ŕz��̃T�C�Y���擾
	};

	enum StageClassName {
		STAGE_UNIT_MANAGER,
		STAGE_NEEDLE,
		STAGE_ARRAY_SIZE // ����Ŕz��̃T�C�Y���擾
	};
	//std::cout << "�񋓌^���N��" << std::endl;

	// �e�N���X�̃C���X�^���X�̐���
	LoadImages loadImages;
	DeltaTime& deltaTime = DeltaTime::GetInstance();
	Camera camera;

	Player player(loadImages, camera);

	StageMain* stages[STAGE_ARRAY_SIZE];
	UnitManager* unitManager = new UnitManager(player, camera);
	stages[STAGE_UNIT_MANAGER] = unitManager;
	stages[STAGE_NEEDLE] = new Needle();

	GameManagerMain* gameManagers[GAMEMANAGER_ARRAY_SIZE];
	gameManagers[GAMEMANAGER_BACKGROUND] = new Background(loadImages);
	gameManagers[GAMEMANAGER_CAMERA] = &camera;
	gameManagers[GAMEMANAGER_COLLIDER] = new Collider(player, unitManager, camera);
	//std::cout << "�C���X�^���X�����ׂĐ�������܂���" << std::endl;

	// update�݂����Ȃ���
	while (TRUE) {

		deltaTime.Update();

		// �X�N���[���ɉf���Ă���̂�����
		ClearDrawScreen();


		// ---�������烁�C���̏���---
		//std::cout << "���C�������J�n" << std::endl;

		// Stage�̍X�V
		for (int i = 0; i < STAGE_ARRAY_SIZE; i++) {

			stages[i]->Update();

		}
		//std::cout << "StageUpdate�I��" << std::endl;

		player.Update();
		//std::cout << "PlayerUpdate�I��" << std::endl;

		// GameManager�̍X�V
		for (int i = 0; i < GAMEMANAGER_ARRAY_SIZE; i++) {

			gameManagers[i]->Update();

		}
		//std::cout << "GameManagerUpdate�I��" << std::endl;

		// Background�̕`��
		GameManagerDraw(gameManagers[GAMEMANAGER_BACKGROUND]);
		//std::cout << "BackgroundDisplay�I��" << std::endl;

		// Stage�̕`��
		for (int i = 0; i < STAGE_ARRAY_SIZE; i++) {

			stages[i]->Display();

		}
		//std::cout << "StageDisplay�I��" << std::endl;

		// Player�̕`��
		player.Display();
		//std::cout << "PlayerDisplay�I��" << std::endl;

		// ESC�L�[�������ꂽ�烋�[�v���甲����(�Q�[�����I��)
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		// Windows �V�X�e�����炭�������������
		if (ProcessMessage() == -1) break;

		// ����ʂɕ`�悵�����̂��f��
		ScreenFlip();
		//std::cout << "���C�����[�v�I���" << std::endl;

	}

	// DX���C�u�����g�p�̏I������
	DxLib_End();

	// �\�t�g�̏I�� 
	return 0;
}