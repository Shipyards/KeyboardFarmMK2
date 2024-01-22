#pragma once
#include "runable.h"

class removesave :
    public ZTRengine::runable
{
public:
    removesave();
    void run(char);
    ~removesave();
};

class settings :
    public ZTRengine::runable
{
public:
    settings();
    void run(char);
    ~settings();
};

