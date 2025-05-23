#pragma once
#include "DxLib.h"

class DeltaTime {
public:
    // �V���O���g���ɂ���
    static DeltaTime& GetInstance() {
        static DeltaTime instance; // ���񂾂������A�Ȍ�͓������̂�Ԃ�
        return instance;
    }

    void Update() {
        // deltaTime���쐬
        nowTime = GetNowHiPerformanceCount();

        // deltaTime��0�ɂȂ�Ȃ��悤��max�Ő���
        // GetNowHiPerformanceCount �Ŏ擾�ł���l�̓}�C�N���b�P�ʂȂ̂�1000000�Ŋ��邱�Ƃŕb�P�ʂɂȂ�
        deltaTime = (nowTime - oldTime) / 1000000.0f;

        // ���̃t���[���̂��߂�oldTime��nowTime����
        oldTime = nowTime;
    }

    void SetDeltaTime(float _deltaTime) { deltaTime = _deltaTime; }

    float GetDeltaTime() const { return deltaTime; }

private:
    float deltaTime;

    // �R���X�g���N�^�E�R�s�[�E������O������g���Ȃ�����
    DeltaTime() : deltaTime(0.000001f) {}
    ~DeltaTime() = default;

    DeltaTime(const DeltaTime&) = delete;
    DeltaTime& operator=(const DeltaTime&) = delete;

    // �f���^�^�C���̊Ǘ�
    long long oldTime = GetNowHiPerformanceCount();
    long long nowTime = 0;
};