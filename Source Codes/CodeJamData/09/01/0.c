#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

char dic[5000][17];
int n,len;

int main(){
  int i,j,k,l,m,n,st;
  char in[10000];
  int fg[5000],chk[128];
  int size,count=0,res;

  scanf("%d%d%d",&len,&n,&size);
  rep(i,n) scanf("%s",dic[i]);

  while(size--){
    scanf("%s",in); st=0;

    rep(k,n) fg[k]=1;
    rep(i,len){
      rep(j,128) chk[j]=0;
      if(in[st]!='('){ chk[in[st]]=1; st++; }
      else {
        st++;
        while(in[st]!=')'){ chk[in[st]]=1; st++;}
        st++;
      }
      rep(k,n) if( chk[dic[k][i]]==0 ) fg[k]=0;
    }
    res=0; rep(k,n) res+=fg[k];
    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
