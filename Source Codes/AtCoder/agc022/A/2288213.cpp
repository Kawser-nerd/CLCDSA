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
ll ok[55][55];
ll d[55][55];
/*int main(){
    rep(i,51){
        rep(j,51){
            for(int k = 1;k <= 50;k++){
                if(i%k == j){
                    ok[i][j] = 1LL<<k;
                    break;
                }
            }
            if(ok[i][j]==0){
                ok[i][j] = 1LL<<60;
            }
            d[i][j] = ok[i][j];
        }
    }
    rep(k,51){
        rep(i,51){
            rep(j,51){
                d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    rep(i,51){
        rep(j,51){
            if(d[i][j] < ok[i][j]){
                cout << i << " " << j << endl;
                show(ok[i][j]);
                show(d[i][j]);
            }
        }
    }
    
}*/
int main(){
    string s;
    cin >> s;
    bool cnt[26]={};
    int n = (int)s.size();
    rep(i,n){
        cnt[s[i]-'a'] = true;
    }
    if(s.size()<26){
        cout << s;
        rep(i,26){
            if(!cnt[i]){
                cout << (char)('a'+i)<< endl;
                return 0;
            }
        }
    }else{
        bool used[26] = {};
        rep(i,26){
            used[s[n-1-i]-'a'] = true;
            if(i==0)continue;
            for(char j = s[n-1-i]+1 ; j <='z'; j++){
                if(used[j-'a']){
                    rep(hoge,n-1-i){
                        cout << s[hoge];
                    }
                    cout << j << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << endl;
}