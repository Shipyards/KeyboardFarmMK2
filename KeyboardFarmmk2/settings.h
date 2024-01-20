#pragma once
#include "runable.h"

class settings :
    public ZTRengine::runable
{
public:
    settings();
    void run(char);
    ~settings();
};

