#include<cstring>
#include<cstdlib>
#include<cstdio>
#include<algorithm>
#include<ctime>
#include<cmath>
using namespace std;
int T,n,m,K,f[41][1100][1100],ans,i,j,k,p,tim;
void renew(int &x,int y){
	x=min(x,y);
}
int main(){
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
	for(scanf("%d",&T);T--;){
		scanf("%d%d%d",&n,&m,&K);
		if(n>m)swap(n,m);
		memset(f,3,sizeof(f));
		for(i=1;i<=m;++i)f[1][i][i]=i;
		ans=K;
		for(i=1;i<n;++i)
			for(j=1;j<=m;++j)
				for(k=1;k<=n*m;++k){
					for(p=-3;p<=3;++p)
						if(j+p<=m && j+p>=1){
							int z=max(abs(p),2);
							renew(f[i+1][j+p][k+j+p],f[i][j][k]+z-(j+p==1));
						}
				}
		for(i=1;i<=n;++i)
			for(j=1;j<=m;++j)
				for(k=1;k<=n*m;++k)ans=min(ans,f[i][j][k]+(k<K?(K-k):0)+max(0,j-2));
		printf("Case #%d: %d\n",++tim,ans);
	}
}
