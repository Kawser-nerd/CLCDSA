#include <stdio.h>

int main(){
  int N,C;
  scanf("%d%d",&N,&C);
  int i,j,k,t,s;
  int D[C+1][C+1];
  int c[N+1][N+1];
  for(i=1;i<C+1;i++){
    for(j=1;j<C+1;j++){
      scanf("%d",&D[i][j]);
    }
  }
  for(i=1;i<N+1;i++){
    for(j=1;j<N+1;j++){
      scanf("%d",&c[i][j]);
    }
  }

  int an[3]={0,0,0};
  int amari[N*N][3];

  for(i=1;i<N+1;i++){
    for(j=1;j<N+1;j++){
      t=(i+j)%3;
      s=an[t];
      amari[s][t]=c[i][j];
      an[t]=an[t]+1;
    }
  }
  
  int amcost[C+1][3];
  for(i=0;i<3;i++){
    for(j=0;j<C+1;j++){
      amcost[j][i]=0;
    }
  }
  
  for(i=0;i<3;i++){
    for(j=1;j<=C;j++){
      for(k=0;k<an[i];k++){
	amcost[j][i]=amcost[j][i]+D[amari[k][i]][j];
      }
    }
  }
  
  long int cost=amcost[1][0]+amcost[2][1]+amcost[3][2];
  for(i=1;i<=C;i++){
    for(j=1;j<=C;j++){
      for(k=1;k<=C;k++){
	if(i!=j&&j!=k&&k!=i){
	  if(cost>amcost[i][0]+amcost[j][1]+amcost[k][2]){
	    cost=amcost[i][0]+amcost[j][1]+amcost[k][2];
	  }
	}
      }
    }
  }
  //printf("%d %d\n",amari[0][0],amari[1][0]);
  printf("%ld",cost);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&C);
   ^
./Main.c:11:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&D[i][j]);
       ^
./Main.c:16:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&c[i][j]);
       ^