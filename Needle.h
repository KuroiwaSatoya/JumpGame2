#pragma once
#include "StageMain.h"

class Needle : public StageMain {
public:
	Needle();

	void Update() override;

	void Display() override;

	float GetTriangleVertexesY1() { return triangleVertexesY1; }

private:

	// �O�p�`��1�ӂ̒���
	float triangleLength;

	// �`�悷��e�O�p�`�̒��_��錾(1����A2�����A3���E)
	float triangleVertexesX1, triangleVertexesX2, triangleVertexesX3,
		triangleVertexesY1, triangleVertexesY2, triangleVertexesY3;

	// �O�p�`�̐F
	int triangleColor, triangleLineColor;
};
