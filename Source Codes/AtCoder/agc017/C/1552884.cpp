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
    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<pair<int, int>> XY(M);
    for(int i=0; i<N; i++) cin >> A[i];
    for(int i=0; i<M; i++) cin >> XY[i].first >> XY[i].second;
    for(int i=0; i<M; i++) XY[i].first--;
    vector<int> cnt(N+1, 0);
    for(int i=0; i<N; i++)
        cnt[A[i]]++;

    vector<int> d(N+2, 0);
    vector<int> v(N+2, 0);
    for(int i=1; i<=N; i++){
        d[max(1, i-cnt[i]+1)]++;
        d[i+1]--;
    }

    for(int i=1; i<=N; i++)
        v[i] = v[i-1] + d[i];

    int ans = 0;
    for(int i=1; i<=N; i++)
        if(v[i] == 0) ans++;

    for(int i=0; i<M; i++){
        int x = A[XY[i].first];
        int y = XY[i].second;

        if(x-cnt[x]+1 >=1){
            if(v[x-cnt[x]+1] == 1) ans++;
            v[x-cnt[x]+1]--;
        }
        cnt[x]--;

        if(y-cnt[y] >= 1){
            if(v[y-cnt[y]] == 0) ans--;
            v[y-cnt[y]]++;
        }
        cnt[y]++;

        A[XY[i].first] = y;
        cout << ans << endl;
    }
    return 0;
}