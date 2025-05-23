#pragma once
#include "Screen.h"

class StageMain {
public:

    virtual ~StageMain() = default;
    virtual void Update() { }
    virtual void Display() { }
};
