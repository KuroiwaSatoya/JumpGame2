#include "Background.h"
#include "DxLib.h"

Background::Background(LoadImages& _loadImages) {

	backgroundImage = _loadImages.backgroundImage;

	// GetGraphSizeはintじゃないと使えないので一時的な変数を作る
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
			DrawGraph(position.x, position.y,		// 描画する座標 
				backgroundImage,					// 描画する画像のハンドル
				FALSE);								// 背景を透過するかどうか
			position.x += size.x;
		}
		position.y += size.y;
	}

}