#include "Needle.h"
#include "Parameter.h"
#include "DxLib.h"
#include <cmath>

Needle::Needle() {
	triangleLength = 80;

	// �O�p�`�̊e���_�̍��W�𒲐�
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

	// �O�p�`�̒��_�̒l��������
	triangleVertexesX1 = triangleLength / 2;
	triangleVertexesX2 = 0;
	triangleVertexesX3 = triangleLength;
	triangleVertexesY1 = SCREEN_HEIGHT - sqrt(3.0) * triangleLength;
	triangleVertexesY2 = SCREEN_HEIGHT;
	triangleVertexesY3 = SCREEN_HEIGHT;
}

void Needle::Display() {

	// �O�p�`��`��(1�`�悵����1�ӂ̒������E�ɂ���Ă܂��`�悷��)
	// �O�p�`�̉E���̒��_�̒l���X�N���[���̉����̒l�����傫���Ȃ�����I��

	do {
		DrawTriangleAA(
			// �O�p�`�̏㒸�_
			triangleVertexesX1, triangleVertexesY1,
			// ���̒��_
			triangleVertexesX2, triangleVertexesY2,
			// �E�̒��_
			triangleVertexesX3, triangleVertexesY3,
			// �F, �h��Ԃ����ǂ���
			triangleColor, TRUE);

		// �����
		DrawTriangleAA(
			// �O�p�`�̏㒸�_
			triangleVertexesX1, triangleVertexesY1,
			// ���̒��_
			triangleVertexesX2, triangleVertexesY2,
			// �E�̒��_
			triangleVertexesX3, triangleVertexesY3,
			// �F, �h��Ԃ����ǂ���(������FALSE�ɂ��ēh��Ԃ��Ȃ����Ƃŉ��������Ă���)
			triangleLineColor, FALSE);

		// �O�p�`��1�ӂ̒������E���ɂ��炷
		triangleVertexesX1 += triangleLength;
		triangleVertexesX2 += triangleLength;
		triangleVertexesX3 += triangleLength;

	} while (triangleVertexesX3 <= SCREEN_WIDTH);

}