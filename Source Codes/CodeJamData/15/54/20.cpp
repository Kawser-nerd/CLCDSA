#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<cstdlib>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<queue>
#include<bitset>
using namespace std;
typedef long long ll;
typedef double db;
const db pi=acos(-1);
void gn(int &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
void gn(ll &x){
	int sg=1;char c;while(((c=getchar())<'0'||c>'9')&&c!='-');
	if(c=='-')sg=-1,x=0;else x=c-'0';
	while((c=getchar())>='0'&&c<='9')x=x*10+c-'0';
	x*=sg;
}
const int mo=1000000007;
int qp(int a,ll b){int ans=1;do{if(b&1)ans=1ll*ans*a%mo;a=1ll*a*a%mo;}while(b>>=1);return ans;}

struct node{
	ll su,nu;
}a[11111],tmp[111111],tar[11111];
int ttot=0;


ll an[100];int tot=0;


int check(ll x,int p){
	ttot=0;
	for (int i=1;i<=p;i++)tmp[i]=a[i];
	ll d=abs(x);
	for (int i=1,j=1;i<=p;i++){
		if(tmp[i].nu==0)continue;
		while(j<=p && tmp[j].su!=tmp[i].su+d)j++;
		if(j>p)return 0;
		if(i==j){
			if(tmp[i].nu&1)return 0;
			tmp[i].nu>>=1;
			tar[++ttot]=(node){tmp[i].su,tmp[i].nu};
		}else{
			if(tmp[j].nu<tmp[i].nu)return 0;
			if(x>0)tar[++ttot]=(node){tmp[i].su,tmp[i].nu};
			else tar[++ttot]=(node){tmp[i].su+d,tmp[i].nu};
			tmp[j].nu-=tmp[i].nu;
		}
	}
	return 1;
}
int doit(){
	for (int i=1;i<=ttot;i++)a[i]=tar[i];
	return ttot;
}
void solve(int n,int p){
	if(n==0)return;
	for (int i=1;i<=p;i++)if(check(a[i].su,p)){
		an[++tot]=a[i].su;
		int np=doit();
		solve(n-1,np);
	}
}

int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int tes;
	scanf("%d",&tes);
	for (int tt=1;tt<=tes;tt++){
		tot=0;
		int p;
		printf("Case #%d: ",tt);
		scanf("%d",&p);
		ll allnu=0;
		for (int i=1;i<=p;i++)gn(a[i].su);
		for (int i=1;i<=p;i++)gn(a[i].nu),allnu+=a[i].nu;
		int n;
		for (int i=1;i<=60;i++)if(1ll<<i==allnu){
			n=i;break;
		}
		solve(n,p);
		for (int i=1;i<=n;i++){
			if(i==1)printf("%lld",an[i]);
			else printf(" %lld",an[i]);
		}
		printf("\n");
	}
	return 0;
}





