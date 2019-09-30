#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int u1[10001],u2[10001],u3[10001];
int sum[10001][10001];

int aa[5000], bb[5000], cc[5000];
int ind[10001];
int hai[100000];

int main(){
  int i,j,k,l,m,n,r,jj;
  int a,b,c;
  int size,count=0;
  int res,add;

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"rest input = %d\n",size);

    rep(i,10001) rep(j,10001) sum[i][j]=0; add=0;
    scanf("%d",&n);
    rep(i,n) scanf("%d%d%d",aa+i,bb+i,cc+i);

    rep(i,10001) u1[i]=u2[i]=0;
    rep(i,n) u1[aa[i]]=u2[bb[i]]=1;

    rep(i,10000) hai[i]=10001;
    rep(i,10001) ind[i]=0;
    if(u2[0]){ ind[0]=1; hai[1]=0; }
    REP(i,1,10001){ ind[i]=ind[i-1]; if(u2[i]) {ind[i]++; hai[ind[i]]=i; } }

    rep(r,n){
      a=aa[r], b=bb[r], c=cc[r];
      if(a==0 && b==0 && c==0) {add++; continue;}
      REP(i,a,10001) if(u1[i]) for(jj=ind[b];;jj++){
        j=hai[jj];
        if(10000 - i - j < c) break;
        sum[i][j]++;
      }
    }
    res=0;
    rep(i,10001) rep(j,10001) if(res < sum[i][j]) res=sum[i][j];
    printf("Case #%d: %d\n",++count,res+add);
  }

  return 0;
}
