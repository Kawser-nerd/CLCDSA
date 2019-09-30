#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int R, C, K, N;
    cin >> R >> C >> K >> N;
    vector<int> r(N);
    vector<int> c(N);
    for(int i=0; i<N; i++){
        cin >> r[i] >> c[i];
        r[i]--; c[i]--;
    }

    vector<long long> a(R);
    vector<long long> b(C);
    for(int i=0; i<N; i++){
        a[r[i]]++;
        b[c[i]]++;
    }

    long long ans = 0;
    for(int i=0; i<N; i++){
        long long tmp = a[r[i]] + b[c[i]];
        if(tmp == K) ans--;
        else if(tmp == K+1) ans++;
    }

    map<long long, long long> mp1, mp2;
    for(int i=0; i<R; i++) mp1[a[i]]++;
    for(int i=0; i<C; i++) mp2[b[i]]++;
    for(int i=0; i<R; i++) ans += mp1[i] * mp2[K-i];
    cout << ans << endl;
    return 0;
}