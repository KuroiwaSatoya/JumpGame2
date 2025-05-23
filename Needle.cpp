#include "Needle.h"
#include "DxLib.h"
#include <cmath>

Needle::Needle() {
	TriangleLength = 80;

	// �O�p�`�̊e���_�̍��W�𒲐�
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

	// �O�p�`�̒��_�̒l��������
	TriangleVertexesX1 = TriangleLength / 2;
	TriangleVertexesX2 = 0;
	TriangleVertexesX3 = TriangleLength;
	TriangleVertexesY1 = SCREEN_HEIGHT - sqrt(3.0) * TriangleLength;
	TriangleVertexesY2 = SCREEN_HEIGHT;
	TriangleVertexesY3 = SCREEN_HEIGHT;
}

void Needle::Display() {

	// �O�p�`��`��(1�`�悵����1�ӂ̒������E�ɂ���Ă܂��`�悷��)
	// �O�p�`�̉E���̒��_�̒l���X�N���[���̉����̒l�����傫���Ȃ�����I��

	do {
		DrawTriangleAA(
			// �O�p�`�̏㒸�_
			TriangleVertexesX1, TriangleVertexesY1,
			// ���̒��_
			TriangleVertexesX2, TriangleVertexesY2,
			// �E�̒��_
			TriangleVertexesX3, TriangleVertexesY3,
			// �F, �h��Ԃ����ǂ���
			TriangleColor, TRUE);

		// �����
		DrawTriangleAA(
			// �O�p�`�̏㒸�_
			TriangleVertexesX1, TriangleVertexesY1,
			// ���̒��_
			TriangleVertexesX2, TriangleVertexesY2,
			// �E�̒��_
			TriangleVertexesX3, TriangleVertexesY3,
			// �F, �h��Ԃ����ǂ���(������FALSE�ɂ��ēh��Ԃ��Ȃ����Ƃŉ��������Ă���)
			TriangleLineColor, FALSE);

		// �O�p�`��1�ӂ̒������E���ɂ��炷
		TriangleVertexesX1 += TriangleLength;
		TriangleVertexesX2 += TriangleLength;
		TriangleVertexesX3 += TriangleLength;

	} while (TriangleVertexesX3 <= SCREEN_WIDTH);

}