#pragma once
#include "StageMain.h"

class Needle : public StageMain {
public:
	Needle();

	void Update() override;

	void Display() override;

private:

	// �O�p�`��1�ӂ̒���
	float TriangleLength;

	// �`�悷��e�O�p�`�̒��_��錾(1����A2�����A3���E)
	float TriangleVertexesX1, TriangleVertexesX2, TriangleVertexesX3,
		TriangleVertexesY1, TriangleVertexesY2, TriangleVertexesY3;

	// �O�p�`�̐F
	int TriangleColor, TriangleLineColor;
};
