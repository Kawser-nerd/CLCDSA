#include<cstdio>
#define inf 1000000
#define L 20000

using namespace std;

int T,m,V,i,tem,I;
int g[L],v[L],c[L],opt[L][2];

main(){
	scanf("%d",&T);
	while (T--){
		scanf("%d%d",&m,&V);
		for (i=1;i<=(m-1)/2;++i) scanf("%d%d",&g[i],&c[i]);
		for (i=(m-1)/2+1;i<=m;++i) scanf("%d",&v[i]);
		for (i=m;i>0;--i)
			if (i>(m-1)/2){
				opt[i][v[i]]=0;
				opt[i][1-v[i]]=inf;
			}
			else if (g[i]==1){
				opt[i][0]=opt[2*i][0]+opt[2*i+1][1]<?opt[2*i][0]+opt[2*i+1][0]<?opt[2*i][1]+opt[2*i+1][0];
				opt[i][1]=opt[2*i][1]+opt[2*i+1][1];
				if (c[i]==1){
					opt[i][1]<?=(opt[2*i][0]+opt[2*i+1][1]<?opt[2*i][1]+opt[2*i+1][1]<?opt[2*i][1]+opt[2*i+1][0])+1;
					opt[i][0]<?=(opt[2*i][0]+opt[2*i+1][0])+1;
				}
			}
			else if (g[i]==0){
				opt[i][1]=opt[2*i][0]+opt[2*i+1][1]<?opt[2*i][1]+opt[2*i+1][1]<?opt[2*i][1]+opt[2*i+1][0];
				opt[i][0]=opt[2*i][0]+opt[2*i+1][0];
				if (c[i]==1){
					opt[i][0]<?=(opt[2*i][0]+opt[2*i+1][1]<?opt[2*i][0]+opt[2*i+1][0]<?opt[2*i][1]+opt[2*i+1][0])+1;
					opt[i][1]<?=(opt[2*i][1]+opt[2*i+1][1])+1;
				}
			}
		printf("Case #%d: ",++I);
		tem=opt[1][V];
		if (tem>=inf) printf("IMPOSSIBLE\n");
		else printf("%d\n",tem);
	}
}
