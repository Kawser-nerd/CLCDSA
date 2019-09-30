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
int main(){
    int n;
    cin >> n;
    vector<int>a(n);
    rep(i,n)cin >> a[i];
    int ans = 0;
    rep(i,n){
        int j = 1;
        while(i+j<n){
            if(a[i]==a[i+j]){
                j++;
            }else{
                break;
            }
        }
        ans +=j/2;
        i+=j-1;
    }
    cout << ans << endl;
}