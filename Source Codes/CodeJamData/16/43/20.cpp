#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,b[20][20],m,A[100],B[100],pd[20][20][5];
int dfs(int k1,int k2,int k3){
//	cout<<"dfs "<<k1<<" "<<k2<<" "<<k3<<endl;
	if (pd[k1][k2][k3]) return -1;
	pd[k1][k2][k3]=1;
	if (k1==0){
		return k2;
	}
	if (k2==m+1){
		return m+k1;
	}
	if (k1==n+1){
		return m-k2+1+n+m;
	}
	if (k2==0){
		return n-k1+1+n+m+m;
	}
	if (b[k1][k2]==0){
		if (k3==0) return dfs(k1,k2-1,1);
		else if (k3==3) return dfs(k1-1,k2,2);
		else if (k3==1) return dfs(k1+1,k2,0);
		else return dfs(k1,k2+1,3);
	} else if (k3==0) return dfs(k1,k2+1,3);
	else if (k3==1) return dfs(k1-1,k2,2);
	else if (k3==2) return dfs(k1,k2-1,1);
	else return dfs(k1+1,k2,0);
}
int check(){
	memset(pd,0x00,sizeof pd);
//	for (int i=1;i<=n;i++){
//		for (int j=1;j<=m;j++) cout<<b[i][j]; cout<<endl;}
	for (int i=1;i<=n+m;i++){
		int num;
		if (A[i]<=m) num=dfs(1,A[i],0);
		else if (A[i]<=n+m) num=dfs(A[i]-m,m,1);
		else if (A[i]<=n+m+m) num=dfs(n,m-(A[i]-n-m)+1,2);
		else num=dfs(n-(A[i]-n-m-m)+1,1,3);
	//	cout<<num<<" "<<B[i]<<endl;
		if (num!=B[i]) return 0;
	}
	return 1;
}
int dfs(int k1,int k2){
	if (k2>m){
		k1++; k2=1;
	}
	if (k1>n) return check();
	if (dfs(k1,k2+1)) return 1;
	b[k1][k2]=1;
	if (dfs(k1,k2+1)) return 1;
	b[k1][k2]=0;
	return 0;
}  
int solve(){
	scanf("%d%d",&n,&m);
	memset(b,0x00,sizeof b);
	for (int i=1;i<=n+m;i++) scanf("%d%d",&A[i],&B[i]);
	if (dfs(1,1)==0) cout<<"IMPOSSIBLE"<<endl;
	else {
		for (int i=1;i<=n;i++){
			for (int j=1;j<=m;j++)
				if (b[i][j]==0) printf("/"); else printf("\\");
			putchar('\n');
		}
	}
}
int main(){
	freopen("Cs.in","r",stdin);
	freopen("Cs.out","w",stdout);
	int t; scanf("%d",&t);
	for (int tt=1;tt<=t;tt++){
		printf("Case #%d:\n",tt);
		solve();
	}
}
