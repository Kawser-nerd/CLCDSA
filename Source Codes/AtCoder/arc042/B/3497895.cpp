#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int X[19], Y[19];
int px, py, N;

double calc(double a, double c){
    return abs(a*px+py+c)/sqrt(a*a+1);
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>px>>py>>N;
    
    rep(i,N)cin>>X[i]>>Y[i];
    X[N] = X[0];
    Y[N] = Y[0];
    
    double mn=INF;
    rep(i,N){
        int x1=X[i+1]-X[i], y1=Y[i+1]-Y[i], x2=px-X[i], y2=py-Y[i];
        double a = 1.*y1/x1;
        mn = min(mn, calc(-a,X[i]*a-Y[i]));
    }
    printf("%.15f\n",mn);
}