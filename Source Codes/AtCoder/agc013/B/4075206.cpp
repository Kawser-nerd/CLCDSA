#include <algorithm>
#include <bitset>
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
#define show(x) cout << #x << " = " << (x) << endl;
using namespace std;
using ll = long long;
using pii = pair<int,int>;
vector<int>g[123456];
vector<int>ans;
bool used[123456];
int main(){
    int n,m;
    cin >> n >> m;
    rep(i,m){
        int a,b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    int now = 1;
    ans.push_back(now);
    used[now] = true;
    while(1){
        bool flag = false;
        for(int x:g[now]){
            if(!used[x]){
                now = x;
                used[now] = true;
                ans.push_back(now);
                flag = true;
                break;
            }
        }
        if(!flag)break;
    }
    reverse(ans.begin(),ans.end());
    now = 1;
    while(1){
        bool flag = false;
        for(int x:g[now]){
            if(!used[x]){
                now = x;
                used[now] = true;
                ans.push_back(now);
                flag = true;
                break;
            }
        }
        if(!flag)break;
    }
    cout << ans.size() << endl;
    rep(i,ans.size()){
        cout << ans[i] << " ";
    }
    cout << endl;
}