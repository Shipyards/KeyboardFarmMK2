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

inline void ZTRsleep(int);
inline void clearScreen();
#ifdef __linux__ //for linux
#include <unistd.h>
inline void ZTRsleep(int sleepamt) { usleep(sleepamt); }
inline void clearScreen() { system("clear"); }
#elif __APPLE__ //for apple
#include <unistd.h>
inline void ZTRsleep(int sleepamt) { usleep(sleepamt); }
inline void clearScreen() { system("clear"); }
#elif _WIN32 //for windows
#include <windows.h>
inline void ZTRsleep(int sleepamt) { Sleep(sleepamt); }
inline void clearScreen() { system("cls"); }
#else
#endif

#include <iostream>
#include <random>
#include <stdio.h>
#include <time.h>
#include <fstream>

using namespace std;
namespace ZTRengine 
{
    class ZTRutils
    {
    public:
        class ZTRexit {}; // throw this when you want a menu item to exit the menu
        class ZTRcontinue {}; // throw this when you want a menu item to go back to the menu
        class ID10T_ERR {}; // ID10T error
        /* highly inefficient random from range number generator */
        static int randomFromRange(const int range_from, const int range_to)
        {
            random_device rand_dev;
            mt19937 generator(rand_dev());
            uniform_int_distribution<int>  distr(range_from, range_to);
            return distr(generator);
        }
        /* fuction to print to screen with a delay inbetween each character, delay is in milliseconds and is sightly randomized */
        static void timeDelayPrint(string printThis, int delay)
        {
            //cout << endl;
            for (int b = 0; b < printThis.length(); b++)
            {
                cout << printThis[b] << flush;
                ZTRsleep(delay + randomFromRange(0,20) * (delay / 2));
            };
        };
        /* theoretically clears terminal */
        static void clrscreen()
        {
            clearScreen();
        }
        /* simple if string is integer */
        static bool strIsInt(string in)
        {
            if (in.empty() || (isdigit(in[0]) && (!(in[0] != '-') && !isdigit(in[1])) && (!(in[0] != '+') && !isdigit(in[1])))) return false;
            else if (isdigit(in[0]) || ((in[0] != '-') && isdigit(in[1])) || ((in[0] != '+') && isdigit(in[1]))) return true;
        };
        /* converts a character (0,1,2,3,4,5,6,7,8,9) into its actual numerical value, rather than its ascii value, if it is not valid for coversion, function returns 10 */
        static unsigned short int chartoint(char charin)
        {
            switch(charin)
            {
            case 48:
                return 0;
                break;
            case 49:
                return 1;
                break;
            case 50:
                return 2;
                break;
            case 51:
                return 3;
                break;
            case 52:
                return 4;
                break;
            case 53:
                return 5;
                break;
            case 54:
                return 6;
                break;
            case 55:
                return 7;
                break;
            case 56:
                return 8;
                break;
            case 57:
                return 9;
                break;
            default:
                return 10;
                break;
            }
        }
        static void swapspacefor_(string &strin)
        {
            string::iterator it1;
            for (it1 = strin.begin(); it1 != strin.end(); it1++)
            {
                if (*it1 == ' ')
                {
                    *it1 = '_';
                }
            }
        }
        static vector<int> extractintfromstr(string strin)
        {
            vector<int> ints;
            string::iterator strit;
            for (strit = strin.begin(); strit != strin.end(); strit++)
            {
                if (isdigit(*strit))
                {
                    ints.push_back(chartoint(*strit));
                }
            }
            return ints;
        }
        static unsigned int unsignedintfromstr(string strin)
        {
            unsigned int returnint = 0;
            unsigned int place = 1;
            string::iterator strit;
            for (strit = strin.begin(); strit != strin.end(); strit++)
            {
                if (isdigit(*strit))
                {
                    returnint += chartoint(*strit) * place;
                    place = place * 10;
                }
            }
            return returnint;
        }
        static int strtoint(string strin) //only picks up sign if it is first (no spaces first)
        {
            unsigned int returnint = 0;
            unsigned int place = 1;
            bool negative = false;
            string::iterator strit;
            if (strin[0] == '-')
            {
                negative = true;
            }
            for (strit = strin.begin(); strit != strin.end(); strit++)
            {
                if (isdigit(*strit))
                {
                    returnint += chartoint(*strit) * place;
                    place = place * 10;
                }
            }
            if (negative)
            {
                returnint * -1;
            }
            return returnint;
        }
        // Get current date/time, format is YYYY-MM-DD.HH:mm:ss
        static string currentDateTime() {
            time_t now = time(0);
            struct tm tstruct;
            char buf[80];
            localtime_s(&tstruct,&now);
            strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
            return buf;
        }
    };
}
