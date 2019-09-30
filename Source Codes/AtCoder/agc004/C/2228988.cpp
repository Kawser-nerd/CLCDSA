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
bool ans[500][500];
bool in[505][505];
int main(){
    int h,w;
    cin >> h >> w;
    rep(i,h){
        rep(j,w-1){
            if(i%2==0)ans[i][j] = true;
            else if(j==0)ans[i][j] = true;
        }
    }
    rep(i,h){
        string s;
        cin >> s;
        rep(j,w){
            in[i][j] = s[j]=='#';
        }
    }
    rep(i,h){
        rep(j,w){
            if(ans[i][j] or in[i][j]){
                cout << '#';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }
    cout << endl;
    rep(i,h){
        rep(j,w){
            if(!ans[i][j] or in[i][j]){
                cout << '#';
            }else{
                cout << '.';
            }
        }
        cout << endl;
    }
    return 0;
}