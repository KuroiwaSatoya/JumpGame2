#include "Needle.h"
#include "Parameter.h"
#include "DxLib.h"
#include <cmath>

Needle::Needle() {
	triangleLength = 80;

	// 三角形の各頂点の座標を調整
	triangleVertexesX1 = triangleLength / 2;
	triangleVertexesX2 = 0;
	triangleVertexesX3 = triangleLength;
	triangleVertexesY1 = SCREEN_HEIGHT - sqrt(3.0) * triangleLength;
	triangleVertexesY2 = SCREEN_HEIGHT;
	triangleVertexesY3 = SCREEN_HEIGHT;

	triangleColor = 0x7A92F2;
	triangleLineColor = 0x000000;
}

void Needle::Update() {

	// 三角形の頂点の値を初期化
	triangleVertexesX1 = triangleLength / 2;
	triangleVertexesX2 = 0;
	triangleVertexesX3 = triangleLength;
	triangleVertexesY1 = SCREEN_HEIGHT - sqrt(3.0) * triangleLength;
	triangleVertexesY2 = SCREEN_HEIGHT;
	triangleVertexesY3 = SCREEN_HEIGHT;
}

void Needle::Display() {

	// 三角形を描画(1つ描画したら1辺の長さ分右にずれてまた描画する)
	// 三角形の右側の頂点の値がスクリーンの横幅の値よりも大きくなったら終了

	do {
		DrawTriangleAA(
			// 三角形の上頂点
			triangleVertexesX1, triangleVertexesY1,
			// 左の頂点
			triangleVertexesX2, triangleVertexesY2,
			// 右の頂点
			triangleVertexesX3, triangleVertexesY3,
			// 色, 塗りつぶすかどうか
			triangleColor, TRUE);

		// 縁取り
		DrawTriangleAA(
			// 三角形の上頂点
			triangleVertexesX1, triangleVertexesY1,
			// 左の頂点
			triangleVertexesX2, triangleVertexesY2,
			// 右の頂点
			triangleVertexesX3, triangleVertexesY3,
			// 色, 塗りつぶすかどうか(ここをFALSEにして塗りつぶさないことで縁取りをしている)
			triangleLineColor, FALSE);

		// 三角形の1辺の長さ分右側にずらす
		triangleVertexesX1 += triangleLength;
		triangleVertexesX2 += triangleLength;
		triangleVertexesX3 += triangleLength;

	} while (triangleVertexesX3 <= SCREEN_WIDTH);

}