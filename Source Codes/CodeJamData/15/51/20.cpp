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
int n,d;
int s[1111111],as,cs,rs,m,am,cm,rm;
int pre[1111111];
#define inf 1000000000
int lef[1111111],rig[1111111];

struct node{
	int p,x;
}a[2222222];int ndtot=0;

int cmp(const node&a,const node&b){
	if(a.p==b.p)return a.x>b.x;
	else return a.p<b.p;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int tes;
	scanf("%d",&tes);
	for (int tt=1;tt<=tes;tt++){
		printf("Case #%d: ",tt);
		scanf("%d%d",&n,&d);
		scanf("%d%d%d%d%d%d%d%d",&s[0],&as,&cs,&rs,&m,&am,&cm,&rm);
		for (int i=1;i<n;i++){
			s[i]=(1ll*s[i-1]*as+cs)%rs;
			m=(1ll*m*am+cm)%rm;
			pre[i]=m%i;
		}
		lef[0]=s[0]-d;
		rig[0]=s[0];
		for (int i=1;i<n;i++){
			lef[i]=s[i]-d;
			rig[i]=s[i];
			lef[i]=max(lef[i],lef[pre[i]]);
			rig[i]=min(rig[i],rig[pre[i]]);
		}
		ndtot=0;
		for (int i=0;i<n;i++)if(lef[i]<=rig[i]){
			a[++ndtot]=(node){lef[i],1};
			a[++ndtot]=(node){rig[i],-1};
		}
		sort(a+1,a+1+ndtot,cmp);
		int cur=0;
		int ma=0;
		for (int i=1;i<=ndtot;i++){
			cur+=a[i].x;
			ma=max(ma,cur);
		}
		printf("%d\n",ma);
	}
	return 0;
}





