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
	// ”wŒi‚Ì‰æ‘œ
	int backgroundImage;

	// ”wŒi‰æ‘œ‚Ìc‰¡‚Ì‘å‚«‚³
	Vector2 size;

	// ”wŒi‚ğ•`‰æ‚·‚éÀ•W
	Vector2 position;
};
