#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)


int min[1200000], max[1200000];

int main(){
  int i,j,k,l,m,n;
  int size,count=0;
  int A1, A2, B1, B2;
  long long res;
  double f = (sqrt(5)+1)/2;
  
  rep(i,1000001) min[i]=max[i]=0;
  for(i=1;;i++){
    m = (int)(i*f); if(m>1000000) break;
    n = m+i;
    max[m]=n;
  }
  REP(i,1,1000001) if(!max[i]) max[i]=max[i-1]+1;

  k=1;
  for(i=1;;i++){
    if(max[i] > 1000001) break;
    while(k<=max[i]) min[k]=i, k++;
  }

  scanf("%d",&size);
  while(size--){
    scanf("%d%d%d%d",&A1,&A2,&B1,&B2); A1--; B1--; A2--; B2--;
    res=0;

    REP(k,A1,A2+1){
      i = B1; j = B2;
      if(i < min[k]) i = min[k];
      if(j > max[k]) j = max[k];
      m = j-i+1; if(m<0) m=0;
      res += (B2-B1+1) - m;
    }

    printf("Case #%d: %lld\n",++count,res);
  }
  
  return 0;
}
