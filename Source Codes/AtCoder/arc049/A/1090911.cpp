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
    string s;
    cin >> s;
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    FOR(i, 0, s.size()+1) {
        if (i == a || i == b || i == c || i == d)
            cout << '"';
        if(i != s.size())
            cout << s[i];
    }
    cout << endl;
    return 0;
}