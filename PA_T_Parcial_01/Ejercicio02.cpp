#include "Ejercicio02.h"
#include <algorithm>
#include <iomanip>
#include <iostream>


using namespace std;

int Ejercicio02::rob(int houses[], int num)
{
    if (num == 0) return 0;
    if (num == 1) return houses[0];

    int* dp = (int*)malloc(sizeof(int) * num);

    dp[0] = houses[0];

    dp[1] = max(houses[0], houses[1]);

    for (int n = 2; n < num; n++) {
        dp[n] = max(dp[n - 1], dp[n - 2] + houses[n]);
    }

    return dp[num - 1];

}
