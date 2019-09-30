#include <stdio.h>
int PG[4];
int main(){
  int Ti,T,N,G,P;
  scanf("%d",&T);
  for(Ti=1;Ti<=T;++Ti){
    scanf("%d %d",&N,&P);
    for(int i=0;i<P;++i)PG[i]=0;
    for(int i=0;i<N;++i)scanf("%d",&G),++PG[(P-G%P)%P];
    int r=PG[0];
    if(P==2)r+=(PG[1]+1)/2;
    else if(P==3){
      int a,b;
      if(PG[2]>PG[1])a=PG[1],b=PG[2];
      else a=PG[2],b=PG[1];
      r+=a+(b-a+3-1)/3;
    }
    else if(P==4){
      int a,b;
      if(PG[1]>PG[3])a=PG[3],b=PG[1];
      else a=PG[1],b=PG[3];
      r+=a;
      int c=(b-a)/2;
      int mi=0;
      int mm=(PG[2]+1)/2+(b-a+3)/4;
      for(int i=1;i<=c&&i<=PG[2];++i){
        if((PG[2]+1-i)/2+(b-a+3-i*2)/4 > mm)mm=(PG[2]+1-i)/2+(b-a+3-i*2)/4,mi=i;
      }
      r+=mm;
    }
    printf("Case #%d: %d\n",Ti,r);
  }
  return 0;
}
