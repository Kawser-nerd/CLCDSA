#pragma comment(linker, "/STACK:65777216")

#include <algorithm>
#include <iostream>
#include <string>
#include<sstream>
#include<string.h>
#include <cstdio>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef unsigned long long ull;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define SORT(v) sort((v).begin(),(v).end())
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back

int n,m;
int u[2222];
int v[2222];

bool has(vi v,int x){
	REP(i,v.size()) if(v[i]==x) return 1;
	return 0;
}

vector<vi> vv;

void parse(int x,int y){
	vi v1,v2;
	vi v = vv.back();vv.pop_back();

	int i1 = -1,i2=-1;
	REP(i,v.size()){
		if(v[i] == x) i1 = i;
		if(v[i] == y) i2 = i;
	}
	if(i1>i2) swap(i1,i2);

	FOR(i,i1,i2+1) v1.pb(v[i]);
	for(int i=i2;;i++){
		if(i==v.size()) i=0;
	
		v2.pb(v[i]);

		if(i==i1) break;
	}

	vv.pb(v1);
	vv.pb(v2);
}

int r[2222];

void check(int mn){
	REP(i,vv.size()){
		int mm = 0;
		REP(j,vv[i].size()) mm |= 1<<r[vv[i][j]];

		if(mm!=(1<<mn)-1) 
			puts("FUCK");
	}	
}

vi C[2222][2222];

void putcolor(int v1,int v2,int c1,int c2,int dont,int numc){
	r[v1] = c1;
	r[v2] = c2;

	int usecomp=-1;
	REP(i,C[v1][v2].size()) if(C[v1][v2][i]!=dont){
		usecomp = C[v1][v2][i];
		break;
	}
	if(usecomp==-1) return;

	int curr_col = 0;
	REP(i,vv[usecomp].size()){
		while(curr_col == c1 || curr_col == c2) curr_col++;
		if(curr_col >= numc) break;
		int ver = vv[usecomp][i];
		if(r[ver]==-1){
			r[ver] = curr_col;
			curr_col++;
		}
	}
	REP(i,vv[usecomp].size()){
		int ver = vv[usecomp][i];
		if(r[ver]!=-1) continue;
		int prev = vv[usecomp][(i+vv[usecomp].size()-1)%vv[usecomp].size()];
		int next = vv[usecomp][(i+1)%vv[usecomp].size()];
		REP(j,3) if(j!=r[prev] && j!=r[next]){
			r[ver] = j;
			break;
		}
	}
	REP(i,vv[usecomp].size()){
		int ver = vv[usecomp][i];
		int next = vv[usecomp][(i+1)%vv[usecomp].size()];
		if(ver == v1 && next == v2 || ver == v2 && next == v1) continue;
		putcolor(ver,next,r[ver],r[next],usecomp,numc);
	}
}

int main(){ 
#ifdef LocalHost
    freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int tc;
	cin>>tc;
	REP(TC,tc){
		cin>>n>>m;
		//n=2000;
		//m=500;
		REP(i,m) scanf("%d",u+i),u[i]--;
		REP(i,m) scanf("%d",v+i),v[i]--;
		vi t;
		REP(i,n) t.pb(i);
		vv.clear();
		vv.pb(t);

		REP(i,m){
			int U = u[i];
			int V = v[i];
			REP(j,vv.size()) if(has(vv[j],U) && has(vv[j],V)){
				swap(vv[j],vv.back());
				parse(U,V);
				break;
			}
		}
	
		CL(r,-1);
		REP(i,n)REP(j,n) C[i][j].clear();
		REP(i,vv.size())
			REP(j,vv[i].size())
				REP(k,vv[i].size()) if(j!=k)
					C[vv[i][j]][vv[i][k]].pb(i);

		int mn = 10000;
		REP(i,vv.size()) mn = min(mn, (int) vv[i].size());
		
		putcolor(0,1,1,2,-1,mn);

	//	best=0;
		//go(0,0);
		printf("Case #%d: %d\n",TC+1,mn);
		//if(mn!=best) puts("FUCK");
		REP(i,n){
			if(i)printf(" ");
			printf("%d",r[i]+1);
		}
		puts("");
		//check(mn);
	}
	return 0;
}