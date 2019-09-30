#include<stdio.h>
int f[11][1124][1124];
char g[11][1124][1124];
int M[1124];
int a[11][1124][1124];
#define low(a) ((a)&(-(a)))
#define min(a,b) ((a)<(b)?(a):(b))
int p;
int find(int k,int l,int r,int dep){
	if(dep==1){
		if(k+min(M[l],M[r])>=p)return 0;
		else if(k+min(M[l],M[r])==p-1)return a[dep][l][r];
		else return 1000000000;
	}
	if(g[k][l][r])return f[k][l][r];
	int tmp;
	int ans=1000000000;
	tmp=find(k,l,(l+r)>>1,dep-1)+find(k,((l+r)>>1)+1,r,dep-1);
	if(tmp<ans)ans=tmp;
	tmp=find(k+1,l,(l+r)>>1,dep-1)+find(k+1,((l+r)>>1)+1,r,dep-1)+a[dep][l][r];
	if(tmp<ans)ans=tmp;
	g[k][l][r]=1;
	f[k][l][r]=ans;
	return ans;
}
int main(){
	int T,c;
	scanf("%d",&T);
	for(c=1;c<=T;c++){
		memset(g,0,sizeof g);
		scanf("%d",&p);
		int i;
		for(i=1;i<=1<<p;i++)scanf("%d",M+i);
		int j;
		for(i=1;i<=p;i++)
		for(j=1;j<=1<<p;j+=(1<<i))
			scanf("%d",a[i][j]+(j+(1<<i)-1));
		int ans=find(0,1,1<<p,p);
		printf("Case #%d: %d\n",c,ans);
	}
	return 0;
}
