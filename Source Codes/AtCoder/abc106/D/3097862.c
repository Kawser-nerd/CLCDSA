#include <stdio.h>

void prints(int n,int S[n+1][n+1] ){
  int i,j;
  for(i=1;i<n+1;i++){
    for(j=1;j<n+1;j++){
      printf("%d", S[j][i]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(){
  int i,j,k,l,s,N,M,Q;
  scanf("%d %d %d", &N,&M,&Q);
  int L[M+1],R[M+1],p[Q],q[Q];
  for(i=1;i<M+1;i++){
    scanf("%d %d",&L[i],&R[i]);
  }
  for(i=0;i<Q;i++){
    scanf("%d %d", &p[i],&q[i]);
  }

  int S[N+1][N+1],Sum[N+1][N+1];
  for(i=0;i<N+1;i++){
    for(j=0;j<N+1;j++){
      S[i][j]=0;
      Sum[i][j]=0;
    }
  }

  for(i=1;i<M+1;i++){
    l=R[i];
    k=L[i];
    S[k][l]=S[k][l]+1;
  }
  //prints(N,S);
  
  for(i=1;i<N+1;i++){
    s=0;
    for(j=1;j<N+1;j++){
      Sum[i][j]=s+S[i][j];
      s=s+S[i][j];
    }
  }
  //prints(N,Sum);
  int ANS;
  for(i=0;i<Q;i++){
    ANS=0;
    for(k=p[i];k<N+1;k++){
      l=q[i];
      ANS=ANS+Sum[k][l];
    }
    printf("%d\n", ANS);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &N,&M,&Q);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&L[i],&R[i]);
     ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &p[i],&q[i]);
     ^