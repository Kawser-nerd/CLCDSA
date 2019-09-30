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
#include <unordered_set>
#define ll long long
#define fr(i,k,N) for(ll i=k; i<N;i++)
#define rep(i,N) for(ll i=0; i<N;i++)
#define alll(v) v.begin(),v.end()
using namespace std;
template <class X> void pr(X test){cout<<test<<endl;}
template <class X> void prr(X test){for(auto it:test){cout<<it<<endl;}cout<<endl;}

int main() {
    ll n;
    cin>>n;
    vector<pair<ll,ll>> v;
    if(n%2 == 0){
        // even
        fr(i,1 , n){
            fr(j, i+1, n+1){
                if(i + j == n + 1) continue;
                v.push_back(make_pair(i, j));
            }
        }
        pr(v.size());
        for(auto it:v){
            cout<<it.first<< " " << it.second<<endl;
        }
    }else{
        n--;
        fr(i,1 , n){
            fr(j, i+1, n+1){
                if(i + j == n + 1) continue;
                v.push_back(make_pair(i, j));
            }
        }
        rep(i, n){
            v.push_back(make_pair(i+1, n+1));
        }
        pr(v.size());
        for(auto it:v){
            cout<<it.first<< " " << it.second<<endl;
        }
    }

    return 0;
}