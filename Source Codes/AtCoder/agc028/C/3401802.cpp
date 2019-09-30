#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <random>
#include <cstdio>
#include <cstring>
#include <cmath>

using namespace std;
using ll = long long;
using P = pair<ll, ll>;

ll N;
vector<P> AB;

void input() {
    cin >> N;
    AB.resize(N);
    for (auto& v : AB) {
        cin >> v.first >> v.second;
    }
}

ll solve() {
    struct ABRef {
        ll p, t;
        ll v() {
            return t == 0 ? AB[p].first : AB[p].second;
        }
    };
    ll sumA = 0, sumB = 0;
    for (auto& v : AB) {
        sumA += v.first;
        sumB += v.second;
    }
    
    vector<ABRef> abrs(N * 2);
    for (ll i = 0; i < N; i++) for (ll j = 0; j < 2; j++) {
        abrs[i * 2 + j] = ABRef{i, j};
    }
    sort(abrs.begin(), abrs.end(), [](ABRef l, ABRef r) {
       return l.v() < r.v();
    });
    
    ll cw[N * 2];
    cw[0] = abrs[0].v();
    for (int i = 1; i < N * 2; i++)
        cw[i] = cw[i - 1] + abrs[i].v();
    
    vector<bool> used(N, false);
    bool useFrontNth = false;
    for (int i = 0; i < N; i++) {
        if (used[abrs[i].p]){
            useFrontNth = true;
            break;
        }
        used[abrs[i].p] = true;
    }
    
    ll sumN = 0;
    if (useFrontNth) {
        sumN = cw[N - 1];
    } else {
        for (int unuse = 0; unuse < N; unuse++) {
            ll sum = cw[N - 1] - abrs[unuse].v();
            ll unuseI = abrs[unuse].p;
            if (abrs[N].p != unuseI)
                sum += abrs[N].v();
            else
                sum += abrs[N + 1].v();
            sumN = unuse == 0 ? sum : min(sumN, sum);
        }
    }
    return min(min(sumA, sumB), sumN);
}

int main() {
    input();
    
    cout << solve() << endl;
    
    
    return 0;
}