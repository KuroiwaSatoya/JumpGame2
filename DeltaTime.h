#pragma once
#include "DxLib.h"

class DeltaTime {
public:
    // シングルトンにする
    static DeltaTime& GetInstance() {
        static DeltaTime instance; // 初回だけ生成、以後は同じものを返す
        return instance;
    }

    void Update() {
        // deltaTimeを作成
        nowTime = GetNowHiPerformanceCount();

        // deltaTimeが0にならないようにmaxで制御
        // GetNowHiPerformanceCount で取得できる値はマイクロ秒単位なので1000000で割ることで秒単位になる
        deltaTime = (nowTime - oldTime) / 1000000.0f;

        // 次のフレームのためにoldTimeにnowTimeを代入
        oldTime = nowTime;
    }

    void SetDeltaTime(float _deltaTime) { deltaTime = _deltaTime; }

    float GetDeltaTime() const { return deltaTime; }

private:
    float deltaTime;

    // コンストラクタ・コピー・代入を外部から使えなくする
    DeltaTime() : deltaTime(0.000001f) {}
    ~DeltaTime() = default;

    DeltaTime(const DeltaTime&) = delete;
    DeltaTime& operator=(const DeltaTime&) = delete;

    // デルタタイムの管理
    long long oldTime = GetNowHiPerformanceCount();
    long long nowTime = 0;
};