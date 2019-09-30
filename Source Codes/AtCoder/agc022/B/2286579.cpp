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
vector<int> solve(int n){
    vector<int>ans(n);
    vector<bool>used(300001,false);
    ll sum = 0;
    int cnt = 0;
    for(int i = 2;i <= 300000;i++){
        if((__gcd(i,6)!=1) and !used[i]){
            ans[cnt] = i;
            used[i] = true;
            sum+=i;
            cnt++;
        }
        if(cnt==n-1)break;
    }
    for(int i = 2;i <= 300000;i++){
        if(!used[i] and (sum+i)%6==0 and __gcd(sum,(ll)i)!=1){
            ans[cnt] = i;
            sum+=i;
            //show(sum);
            break;
        }
    }
    
    return ans;
}
bool check(vector<int> &ans){
    sort(ans.begin(),ans.end());
    int n = (int)ans.size();
    rep(i,n-1){
        if(ans[i]==ans[i+1])return false;
    }
    int k = ans[0];
    ll sum = 0;
    rep(i,ans.size()){
        k = __gcd(k,ans[i]);
        sum+=ans[i];
    }
    show(sum);
    if(k!=1)return false;
    rep(i,ans.size()){
        if(__gcd(sum-(ll)ans[i],(ll)ans[i])==1){
            return false;
        }
    }
    return true;
}
int main(){
    int n;
    cin >> n;
    auto res = solve(n);
    if(1){
        rep(i,n-1){
            cout << res[i] << " ";
        }
        cout << res[n-1] << endl;
    }else{
        //cout << "WA" << endl;
    }
    return 0;
}