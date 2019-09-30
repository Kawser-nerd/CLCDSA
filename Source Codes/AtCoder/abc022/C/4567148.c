#include<stdio.h>

#define INF 200000000000

int main(){
	int n,m,i,j,k,u[3];
	long long edge[320][320],e[321]={0},c=0,ans=INF;
	scanf("%d%d",&n,&m);
  for(i=0;i<=n;i++){
		for(j=0;j<=n;j++){
			edge[i][j]=INF;
    	}
	}
	for(i=0;i<m;i++){
		scanf("%d%d%d",&u[0],&u[1],&u[2]);
      	if(u[0]==1)e[c++]=u[1];
		edge[u[0]][u[1]]=u[2];
		edge[u[1]][u[0]]=u[2];
	}
  for(k=2;k<=n;k++){
  	for(i=2;i<=n;i++){
      for(j=2;j<=n;j++){
          if(edge[i][j]>edge[i][k]+edge[k][j])edge[i][j]=edge[i][k]+edge[k][j];
        }
      }
    }
	for(i=0;i<=c;i++){
		for(j=i+1;j<=c;j++){
          long long tmp=edge[e[i]][e[j]]+edge[1][e[i]]+edge[e[j]][1];
		  if(ans>tmp)ans=tmp;
		}
	}
  	/*for(i=1;i<=n;i++){
      for(j=1;j<=n;j++){
	      printf("%lld,",kei[i][j]);
      }puts("");
    }*/
	if(ans<INF)printf("%lld\n",ans);
  	else puts("-1");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&m);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&u[0],&u[1],&u[2]);
   ^