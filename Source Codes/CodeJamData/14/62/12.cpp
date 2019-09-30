#include <cstdio>
#include <queue>
#include <set>
#include <vector>
#include <cmath>
#include <iostream>
#include <map>
#include <cstring>
#include <algorithm>
using namespace std;

int n;
vector<int> a;
long long fact[128];

void read() {
    scanf("%d", &n);
    a.clear();
    for (int i = 0; i < (1 << n); i++) {
        int x;
        scanf("%d", &x);
        a.push_back(x);
    }
}

long long ans;

vector<int> getnew(vector<int> a) {
    vector<int> b;
    for (int i = 1; i < (int)a.size(); i+= 2) {
        b.push_back(a[i] / 2);
    }
    return b;
}

void go(vector<int> a, int moves) {
    if ((int)a.size() == 1) {
        ans += fact[moves];
        //printf ( "-- %d\n", moves);
        return ;
    }
    vector<int> b;
    vector<int> mis;
    //int idx = -1;
/*
    for(int i = 0; i < (int)a.size(); i++) {
        printf ("%d ", a[i]);
    }
    printf ("\n");
*/
    for (int i = 0; i < (int)a.size(); i+=2) {
        if (a[i] % 2 == 0 || a[i] + 1 != a[i + 1])
        {
           mis.push_back(i); 
        }
    }
    
    //printf ("idx %d mis %d\n", idx, (int)mis.size());

    if ((int)mis.size() == 0) {
        go(getnew(a), moves);
        return ;
    }

    if ((int)mis.size() == 1) {
        swap(a[mis[0]], a[mis[0] + 1]);
        go(getnew(a), moves + 1);
        return ;
    }

    if ((int)mis.size() > 2) return ;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            swap(a[mis[0] + i], a[mis[1] + j]);
            if ((a[mis[0]] & 1) && (a[mis[1]] & 1)) {
                if ((a[mis[0]] + 1 == a[mis[0] + 1]) && (a[mis[1]] + 1 == a[mis[1] + 1])) {
                    go(getnew(a), moves + 1);
                }
            }
            swap(a[mis[0] + i], a[mis[1] + j]);
        }
    }
}

void solve() {
    ans = 0;
    fact[0] = 1;
    for (int i = 1; i <= 30; i++) {
        fact[i] = fact[i - 1] * (long long)i;
    }

    go(a, 0);
    cout << ans << '\n';
}

int main() {
    int cases;

    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++) {
        read();
        printf ("Case #%d: ", i);
        solve();
    }

    return 0;
}

