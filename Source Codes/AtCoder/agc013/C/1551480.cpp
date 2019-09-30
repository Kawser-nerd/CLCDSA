#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
#include <cassert>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long N, L, T;
    cin >> N >> L >> T;
    vector<pair<long long, int>> XW(N);
    for(int i=0; i<N; i++) cin >> XW[i].first >> XW[i].second;
    vector<long long> rmover, lmover;
    for(int i=0; i<N; i++){
        if(XW[i].second == 1) rmover.push_back(L-1-XW[i].first);
        else lmover.push_back(XW[i].first);
    }
    sort(rmover.begin(), rmover.end());
    for(int i=0, j=rmover.size(); i<j; i++)
        rmover.push_back(rmover[i]+L);
    for(int i=0, j=lmover.size(); i<j; i++)
        lmover.push_back(lmover[i]+L);

    vector<long long> cross(N);
    for(int i=0; i<N; i++){
        if(XW[i].second == 1){
            long long X0 = XW[i].first;
            long long tmp1 = (2*T/L)*lmover.size()/2;
            long long tmp2 = (2*T)%L;
            long long tmp3 = upper_bound(lmover.begin(), lmover.end(), tmp2+X0) - lower_bound(lmover.begin(), lmover.end(), X0);
            cross[i] = tmp1 + tmp3;
        }else{
            long long X0 = L-1-XW[i].first;
            long long tmp1 = (2*T/L)*rmover.size()/2;
            long long tmp2 = (2*T)%L;
            long long tmp3 = upper_bound(rmover.begin(), rmover.end(), tmp2+X0) - lower_bound(rmover.begin(), rmover.end(), X0);
            cross[i] = tmp1 + tmp3;
        }
    }

    vector<long long> num(N);
    for(int i=0; i<N; i++){
        if(XW[i].second == 1)
            num[i] = (i + cross[i]) % N;
        else
            num[i] = (i - cross[i] + 2 * N * T) % N;
    }

    vector<long long> ans(N);
    for(int i=0; i<N; i++){
        int n = num[i];
        if(XW[i].second == 1)
            ans[n] = (XW[i].first + T) % L;
        else
            ans[n] = (XW[i].first - T + L * T) % L;
    }
    for(int i=0; i<N; i++)
        cout << ans[i] << endl;

    return 0;
}