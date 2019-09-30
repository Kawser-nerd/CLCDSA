#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cassert>
#include <climits>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cstring>

using namespace std;

const int MAX_X = 10000005;
int knownNumber[MAX_X] = {0};
int currentId = 0;

int getPow10(int x) {
    int pow10 = 1;
    for (pow10 = 1; x >= pow10; pow10 *= 10) {}
    return pow10;
}

int main() {
    int nCases;

    scanf("%d", &nCases);
    for (int iCase = 1; iCase <= nCases; iCase++) {
        int xMin, xMax;
        scanf("%d%d", &xMin, &xMax);
        int pow10 = getPow10(xMin);
        assert(pow10 == getPow10(xMax));
        int solution = 0;
        for (int x = xMin; x <= xMax; x++) {
            currentId++;
            int rotX = x;
            while (knownNumber[rotX] < currentId) {
                knownNumber[rotX] = currentId;
                solution += (x < rotX && rotX <= xMax);
                rotX = (rotX + (rotX % 10) * pow10) / 10;
            }
        }
        printf("Case #%i: %i\n", iCase, solution);
    }
    return 0;
}
