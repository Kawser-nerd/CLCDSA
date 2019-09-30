#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <sstream>
#include <algorithm>
#include <deque>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <cstdio>
#include <iostream>
#include <cmath>
#include <climits>
#include <bitset>
#include <functional>
#include <numeric>
#include <ctime>
#include <cassert>
#include <cstring>
#include <fstream>

#define FOR(i, a, b) for(int (i)=(a); (i)<(b); (i)++)
#define IFOR(i, a, b) for(int (i)=(a);(i)<=(b);(i)++)
#define RFOR(i, a, b) for(int (i)=(a);(i)>=(b);(i)--)

using namespace std;

int main() {
    long long r, b;
    cin >> r >> b;
    long long x, y;
    cin >> x >> y;

    long long lb = 0, ub = min(r, b) + 1;
    while (ub - lb > 1) {
        long long half = (ub + lb) / 2;
        long long tr = r, tb = b;
        tr -= half, tb -= half;
        if (tr >= 0 && tb >= 0 && tr / (x - 1) + tb / (y - 1) >= half)
            lb = half;
        else
            ub = half;
    }
    cout << lb << endl;

    return 0;
}