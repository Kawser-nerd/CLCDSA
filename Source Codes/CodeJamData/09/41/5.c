#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n;
  int in[1000],res;
  char tmp[1000];
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    res=0;
    scanf("%d",&n);
    rep(i,n){
      scanf("%s",tmp);
      for(k=n-1;k>=0;k--) if(tmp[k]=='1') break;
      in[i]=k;
    }
    rep(i,n){
      REP(j,i,n) if(in[j]<=i) break;
      while(j>i){
        res++;
        k=in[j], in[j]=in[j-1], in[j-1]=k;
        j--;
      }
    }
    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
