#include<cstdio>
#include<cstring>
#include<algorithm>
#define L 20000

using namespace std;

int d[L],l[L],now[L];

void solve(){
	int n;
	scanf("%d",&n);
	for (int i=0;i<n;++i){
		scanf("%d%d",&d[i],&l[i]);
	}
	scanf("%d",&d[n]);
	l[n]=0;
	memset(now,-1,sizeof now);
	now[0]=d[0];
	for (int i=0;i<n;++i)
		if (now[i]!=-1){
			for (int j=i+1;j<=n;++j)
				if (d[j]-d[i]<=now[i]){
					now[j]=max(now[j],min(d[j]-d[i],l[j]));
				}
				else break;
		}
	puts(now[n]>=0?"YES":"NO");
}

int T,I=0;

int main(){
	scanf("%d",&T);
	while (T--){
		printf("Case #%d: ",++I);
		solve();
	}
}
