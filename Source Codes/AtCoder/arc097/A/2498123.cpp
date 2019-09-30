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
set<string>st;
int main(){
    string  s;
    cin >> s;
    int k;
    cin >> k;
    int n = (int)s.size();
    rep(i,n){
        for(int j = 1; j <= 5; j++){
            if(i+j>=n+1)continue;
            st.insert(s.substr(i,j));
        }
        if(st.size()>6){
            st.erase(*st.end());
        }
    }
    rep(i,k){
        if(i!=k-1)st.erase(*st.begin());
        else{
            cout << *st.begin() << endl;
        }
    }
}