#include <iostream>
#include <vector>
#include <cstdio>
#include <queue>
#include <algorithm>
#include <functional>
#include <string>
#include <queue>
#include <cmath>
#include <iomanip>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <random>
#include <unordered_map>
#define ll long long
#define fr(i,k,N) for(ll i=k; i<N;i++)
#define rep(i,N) for(ll i=0; i<N;i++)
#define alll(v) v.begin(),v.end()
using namespace std;
template <class X> void pr(X test){cout<<test<<endl;}
template <class X> void prr(X test){for(auto it:test){cout<<it;}cout<<endl;}

bool isSym(const char m[300][300],ll a,ll b,ll c,ll d){
    char inner[b-a][b-a];
    rep(i,b-a) rep(j,b-a){
        inner[i][j] = m[i+a][j+c];
    }
    rep(i,b-a) rep(j,b-a){
        if(inner[i][j] != inner[j][i]){
            return false;
        }
    }
    return true;
};
bool isSym2(const char m[300][300],ll i,ll n){
    return true;
};

int main() {
    ll n;
    cin>>n;
    char mat[300][300];
    rep(i, n) rep(j,n){
        cin>>mat[i][j];
    }
    ll sum=0;
    rep(i, n){
        bool a = isSym(mat,0,n-i,i,n);
        bool b = isSym(mat,n-i,n,0,i);
//        bool c = isSym2(mat,i,n);
        bool c = true;
        fr(ii, 0, n-i) {
            fr(jj, 0, i){
                if(mat[ii][jj]!=mat[n-i+jj][i+ii]){
                    c=false;
                    break;
                }
            }
            if(!c) break;
        }
        if(a&&b&&c) sum+=n;
    }
//    pr(mat[0][1]);
    pr(sum);
}