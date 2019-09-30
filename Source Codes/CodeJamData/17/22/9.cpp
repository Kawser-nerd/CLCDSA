#include<iostream>
#include<cmath>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int x[7],n,y[4];
char ch[7]={' ','R','O','Y','G','B','V'};
int aim[7]={0,4,5,6,1,2,3};
int ans[1100],pd[10],Ans[1100],N;
void print(int k){
	putchar(ch[k]); Ans[++N]=k;
	if (pd[k]==0){
		int ne=aim[k];
		for (int i=1;i<=x[ne];i++){
			putchar(ch[ne]); putchar(ch[k]);
			Ans[++N]=ne; Ans[++N]=k;
		}
		pd[k]=1; return;
	}
}
int check(){
	Ans[N+1]=Ans[1];
	for (int i=1;i<=N;i++){
		int a=Ans[i],b=Ans[i+1];
		if (a==b) return 0;
		if (a%2==0&&b!=aim[a]) return 0;
		if (b%2==0&&a!=aim[b]) return 0;
	}
	return 1;
}
void solve(){
	scanf("%d",&n); 
	memset(pd,0x00,sizeof pd); N=0; memset(Ans,0x00,sizeof Ans);
	for (int i=1;i<=6;i++) scanf("%d",&x[i]);
	n=0; for (int i=1;i<=6;i++) n+=x[i];
	for (int i=2;i<=6;i+=2){
		if (x[i]==0) continue;
		int j=aim[i];
		if (x[j]<x[i]){
			printf("IMPOSSIBLE\n"); return;
		}
		if (x[j]==x[i]){
			if (x[j]+x[i]==n){
				for (int k=1;k<=n;k++) if (k&1) putchar(ch[i]); else putchar(ch[j]);
				putchar('\n'); return;
			} else {
				printf("IMPOSSIBLE\n"); return;
			}
		}
		x[j]=x[j]-x[i];
	}
	if (max(x[1],max(x[3],x[5]))>(x[1]+x[3]+x[5])/2){
		printf("IMPOSSIBLE\n"); return;
	}
	int k1=1,k2=3,k3=5;
	if (x[k2]>x[k1]) swap(k1,k2);
	if (x[k3]>x[k1]) swap(k1,k3);
	int len=0;
	for (int i=1;i<=x[k1];i++){
		ans[++len]=k1;
		if (i<=x[k2]) ans[++len]=k2;
		if (i>=x[k1]-x[k3]+1) ans[++len]=k3;
	}
	for (int i=1;i<=len;i++) print(ans[i]);
	putchar('\n');
	if (check()==0){
		cerr<<"fa "<<x[1]<<" "<<x[3]<<" "<<x[5]<<endl;
		for (int i=1;i<=N;i++) cerr<<Ans[i]<<" "; cerr<<endl;
		for (int i=1;i<=len;i++) cerr<<ans[i]<<" "; cerr<<endl;
	}
}
int main(){
	freopen("Bl.in","r",stdin);
	freopen("Bl.out","w",stdout);
	int t; scanf("%d",&t);
	for (int i=1;i<=t;i++){
		printf("Case #%d: ",i); solve();
	}
	return 0;
}

