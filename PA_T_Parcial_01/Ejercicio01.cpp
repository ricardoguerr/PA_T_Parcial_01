#include "Ejercicio01.h"
#include <string>

using namespace std;

char Ejercicio01::lower(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        return c;

    return (char)(c + 32);
}

bool Ejercicio01::isPalindrome(const char* phrase, int length)
{

    string clean;
    for (int i = 0; i < length; i++) {
        char c = lower(phrase[i]);
        if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            clean += c;
        }
    }

    int num = clean.size();
    for (int n = 0; n < num / 2; n++) {
        if (clean[n] != clean[num - n - 1]) {
            return false;
        }
    }

    return true;
}
