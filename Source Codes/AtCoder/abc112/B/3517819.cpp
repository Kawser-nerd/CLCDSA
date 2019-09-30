#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<utility>
#include<map>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define REPR(i,n) for(int i=n-1;i>=0;i--)
#define FORR(i,n,m) for(int i=n-1;i>=m;i--)
#define all(in) in.begin(),in.end()
#define ALL(in,K) in,in+K
#define INF 1e18
#define MOD 100000007
#define SIZE 100005
#define PI 	3.14159265358979323846

int main(){
    int N,T;
    cin >> N >> T;
    int ans = 20000;
    REP(i,N){
        int c,t;
        cin >> c >> t;
        if(t<=T)ans = min(ans,c);
    }
    if(ans==20000){
        cout << "TLE" << endl;
        return 0;
    }
    cout << ans;
}