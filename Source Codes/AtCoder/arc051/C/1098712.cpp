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
const int MOD = 1e9 + 7;

int power(int n, int p) {
    if (p == 0)
        return 1;
    long long res = 1;
    long long add = n;
    while (p > 0) {
        if (p & 1)
            res = (res * add) % MOD;
        p >>= 1;
        add = add*add%MOD;
    }
    return res;
}



int main() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<long long> dat(n);

    FOR(i, 0, n) {
        cin >> dat[i];
    }
    sort(dat.begin(), dat.end());
    if (a == 1) {
        for (auto t : dat) {
            cout << t << endl;
        }
        return 0;
    }


    long long maxx = dat.back();

    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (auto t : dat)
        pq.push(t);

    int cnt = 0;
    while (1) {
        long long t = pq.top();
        if (b == 0 || t*a >= maxx)
            break;
        pq.pop();
        t *= a;
        pq.push(t);
        cnt++;
        b--;
    }

    vector<long long> res(n);
    FOR(i, 0, n) {
        long long t = pq.top() % MOD;
        pq.pop();
        int pos = (2 * n + i - b%n) % n;
        int divnum = (b - i - 1 < 0 ? 0 : max(0, ((b - i - 1) / n) + 1));
        long long mod = power(a, divnum);
        long long ttt = (mod * t) % MOD;
        res[pos] = ttt;
    }
    for (auto t : res)
        cout << t << endl;


    // a >= a_n????????
    // a < a_n???
    // a >= a_n???????????????
    return 0;
}