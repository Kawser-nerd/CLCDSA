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

int BEST_STD[31] =  {0 ,  1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9,  9,  10, 10, 10};
int BEST_SURP[31] = {-1, -1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5, 5, 5, 6, 6, 6, 7, 7, 7, 8, 8, 8, 9, 9, 9, 10, 10, 10, -1, -1};

int main() {
    int nCases;
    scanf("%d", &nCases);


    for (int iCase = 1; iCase <= nCases; iCase++) {
        int n, nSurp, minBest;
        scanf("%d%d%d", &n, &nSurp, &minBest);

        int solution = 0;
        for (int i = 0; i < n; i++) {
            int total;
            scanf("%d", &total);
            if (BEST_STD[total] >= minBest) {
                solution++;
            } else if (BEST_SURP[total] >= minBest && nSurp > 0) {
                solution++;
                nSurp--;
            }
        }

        printf("Case #%i: %i\n", iCase, solution);
    }

    return 0;
}
