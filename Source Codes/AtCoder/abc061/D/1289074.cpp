#include<stdio.h>
#include<algorithm>
#define rep(i,n)for(int i=0;i<(n);i++)
using namespace std;
typedef long long ll;

ll d[1000][1000];
int main(){
	int n,m;scanf("%d%d",&n,&m);
	rep(i,n)rep(j,n){
		if(i==j)d[i][j]=0;
		else d[i][j]=-1e18;
	}
	rep(i,m){
		int a,b,c;scanf("%d%d%d",&a,&b,&c);a--;b--;
		d[a][b]=c;
	}
	rep(k,n)rep(i,n)rep(j,n)d[i][j]=max(d[i][j],d[i][k]+d[k][j]);
	if(d[0][0]>0)puts("inf");
	else printf("%lld\n",d[0][n-1]);
}