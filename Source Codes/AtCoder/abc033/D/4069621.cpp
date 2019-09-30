#include<vector>
#include<cmath>
#include<map>
#include<cstdlib>
#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<set>
#include<stack>
#include<bitset>
#include<functional>
#include<ctime>
#include<queue>
#include<deque>
#include<complex>
#include<cassert>
//#include <bits/stdc++.h>
using namespace std;
struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);cout.precision(20);}} fast;

/* define */
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define COUNT(V,X) (upper_bound((V).begin(),(V).end(),X)-lower_bound((V).begin(),(V).end(),X))
#define debug(x) cerr<<#x<<':'<<x<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto xXx:v)cerr<<xXx<<' ';cerr<<endl;
#define Yes(X) if(X){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define YES(X) if(X){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define ctoi(C) (C-'0')

/* alias */
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using pi = pair<int,int>;
using pl = pair<long long,long long>;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

/* const */
const long long dx[] = {1,0,-1,0};
const long long dy[] = {0,1,0,-1};
const long long dx8[] = {1,1,0,-1,-1,-1,0,1};
const long long dy8[] = {0,1,1,1,0,-1,-1,-1};
const long long dx9[] = {1,1,0,-1,-1,-1,0,1,0};
const long long dy9[] = {0,1,1,1,0,-1,-1,-1,0};
const int INF = 1000000007;
const long long LINF = 1000000000000000007;

/* func */
template <typename T> inline bool chmin(T& a, const T& b) {if (a > b) a = b; return a > b;}
template <typename T> inline bool chmax(T& a, const T& b) {if (a < b) a = b; return a < b;}
long long max(long long x,int y){return max(x,(long long)y);}
long long max(int x,long long y){return max((long long)x,y);}
long long min(long long x,int y){return min(x,(long long)y);}
long long min(int x,long long y){return min((long long)x,y);}

/* liblary */



/* main */

int x[2000],y[2000];
int table[2000][2000];
int N,A,B,C,D,E;
int ei,cho,don;
int i,j,k;

signed main(){
    cin >> N;
    for(i=0;i<N;i++)cin >> x[i] >> y[i];
    for(i=0;i<N;i++)for(j=i+1;j<N;j++){
        table[i][j]=(x[i]-x[j])*(x[i]-x[j]);
    }
  	for(i=0;i<N;i++)for(j=i+1;j<N;j++){
        table[i][j]+=(y[i]-y[j])*(y[i]-y[j]);
    }
    for(i=0;i<N;i++)for(j=i+1;j<N;j++)for(k=j+1;k<N;k++){
        A = table[i][j];
        B = table[i][k];
        C = table[j][k];
        D = A;
        if(D<B)D=B;
        if(D<C)D=C;
        E = A+B+C-(D<<1);
        if(E>0){ei++;continue;}
        if(E==0){cho++;continue;}
        don++;
    }
    cout << ei << ' ' << cho << ' ' << don << endl;
}