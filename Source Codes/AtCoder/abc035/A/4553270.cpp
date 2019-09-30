#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>
#include <cmath>
#include <limits>
using namespace std;
#define REP(var, num) for(sll var = 0; var < num; var++)
typedef signed long long sll;
typedef unsigned long long ull;
/*
numeric_limits<sll>::max()
*/

int main() {
    sll w,h;
    cin >> w >> h;

    if (3*w == 4*h)
        cout << "4:3" << endl;
    else
        cout << "16:9" << endl;

    return 0;
}