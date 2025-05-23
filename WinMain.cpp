#include <windows.h>
#include <ctime>
//#include <iostream> // 後で消す
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

	// 画面モードの設定
	SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, COLOR_DEPTH);

	// ウィンドウモードの設定
	ChangeWindowMode(TRUE);

	// 画面比率を変えられるかどうか
	SetWindowSizeChangeEnableFlag(TRUE);

	// DXライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return false;
	}

	// 描画先を裏画面にする
	SetDrawScreen(DX_SCREEN_BACK);

	return true;
}

void GameManagerDraw(GameManagerMain* _gameManagerMain) {
	_gameManagerMain->Display();
}

// プログラムの開始
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	AllocConsole();
	freopen_s((FILE**)stdout, "CONOUT$", "w", stdout);
	//std::cout << "コンソールが起動" << std::endl;
	srand(time(nullptr));

	if (!InitDX()) {
		//std::cout << "InitDXが失敗" << std::endl;
		return -1;
	}
	//std::cout << "InitDXが起動" << std::endl;

	// 各クラスのインスタンスを生成するための列挙型を作る
	// 順番は、Updateを発動させる順
	enum GameManagerClassName {
		GAMEMANAGER_BACKGROUND,
		GAMEMANAGER_CAMERA,
		GAMEMANAGER_COLLIDER,
		GAMEMANAGER_ARRAY_SIZE // これで配列のサイズを取得
	};

	enum StageClassName {
		STAGE_UNIT_MANAGER,
		STAGE_NEEDLE,
		STAGE_ARRAY_SIZE // これで配列のサイズを取得
	};
	//std::cout << "列挙型が起動" << std::endl;

	// 各クラスのインスタンスの生成
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
	//std::cout << "インスタンスがすべて生成されました" << std::endl;

	// updateみたいなもの
	while (TRUE) {

		deltaTime.Update();

		// スクリーンに映ってるものを消す
		ClearDrawScreen();


		// ---ここからメインの処理---
		//std::cout << "メイン処理開始" << std::endl;

		// Stageの更新
		for (int i = 0; i < STAGE_ARRAY_SIZE; i++) {

			stages[i]->Update();

		}
		//std::cout << "StageUpdate終了" << std::endl;

		player.Update();
		//std::cout << "PlayerUpdate終了" << std::endl;

		// GameManagerの更新
		for (int i = 0; i < GAMEMANAGER_ARRAY_SIZE; i++) {

			gameManagers[i]->Update();

		}
		//std::cout << "GameManagerUpdate終了" << std::endl;

		// Backgroundの描画
		GameManagerDraw(gameManagers[GAMEMANAGER_BACKGROUND]);
		//std::cout << "BackgroundDisplay終了" << std::endl;

		// Stageの描画
		for (int i = 0; i < STAGE_ARRAY_SIZE; i++) {

			stages[i]->Display();

		}
		//std::cout << "StageDisplay終了" << std::endl;

		// Playerの描画
		player.Display();
		//std::cout << "PlayerDisplay終了" << std::endl;

		// ESCキーが押されたらループから抜ける(ゲームを終了)
		if (CheckHitKey(KEY_INPUT_ESCAPE)) break;

		// Windows システムからくる情報を処理する
		if (ProcessMessage() == -1) break;

		// 裏画面に描画したものを映す
		ScreenFlip();
		//std::cout << "メインループ終わり" << std::endl;

	}

	// DXライブラリ使用の終了処理
	DxLib_End();

	// ソフトの終了 
	return 0;
}