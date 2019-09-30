#include<stdio.h>
#include<stdlib.h>

int main(void){
  struct{
    int A,B;
  }data[200000];

  unsigned *board[2][4097]; 
  unsigned **calc,*center[4097],ans=0;
  int i,j,k,N;
  const unsigned mod=(unsigned)1E9+7;

  for(i=0;i<2;i++){
    for(j=0;j<4097;j++){
      board[i][j]=(unsigned *)calloc(4097,sizeof(unsigned));
      if(i==1) center[j]=board[1][j]+2049;
    }
  }
  calc=&center[2049];

  scanf("%d",&N);
  for(i=0;i<N;i++) scanf("%d%d",&data[i].A,&data[i].B);

  for(i=0;i<4097;i++) for(j=0;j<4097;j++) board[0][i][j]=(i==0 || j==0)?1:(board[0][i][j-1]+board[0][i-1][j])%mod;
 
 for(i=0;i<N;i++) calc[-data[i].A][-data[i].B]++;
 for(i=0;i<4097;i++){
   for(j=0;j<4097;j++){
     if(i!=0) board[1][i][j]+=board[1][i-1][j];
     if(j!=0) board[1][i][j]+=board[1][i][j-1];
     board[1][i][j]%=mod;
   }
 }

 for(i=0;i<N;i++){
   ans+=calc[data[i].A][data[i].B];
   if(ans>=board[0][2*data[i].A][2*data[i].B]) ans-=board[0][2*data[i].A][2*data[i].B];
   else ans+=mod-board[0][2*data[i].A][2*data[i].B];
   ans%=mod;
 }
 
 if(ans%2) ans+=mod;
 ans/=2;
 printf("%u\n",ans%mod);

 for(i=0;i<2;i++) for(j=0;j<4097;j++) free(board[i][j]);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:23:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<N;i++) scanf("%d%d",&data[i].A,&data[i].B);
                    ^