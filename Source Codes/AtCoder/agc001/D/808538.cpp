#include <iostream>
#include <cstdio>
#include <cassert>
#include <cstring>
#include <vector>
#include <valarray>
#include <array>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <complex>
#include <random>
#include <cassert>

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

string IMP = "Impossible";
int n, m;
int a[110];

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
    }
    int rc = 0;
    for (int i = 0; i < m; i++) {
        rc += (a[i]+1)/2;
    }
    if (rc-1 > n/2) {
        cout << IMP << endl;
        return 0;
    }
    vector<int> od, ev;
    for (int i = 0; i < m; i++) {
        if (a[i] % 2) {
            od.push_back(a[i]);
        } else {
            ev.push_back(a[i]);
        }
    }
    assert(od.size() <= 2);
    vector<int> v;
    if (od.size()) {
        v.push_back(od.back());
        od.pop_back();
    }
    for (int d: ev) {
        v.push_back(d);
    }
    if (od.size()) {
        v.push_back(od.back());
        od.pop_back();
    }
    vector<int> b;
    if (v.size() >= 2) {
        int i = 0;
        if (v[i] % 2 == 1) {
            if (v[i]-1) {
                b.push_back(v[i]-1);
            }
            i++;
        } else {
            b.push_back(v[i]-1);
            i++;
        }
        while (i < v.size()-1) {
            b.push_back(v[i]);
            i++;
        }
        if (v[i] % 2 == 1) {
            b.push_back(2);
            if (v[i]-1) {
                b.push_back(v[i]-1);
            }
            i++;
        } else {
            b.push_back(v[i]);
            b.push_back(1);
        }
    } else {
        if (v[0]-1) {
            b.push_back(v[0]-1);
        }
        b.push_back(1);
    }

    for (int d: v) {
        printf("%d ", d);
    }
    printf("\n");
    printf("%d\n", (int)b.size());
    for (int d: b) {
        printf("%d ", d);
    }
    printf("\n");
    return 0;
}