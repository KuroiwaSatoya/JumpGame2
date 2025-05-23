#include "Background.h"
#include "LoadImages.h"
#include "Parameter.h"
#include "DxLib.h"

Background::Background(LoadImages& _loadImages) {

	backgroundImage = _loadImages.backgroundImage;

	// GetGraphSize‚Íint‚¶‚á‚È‚¢‚Æg‚¦‚È‚¢‚Ì‚Åˆê“I‚È•Ï”‚ğì‚é
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
			DrawGraph(position.x, position.y,		// •`‰æ‚·‚éÀ•W 
				backgroundImage,					// •`‰æ‚·‚é‰æ‘œ‚Ìƒnƒ“ƒhƒ‹
				FALSE);								// ”wŒi‚ğ“§‰ß‚·‚é‚©‚Ç‚¤‚©
			position.x += size.x;
		}
		position.y += size.y;
	}

}