#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define EPS 1e-10
void doubleIntSort(double d[],int m[],int s){int i,j,r;double k1,k2,t;if(s<=1)return;k1=(d[0]+d[s-1])/2.0;k2=k1+EPS;k1-=EPS;i=-1;j=s;for(;;){while(d[++i]<k1);while(d[--j]>k2);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;r=m[i];m[i]=m[j];m[j]=r;}doubleIntSort(d,m,i);doubleIntSort(d+j+1,m+j+1,s-j-1);}

int main(){
  int i,j,k,l,m,n;
  double walk, run, run_time;
  double len;
  double st[1200], ed[1200], ksk[1200];

  double go_len[1200], go_speed[1200];
  double rest, need;

  double val[1200]; int ind[1200];

  double res;

  int size, count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%lf%lf%lf",&len,&walk,&run);
    scanf("%lf%d",&run_time,&n);

    rep(i,n) scanf("%lf%lf%lf",st+i,ed+i,ksk+i);

    rest = len;
    rep(i,n) rest -= ed[i] - st[i];

    rep(i,n){
      go_len[i] = ed[i] - st[i];
      go_speed[i] = ksk[i] + walk;
    }
    go_len[n] = rest;
    go_speed[n] = walk;
    n++;

    rep(i,n) val[i] = go_speed[i], ind[i] = i;
    doubleIntSort(val,ind,n);

    res = 0;
    rep(i,n){
      k = ind[i];

      rest = go_len[k];
      need = rest / (go_speed[k] + run-walk);
      if(need > run_time) need = run_time;

      res += need;
      rest -= (go_speed[k] + run-walk) * need;
      run_time -= need;

      need = rest / go_speed[k];
      res += need;
    }

    printf("Case #%d: %.10lf\n",++count,res);
  }


  return 0;
}
