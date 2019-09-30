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


int main(){
	READ(T);
	FOR(t,T){
	    READ(x);
		READ(r);
		READ(c);
		if(c<r) swap(r,c);
		if((r*c)%x!=0){
			cout<<"Case #"<<(t+1)<<": RICHARD"<<endl; continue;
		}

		if(x>=7){
			cout<<"Case #"<<(t+1)<<": RICHARD"<<endl; continue;
		}
		if(x==1){
			cout<<"Case #"<<(t+1)<<": GABRIEL"<<endl; continue;
		}
		if(x==2){
			cout<<"Case #"<<(t+1)<<": GABRIEL"<<endl; continue;
		}
		if(x==3){
			if(r==1 || c==1){
				cout<<"Case #"<<(t+1)<<": RICHARD"<<endl; continue;
			}else{
				cout<<"Case #"<<(t+1)<<": GABRIEL"<<endl; continue;
			}
		}
		if(x==4){
			if(r<=2 || c<=2){
				cout<<"Case #"<<(t+1)<<": RICHARD"<<endl; continue;
			}else{
				cout<<"Case #"<<(t+1)<<": GABRIEL"<<endl; continue;
			}
		}
		if(x==5){
			if(r<=2 || c<=2){
				cout<<"Case #"<<(t+1)<<": RICHARD"<<endl; continue;
			}else{
				if(r==3 && c==5){
					cout<<"Case #"<<(t+1)<<": RICHARD"<<endl; continue;
				}else{
					cout<<"Case #"<<(t+1)<<": GABRIEL"<<endl; continue;
				}
			}
		}
		if(x==6){
			if(r<=3 || c<=3){
				cout<<"Case #"<<(t+1)<<": RICHARD"<<endl; continue;
			}else{
				cout<<"Case #"<<(t+1)<<": GABRIEL"<<endl; continue;
			}
		}
	}
	return 0;
}