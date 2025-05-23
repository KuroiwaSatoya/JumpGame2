#pragma once
#include "StageMain.h"

class Needle : public StageMain {
public:
	Needle();

	void Update() override;

	void Display() override;

	float GetTriangleVertexesY1() { return triangleVertexesY1; }

private:

	// 三角形の1辺の長さ
	float triangleLength;

	// 描画する各三角形の頂点を宣言(1が上、2が左、3が右)
	float triangleVertexesX1, triangleVertexesX2, triangleVertexesX3,
		triangleVertexesY1, triangleVertexesY2, triangleVertexesY3;

	// 三角形の色
	int triangleColor, triangleLineColor;
};
