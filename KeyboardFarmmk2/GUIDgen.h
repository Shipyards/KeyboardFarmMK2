/*
   Copyright 2024 Jacob T. Ray

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software
   distributed under the License is distributed on an "AS IS" BASIS,
   WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
   See the License for the specific language governing permissions and
   limitations under the License.
*/

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
