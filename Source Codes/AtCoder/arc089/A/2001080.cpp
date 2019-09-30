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

#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define vsort(v) sort(v.begin(),v.end())
#define asort(a,n) sort(a, a + n)
#define vi vector<int>
#define vd vector<double>

//????AtCoder??define
#define yes cout << "Yes" << endl;
#define no cout << "No" << endl;

using namespace std;
int x[100001];
int y[100001];
int t[100001];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    rep(i, n) cin >> t[i] >> x[i] >> y[i];
    
    int sx = 0;int sy = 0;int st = 0;
    int sat, sax, say;
    int atleast;
    rep(i, n){
        sat = t[i] - st;
        sax = abs(x[i] - sx);
        say = abs(y[i] - sy);
        atleast = sax + say;
        //cerr << atleast << endl;
        if(atleast > sat || (sat - atleast) % 2 != 0){
            no;
            return 0;
        }
        st = t[i];sx = x[i];sy = y[i];
    }
    yes;
    
    return 0;
}