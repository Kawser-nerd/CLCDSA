#include<cstdio>
#include<algorithm>
#include<cstring>
#define L 1000
using namespace std;

int T,n,k,i,j;
int lj[L][L],lnk[L],p[L][L];
bool bt[L];

bool dfs(int a){
	if (bt[a]) return false;
	bt[a]=1;
	for (int i=0;i<n;++i)
		if (lj[a][i] && (lnk[i]==-1 || dfs(lnk[i]))){
			lnk[i]=a;
			return true;
		}
	return false;
}

int l,ans,I;

int main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&n,&k);
		for (i=0;i<n;++i)
			for (j=0;j<k;++j)
				scanf("%d",&p[i][j]);
		for (i=0;i<n;++i)
			for (j=0;j<n;++j){
				lj[i][j]=1;
				for (l=0;l<k;++l)
					if (p[i][l]<=p[j][l]) {lj[i][j]=0;break;}
			}
		memset(lnk,-1,sizeof lnk);
		ans=n;
		for (i=0;i<n;++i){
			memset(bt,0,sizeof bt);
			if (dfs(i)) --ans;
		}
		printf("Case #%d: %d\n",++I,ans);
	}
}
