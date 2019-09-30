#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
using ll=long long;

int main(){
    int N, M;
    cin >> N >> M;
    int P[100000], Y[100000];
    vector<ll> h[100001];
    for(int i = 0; i < M; i++){
        cin >> P[i] >> Y[i];
        h[P[i]].push_back(Y[i]);
    }
    for(int i = 0; i < N; i++){
        sort(h[i+1].begin(), h[i+1].end());
    }
    for(int i = 0; i < M; i++){
        printf("%012lld\n", ll(P[i])*1000000+int(lower_bound(h[P[i]].begin(), h[P[i]].end(), Y[i])-h[P[i]].begin())+1);
    }
    return 0;
}