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
    int x1, y1, r, x2, y2, x3, y3;
    cin >> x1 >> y1 >> r >> x2 >> y2 >> x3 >> y3;

    if (x1 - r >= x2&&x1 + r <= x3&&y1 - r >= y2&&y1 + r <= y3)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    if (
        (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1) <= r*r &&
        (x3 - x1)*(x3 - x1) + (y3 - y1)*(y3 - y1) <= r*r &&
        (x2 - x1)*(x2 - x1) + (y3 - y1)*(y3 - y1) <= r*r &&
        (x3 - x1)*(x3 - x1) + (y2 - y1)*(y2 - y1) <= r*r)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}