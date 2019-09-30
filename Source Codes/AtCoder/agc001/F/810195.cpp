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

using namespace std;
using ll = long long;
using ull = unsigned long long;
constexpr int TEN(int n) {return (n==0)?1:10*TEN(n-1);}

struct Node {
    using NP = Node*;

    int ma = -1;
    int get(int a, int b) {
        if (b <= 0 or sz <= a) return -1;
        if (a <= 0 and sz <= b) {
            return ma;
        }
        return max(l->get(a, b), r->get(a-sz/2, b-sz/2));
    }
    void set(int k, int x) {
        if (sz == 1) {
            ma = x;
            return;
        }
        if (k < sz/2) {
            l->set(k, x);
        } else {
            r->set(k-sz/2, x);
        }
        ma = max(l->ma, r->ma);
    }
    NP l, r;
    int sz;
    Node(int sz) : sz(sz) {
        if (sz == 1) return;
        l = new Node(sz/2);
        r = new Node(sz - sz/2);
    }
};


int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int p[n], q[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", p+i); p[i]--;
    }
    for (int i = 0; i < n; i++) {
        q[p[i]] = i;
    }
/*    for (int i = 0; i < n; i++) {
        printf("%d, ", q[i]);
    }
    printf("\n");*/
    Node* rmq = new Node(n);
    int mi[n];
    vector<vector<int>> g(n);
    for (int i = 0; i < n; i++) {
        {
            int v = rmq->get(max(0, q[i]-k+1), q[i]);
            if (v != -1) {
                int qv = q[v];
//                printf("ed %d %d\n", q[i], qv);
                g[q[i]].push_back(qv);
            }
        }
        {
            int v = rmq->get(q[i], min(n, q[i]+k));
            if (v != -1) {
                int qv = q[v];
//                printf("ed %d %d\n", q[i], qv);
                g[q[i]].push_back(qv);
            }
            rmq->set(q[i], i);
        }        
        rmq->set(q[i], i);
    }
/*    Node* rrmq = new Node(n);
    for (int i = n-1; i >= 0; i--) {
        int v = n-1-rrmq->get(max(0, q[i]-k+1), min(n, q[i]+k));
        if (v != n) {
            int qv = q[v];
            printf("ed %d %d\n", qv, q[i]);
            g[qv].push_back(q[i]);
        }
        rrmq->set(q[i], n-1-i);
    }*/

    int deg[n];
    fill_n(deg, n, 0);
    for (int i = 0; i < n; i++) {
        for (int j: g[i]) {
            deg[j]++;
        }
    }
    priority_queue<int> que;
    for (int i = 0; i < n; i++) {
        if (deg[i] == 0) {
            que.push(i);
        }
    }
    vector<int> v;
    while (que.size()) {
        int p = que.top(); que.pop();
        v.push_back(p);
        for (int d: g[p]) {
            deg[d]--;
            if (deg[d] == 0) {
                que.push(d);
            }
        }
    }
    reverse(v.begin(), v.end());
    int ans[n];
    for (int i = 0; i < n; i++) {
//        printf("%d, ", v[i]);
        ans[v[i]] = i+1;
    }
//    printf("\n");
    for (int i = 0; i < n; i++) {
        printf("%d\n", ans[i]);
    }
    return 0;
}