//#include "bits/stdc++.h"
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
#include <numeric>
#include <complex>
#include <bitset>
#include <functional>
#include <stack>
#include <regex>
#include <tuple>

#define int long long
#define REP(i,a,n) for(int i=a;i<n;++i)
#define rep(i,n) REP(i,0,n)
#define REV(i,a,n) for(int i=n;i>=a;--i)
#define all(e) e.begin(),e.end()
#define rall(e) e.rbegin(),e.rend()
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define mod 1000000007
#define show(n) cerr<<#n<<" = "<<n<<endl
#define showp(n) cerr<<n.fs<<", "<<n.sc<<endl
#define shows(n) for(auto z:n){cerr<<z<<", ";}cerr<<endl
#define showsp(n) for(auto z:n){cerr<<z.fs<<" "<<z.sc<<", "}cerr<<endl

#define yes printf("Yes\n")
#define no printf("No\n")
#define case(i) printf("Case #%lld: ",i)

using namespace std;

using ull=unsigned long long;
using vi=vector<int>;
using pint=pair<int,int>;

const int INF=1LL<<55;

int a,b,c;
int x,y;

int kane = 0;

signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>a>>b>>c>>x>>y;
    c *= 2;

    if(x > y){
        //small=y, b
        if(c<a+b){
            if(c<a){ kane+=c*x; }
            else {
                kane+=c*y;
                kane+=a*(x-y);
            }
        }else{
            kane+=a*x;
            kane+=b*y;
        }
    }else if(x < y){
        //x,a
        if(c<a+b){
            if(c<b){ kane+=c*y; }
            else {
                kane+=c*x;
                kane+=b*(y-x);
            }
        }else{
            kane+=a*x;
            kane+=b*y;
        }
    }else{
        if(c<=a+b){
            kane=c*x;
        }else{
            kane+=a*x;
            kane+=b*y;
        }
    }
    cout<<kane<<endl;
    
    return 0;
}