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
typedef long long ll;
typedef pair<int, int> pii;
int a[100000];
vector<int>g[100000];
int k;
int ans;
int dfs(int s){
    int res = 0;
    for(int x:g[s]){
        res = max(res, dfs(x)+1);
    }
    if(res == k-1 and a[s] != 0){
        ans++;
        res = -1;
    }
    return res;
}
int main(){
    int n;
    scanf("%d%d",&n,&k);
    rep(i,n){
        scanf("%d",a+i);
        a[i]--;
    }
    if(a[0] != 0){
        ans++;
        a[0] = 0;
    }
    rep(i,n-1){
        g[a[i+1]].push_back(i+1);
    }
    //rep(i,n)show(g[i].size());
    dfs(0);
    cout << ans << endl;
}