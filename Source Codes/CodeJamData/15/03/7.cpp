#define _CRT_SECURE_NO_WARNINGS

#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <queue>
#include <cstring>
#include <string>
#include <complex>

#define vi vector<int>
#define vpii vector< pair<int,int> >
#define pii pair<int,int>
#define mp(x,y) make_pair(x,y)
#define all(x) (x).begin(),(x).end()
#define FOREACH(it,x) for (auto it = (x).begin(); it!=(x).end(); ++it) 
#define sz(x) (int)(x).size()
#define FOR(i,n) for (ll i = 0; i < ll(n); i++)
#define REP(i,a,b) for (ll i = a; i < ll(b); i++)
#define READ(a) int a; scanf("%d", &a);
#define READV(v,n) vi v(n);FOR(i,n){scanf("%d", &v[i]);}
#define WRITE(v) "";FOR(i,sz(v))cout<<v[i]<<" ";cout
#define gmin(a,b) { if (b < a) a = b; }
#define gmax(a,b) { if (b > a) a = b; }
#define pb push_back
#define ff first
#define ss second
#define X first
#define Y second
#define oo 2140000000ll

typedef long long ll;
typedef unsigned long long ull;
using namespace std;


struct Quat{
public:
	int h, i, j, k;

	Quat(char c){
		if(c=='1'){
			h=1;i=0;j=0;k=0;
		}
		if(c=='i'){
			h=0;i=1;j=0;k=0;
		}
		if(c=='j'){
			h=0;i=0;j=1;k=0;
		}
		if(c=='k'){
			h=0;i=0;j=0;k=1;
		}
	}

	Quat(){}
};

bool eq(Quat q1, Quat q2){
	return q1.h == q2.h && q1.i == q2.i && q1.j == q2.j && q1.k == q2.k;
}

Quat mult(Quat q1, Quat q2){
	Quat q;
	q.h = q1.h*q2.h - q1.i*q2.i - q1.j*q2.j - q1.k*q2.k;
	q.i = q1.h*q2.i + q1.i*q2.h + q1.j*q2.k - q1.k*q2.j;
	q.j = q1.h*q2.j - q1.i*q2.k + q1.j*q2.h + q1.k*q2.i;
	q.k = q1.h*q2.k + q1.i*q2.j - q1.j*q2.i + q1.k*q2.h;
	return q;
}


int main(){
	Quat qi('i');
	Quat qj('j');
	Quat qk('k');
	
	Quat qs;
	READ(T);
	FOR(t,T){
	    READ(n);
		ll x;
		cin>>x;
		x = min(x, x%4 + 16);
		string s;
		cin>>s;
		qs = Quat('i');
		Quat akt('1');
		FOR(i,x*n){
			Quat q(s[i%n]);
			akt = mult(akt, q);
			if(eq(akt,qs)){  
				if(eq(qs,qi)){
					qs = qj;
					akt = Quat('1');
				}else if(eq(qs,qj)){
					qs = qk;
					akt = Quat('1');
				}
			}
		}
		if(eq(qs,qk) && eq(akt, qs)){
			cout<<"Case #"<<(t+1)<<": YES"<<endl;
		}else{
			cout<<"Case #"<<(t+1)<<": NO"<<endl;
		}
	}
	return 0;
}