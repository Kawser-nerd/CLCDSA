#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <queue>
#include <ctime>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <bitset>

using namespace std;

#define fr first
#define sc second
#define mp make_pair
#define pb push_back
#define epr(...) fprintf(stderr, __VA_ARGS__)
#define db(x) cerr << #x << " = " << x << endl

#define equal equalll
#define less lesss
const int N = -1;
const int INF = 1e9;


long long n;

void read() {
    cin >> n;
}

long long binPow(long long a, long long b) {
    long long res = 1;
    for (;b > 0; b /= 2) {
        if (b % 2 == 1) res = (res * a);
        a *= a;
    }
    return res;
}

long long solve(long long n) {
    if (n % 10 == 0) {
        return solve(n - 1) + 1;
    }

    long long res = 1;
    long long x = 1; 
    int k;
    if (n <= 10) return n;
    for (k = 1; x * 10 <= n; k++) {
        //db(res);
        if (k % 2 == 1) {
            int d = (k + 1) / 2;
            res += binPow(10, d) - 1 + binPow(10, d - 1);
            if (k == 1)
                res--;
        } 
        else {
            res += binPow(10, k / 2) * 2 - 1;
        }
        x *= 10; 
    }
    //db(res);
    int d = (k + 1) / 2;
    int tmp = n / binPow(10, d);
    if (tmp != binPow(10, k - d - 1))
        res++; 
    res += n % binPow(10, d);

    long long sim = 0; 
    for (; tmp > 0; tmp /= 10) {
        sim = sim * 10 + tmp % 10;
    }  
    res += sim - 1;
    return res;
}

void printAns() {

}

long long getRef(long long x) {
    long long res = 0;
    for (; x > 0; x /= 10) {
        res = res * 10 + x % 10;
    }
    return res;
}


long long stupid(long long n) {
    vector < int > dist(n + 1, INF); 
    queue < int > q;
    dist[0] = 0; 
    q.push(0);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v + 1 <= n && dist[v + 1] > dist[v] + 1) {
            dist[v + 1] = dist[v] + 1;
            q.push(v + 1);
        }
        long long y = getRef(v);
        if (y <= n && dist[y] > dist[v] + 1) {
            dist[y] = dist[v] + 1;
            q.push(y);
        }
    }
    return dist[n];
}

void stress() {
    for (int t = 0; ; t++) {
        cerr << "test id: " << t << endl;
        long long x = rand() % 100000;
        long long r1 = solve(x);
        long long r2 = stupid(x);
        cerr << "r1 r2: " << r1 << " " << r2 << endl;
        assert(r1 == r2);
    }
}


int main(){
#ifdef DEBUG
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
#endif
    if (1) {
        int k = 1;
        scanf("%d", &k);
        for (int tt = 0; tt < k; tt++) {
            printf("Case #%d: ", tt + 1);
            read();
            //printf("%lld\n", stupid(n));
            long long res = solve(n);
            assert(res > 0);
            printf("%lld\n", res);
        }
    }
    else {
        stress();
    }

    return 0;
}

