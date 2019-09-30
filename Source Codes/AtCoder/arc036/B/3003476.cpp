#include <algorithm>
#include <cassert>
#include <cctype>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <vector>
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define show(x) cout << #x << " = " << x << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
int used[323456];
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    priority_queue<pii>pq;
    int ans = 0;
    rep(i,n){
        cin >> a[i];
        pq.push(pii(a[i],i));
    }
    while(!pq.empty()){
        auto x = pq.top();
        pq.pop();
        if(used[x.second]>=1)continue;
        int id = x.second;
        used[id]++;
        int temp = 1;
        while(id+1 < n and a[id] > a[id+1]){
            used[id+1]++;
            temp++;
            id++;
        }
        id = x.second;
        while(id-1 >= 0 and a[id-1] < a[id]){
            used[id-1]++;
            temp++;
            id--;
        }
        ans = max(temp,ans);
    }
    cout << ans << endl;
}