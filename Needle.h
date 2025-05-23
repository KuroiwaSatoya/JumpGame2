#pragma once
#include "StageMain.h"

class Needle : public StageMain {
public:
	Needle();

	void Update() override;

	void Display() override;

private:

	// 三角形の1辺の長さ
	float TriangleLength;

	// 描画する各三角形の頂点を宣言(1が上、2が左、3が右)
	float TriangleVertexesX1, TriangleVertexesX2, TriangleVertexesX3,
		TriangleVertexesY1, TriangleVertexesY2, TriangleVertexesY3;

	// 三角形の色
	int TriangleColor, TriangleLineColor;
};
