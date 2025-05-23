#pragma once
#include "Screen.h"

class GameManagerMain {
public:

    virtual ~GameManagerMain() = default;

    virtual void Update() {};

    virtual void Display() {};
};
