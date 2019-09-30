#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cmath>
using namespace std;
int T,i,tim,ans;
long long x,y;
int main(){
	freopen("A.in","r",stdin);
	freopen("A.out","w",stdout);
	for(scanf("%d",&T);T--;){
		tim++;
		scanf("%I64d/%I64d",&x,&y);
		long long g=__gcd(x,y);
		x/=g; y/=g;
		ans=1<<30;
		for(i=0;i<=1000000;++i){
			if(x==0)break;
			if(x>=y)x-=y,ans=min(ans,i);
			x*=2;
		}
		if(i>1000000)printf("Case #%d: impossible\n",tim);
		else printf("Case #%d: %d\n",tim,ans);
	}
}
