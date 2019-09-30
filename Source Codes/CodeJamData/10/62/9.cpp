#pragma comment(linker, "/STACK:836777216")

#include <algorithm>
#include <iostream>
#include<stdio.h>
#include <string>
#include<sstream>   
#include<string.h>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include<stack>
#include <set>
#include <map>
#include<ctime>
#include<memory.h>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<double,double> pdd;
typedef pair<int,pii> p3i;
typedef long double ld;
typedef vector<ld> vd;

#define FOR(i,a,b) for (int i(a); i < (b); i++) 
#define REP(i,n) FOR(i,0,n) 
#define UN(v) sort((v).begin(),(v).end()),v.erase(unique(v.begin(),v.end()),v.end())
#define CL(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define SORT(a) sort((a).begin(),(a).end())

vi a[1111][1111];
int n;

bool c[1111][1111];

int go(int i,int j,int par=-1){
	int res = 2;
	REP(k,a[i][j].size())if(a[i][j][k]!=par)
		res = max(res, go(i,a[i][j][k],j) + go(a[i][j][k],j,i)-1);
	return res;
}

int X[1111],Y[1111];

int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);

	int TC;
	cin>>TC;
	REP(tc,TC){
		CL(c,0);
		c[0][1]=c[1][0]=1;
		c[1][2]=c[2][1]=1;
		c[0][2]=c[2][0]=1;

		cin>>n;
		REP(i,n)REP(j,n) a[i][j].clear();

		a[0][1].pb(2);
		a[1][0].pb(2);
		a[1][2].pb(0);
		a[2][1].pb(0);
		a[0][2].pb(1);
		a[2][0].pb(1);
		REP(i,n-3){
			int x,y;

			scanf("%d %d",&x,&y);
			x--,y--;
			X[i+3]=x;
			Y[i+3]=y;

			if(!c[x][y])
				puts("FUCK");
			c[i+3][x]=c[x][i+3]=1;
			c[i+3][y]=c[y][i+3]=1;//[

			a[x][y].pb(i+3);
			a[y][x].pb(i+3);
			a[x][i+3].pb(y);
			a[i+3][x].pb(y);
			a[y][i+3].pb(x);
			a[i+3][y].pb(x);
		}		
		int res = go(0,1,2) + go(1,2,0) + go(0,2,1)-3;
		REP(i,n-3){
			res=max(res,go(i+3,X[i+3],Y[i+3])+go(X[i+3],Y[i+3],i+3)+go(Y[i+3],i+3,X[i+3])-3);
		}

		printf("Case #%d: %d\n",tc+1,res);
	}

	return 0;
}