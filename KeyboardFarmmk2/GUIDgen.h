#pragma once

#include "ZTRutils.h"
#include <iostream>
#include <random>

using namespace std;

static string GUIDgen() //Note: not garunteed unique, however statistically improbable, this is experimental
{
    const char hexTemp[16] = "0123456789ABCEF";
    string uniqueID = "xxxxxxxx-xxxx-xxxx-xxxx-xxxxxxxxxxxx";
    random_device rand_dev;
    mt19937 generator(rand_dev());
    uniform_int_distribution<int>  distr(0, 14);
    for (int x = 0; x < 36; x++)
    {
        if (uniqueID[x] == '-')
        {
            continue;
        }
        uniqueID[x] = hexTemp[distr(generator)];
    }
    return uniqueID;
}