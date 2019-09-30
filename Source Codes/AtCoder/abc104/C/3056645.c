#include <stdio.h>
#include <math.h>

int main(){

  int D,G,i,j,P,C;
  scanf("%d" "%d", &D, &G);
  int p[D+1],c[D+1],psum[D+1];
  int N=pow(2,D);
  int A[N][D+1];
  int point[N],precost[N],cost[N];

  for(i=1;i<=D;i++){scanf("%d" "%d", &p[i],&c[i]);}
  
  for(i=1;i<=D;i++){psum[i]=100*i*p[i]+c[i];}

  int MAX=0;
  for(i=1;i<=D;i++){MAX=MAX+p[i];}
  
  for(j=0;j<N;j++){
    A[j][0]=j;point[j]=0;precost[j]=0;cost[j]=MAX;
    for(i=1;i<=D;i++){
      A[j][i]=A[j][0]%2;
      A[j][0]=(int)A[j][0]/2;
    }
  }

  for(j=0;j<N;j++){
    for(i=1;i<=D;i++){
      precost[j]=precost[j]+p[i]*A[j][i];
      point[j]=point[j]+psum[i]*A[j][i];
    }
  }

  for(j=0;j<N;j++){
    if(point[j]>=G){cost[j]=precost[j];}

    if(point[j]<G){
      for(i=1;i<=D;i++){
	P=point[j];C=precost[j];
	if(A[j][i]==0){
	  if(P+100*i*(p[i]-1)>=G){
	    while(P<G){P=P+100*i;C++;}
	    if(cost[j]>C){cost[j]=C;}
	  }
	}
      }
    }
  }

  int ANS=MAX;
  for(j=0;j<N;j++){
    if(ANS>cost[j]){ANS=cost[j];}
  }
  printf("%d",ANS);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d" "%d", &D, &G);
   ^
./Main.c:13:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=D;i++){scanf("%d" "%d", &p[i],&c[i]);}
                     ^