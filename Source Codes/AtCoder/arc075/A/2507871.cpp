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
    vector<int>s(n);
    int sum = 0;
    rep(i,n){
        cin >> s[i];
        sum += s[i];
    }
    sort(s.begin(),s.end());
    if(sum%10){
        cout << sum << endl;
        return 0;
    }else{
        rep(i,n){
            if((sum-s[i])%10){
                cout << sum-s[i] << endl;
                return 0;
            }
        }
        cout << 0 << endl;
    }
}