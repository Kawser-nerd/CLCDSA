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
int main(){
    int n;
    cin >> n;
    vector<int>x(n);
    vector<int>a(n);
    rep(i,n){
        scanf("%d",&x[i]);
        a[i] = x[i];
    }
    sort(a.begin(),a.end());
    int b = a[n/2-1];
    int c = a[n/2];
    rep(i,n){
        int ans;
        if(x[i] <= b){
            ans = c;
        }
        if(x[i]>=c){
            ans = b;
        }
        cout << ans << endl;
    }
}