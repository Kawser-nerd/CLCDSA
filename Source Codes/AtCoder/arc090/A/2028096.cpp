#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>

#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define all(e) e.begin(), e.end()
#define vi vector<int>
#define vd vector<double>

//????AtCoder??define
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;

typedef long long ll;
typedef unsigned long long ull;

const int INF = ~(1 << 31);

using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vi v1(n);
    vi v2(n);
    rep(i, n) cin >> v1[i];
    rep(i, n) cin >> v2[i];

    int max = 0;
    int tmp;
    rep(i, n){
        tmp = 0;
        rep(j, n){
            if(j > i){
                tmp += v2[j];
            }else if(j == i){
                tmp += v2[i];
                tmp += v1[i];
            }else{
                tmp += v1[j];
            }
            //cerr << tmp << endl;
        }
        if(max < tmp){
            max = tmp;
        }
    }

    cout << max << endl;

    return 0;
}