#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
#define ll long long
#define pii pair<int,int>
#define pb push_back
#define popb pop_back
#define ub upper_bound
#define lb lower_bound
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mmin(x) memset((x),-1,sizeof((x)))
#define mnul(x) memset((x),0,sizeof((x)))
#define N 2005
//const int inf= 1000000005;
//const int MOD= 1000000007;
//const int N= 2005;

char a[N][N];
int v[N][N],e[N][N];
int er[N][N],ec[N][N];

int getver(int a,int b,int c,int d){
	return v[c][d]+v[a-1][b-1]-v[a-1][d]-v[c][b-1];
}

int geted(int a,int b,int c,int d){
	int ret=e[c][d]+e[a-1][b-1]-e[a-1][d]-e[c][b-1];
	ret-=(er[a][d]-er[a][b-1]);
	ret-=(ec[c][b]-ec[a-1][b]);
	return ret;
}

int main(){
	int n,m,q;
	scanf("%d %d %d",&n,&m,&q);
	getchar();
	mnul(a);mnul(v);mnul(e);
	mnul(er);mnul(ec);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			scanf("%c",&a[i][j]);
			v[i][j]=v[i-1][j]+v[i][j-1]-v[i-1][j-1];
			e[i][j]=e[i-1][j]+e[i][j-1]-e[i-1][j-1];
			er[i][j]=er[i][j-1];
			ec[i][j]=ec[i-1][j];
			if(a[i][j]=='0')continue;
			v[i][j]++;
			if(i>1 && a[i-1][j]=='1'){ e[i][j]++; er[i][j]++;}
			if(j>1 && a[i][j-1]=='1'){ e[i][j]++; ec[i][j]++;}
		}
		getchar();
	}
	for(int i=0;i<q;i++){
		int x1,x2,y1,y2;
		scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
		int ed=geted(x1,y1,x2,y2);
		int ver=getver(x1,y1,x2,y2);
		printf("%d\n",ver-ed);
	}
}