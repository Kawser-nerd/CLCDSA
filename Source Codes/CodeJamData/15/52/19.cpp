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


int n,k;
int a[1111];
int dif[1111];
int ma[1111],mi[1111];
int cediv(int x,int y){
	int r=x%y;
	if(r>0)r-=y;
	return (x-r)/y;
}
int fldiv(int x,int y){
	int r=x%y;
	if(r<0)r+=y;
	return (x-r)/y;
}
int main()
{
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
	int tes;
	scanf("%d",&tes);
	for (int tt=1;tt<=tes;tt++){
		printf("Case #%d: ",tt);
		scanf("%d%d",&n,&k);
		for (int i=k;i<=n;i++)scanf("%d",&a[i]);
		for (int i=1;i<=k;i++)dif[i]=0;
		for (int i=k+1;i<=n;i++)dif[i]=a[i]-a[i-1]+dif[i-k];
		for (int i=1;i<=k;i++)ma[i]=mi[i]=0;
		for (int i=k+1;i<=n;i++)ma[(i-1)%k+1]=max(ma[(i-1)%k+1],dif[i]);
		for (int i=k+1;i<=n;i++)mi[(i-1)%k+1]=min(mi[(i-1)%k+1],dif[i]);
		int su=a[k];
		int maxlen=0;
		for (int i=1;i<=k;i++)maxlen=max(maxlen,ma[i]-mi[i]);
		int sul=0,sur=0;
		for (int i=1;i<=k;i++){
			int le=ma[i]-mi[i];
			int sl=maxlen-le;
			sul+=-mi[i];
			sur+=-mi[i]+sl;
		}
		sul-=su,sur-=su;
		int a=cediv(sul,k),b=fldiv(sur,k);
		if(a<=b){
			printf("%d\n",maxlen);
		}else printf("%d\n",maxlen+1);
	}
	return 0;
}





