#include <algorithm>
#include <iostream>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>
#include <bitset>
#include <math.h>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <complex>

#pragma comment(linker, "/STACK:60777216")

using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef vector<pii> vpi;
typedef pair<ld,ld> pdd;
typedef complex<ld> VEC;
typedef vector<pdd> vdd;
typedef unsigned long long ul;
typedef unsigned int UI;
typedef pair<pii,int> p3i;
typedef vector<p3i> vp3i;
typedef vector<double> vd;

#define F(i,a,b) for (int _n(b), i(a); i < _n; i++) 
#define FD(i,a,b) for (int _n(b), i(a); i >= _n; i--) 
#define R(i,n) F(i,0,n) 
#define SORT(a) sort((a).begin(),(a).end())
#define UN(v) SORT(v),v.erase(unique(v.begin(),v.end()),v.end())
#define RV(v) reverse((v).begin(),(v).end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

const int INF = 1011111111;
const double Pi =acos(-1.);
const double eps =1e-9;

int nb(int x){return x?nb(x&(x-1))+1:0;}
ll gcd(ll a,ll b){while(a&&b){if(a>b) a%=b;else b%=a;}return a+b;}
int gcd(int a,int b){while(a&&b){if(a>b) a%=b;else b%=a;}return a+b;}


const int MOD =30031;

int TC;
bool u[1111][5000];
ll   d[1111][5000];
int n,p,k;
int t_m;
ll go(int pos,int mask){
	if(pos==k) return mask==t_m ? 1 :0;
	if(u[pos][mask]) return d[pos][mask];
	if(!(mask&1)) return 0;//go(pos-1,mask>>1);
	ll val=0;
	F(i,1,p+1) if(!(mask&(1<<i)))
		val+=go(pos-1,(mask|(1<<i))>>1),val%=MOD;
	return u[pos][mask]=true,d[pos][mask]=val;
}

int main(){    
    
    freopen("input.txt","r",stdin);       
    freopen("output.txt","w",stdout);   
	cin>>TC;
	R(tc,TC){
		cout<<"Case #"<<tc+1<<": ";

		cin>>n>>k>>p;
		t_m=0;
		R(i,k)  t_m|=(1<<i);

		CL(u,false);
		cout<<go(n,t_m);


		cout<<endl;
	}
    
    return 0;
}   