#include "Needle.h"
#include "DxLib.h"
#include <cmath>

Needle::Needle() {
	TriangleLength = 80;

	// 三角形の各頂点の座標を調整
	TriangleVertexesX1 = TriangleLength / 2;
	TriangleVertexesX2 = 0;
	TriangleVertexesX3 = TriangleLength;
	TriangleVertexesY1 = SCREEN_HEIGHT - sqrt(3.0) * TriangleLength;
	TriangleVertexesY2 = SCREEN_HEIGHT;
	TriangleVertexesY3 = SCREEN_HEIGHT;

	TriangleColor = 0x7A92F2;
	TriangleLineColor = 0x000000;
}

void Needle::Update() {

	// 三角形の頂点の値を初期化
	TriangleVertexesX1 = TriangleLength / 2;
	TriangleVertexesX2 = 0;
	TriangleVertexesX3 = TriangleLength;
	TriangleVertexesY1 = SCREEN_HEIGHT - sqrt(3.0) * TriangleLength;
	TriangleVertexesY2 = SCREEN_HEIGHT;
	TriangleVertexesY3 = SCREEN_HEIGHT;
}

void Needle::Display() {

	// 三角形を描画(1つ描画したら1辺の長さ分右にずれてまた描画する)
	// 三角形の右側の頂点の値がスクリーンの横幅の値よりも大きくなったら終了

	do {
		DrawTriangleAA(
			// 三角形の上頂点
			TriangleVertexesX1, TriangleVertexesY1,
			// 左の頂点
			TriangleVertexesX2, TriangleVertexesY2,
			// 右の頂点
			TriangleVertexesX3, TriangleVertexesY3,
			// 色, 塗りつぶすかどうか
			TriangleColor, TRUE);

		// 縁取り
		DrawTriangleAA(
			// 三角形の上頂点
			TriangleVertexesX1, TriangleVertexesY1,
			// 左の頂点
			TriangleVertexesX2, TriangleVertexesY2,
			// 右の頂点
			TriangleVertexesX3, TriangleVertexesY3,
			// 色, 塗りつぶすかどうか(ここをFALSEにして塗りつぶさないことで縁取りをしている)
			TriangleLineColor, FALSE);

		// 三角形の1辺の長さ分右側にずらす
		TriangleVertexesX1 += TriangleLength;
		TriangleVertexesX2 += TriangleLength;
		TriangleVertexesX3 += TriangleLength;

	} while (TriangleVertexesX3 <= SCREEN_WIDTH);

}