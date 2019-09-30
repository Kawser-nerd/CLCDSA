#include<stdio.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define EPS 1e-8

double dp[70000], next[70000];

int main(){
  int i,j,k,l,m,n,node,round;
  int size,count=0;
  int s;
  int target=1000000;
  double p,res,per,sum,opt,tmp1,tmp2,tmp;
  int a,b,c1,c2;

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"%d\n",size);
    scanf("%d%lf%d",&n,&p,&s);
    node = (1<<n) + 1;
    rep(i,node) dp[i]=0; dp[node-1]=1;
    rep(round,n){
      rep(i,node) next[i]=0;

      rep(i,node){
        a=0; b=i; if(b > node-1-i) b = node-1-i;
        while(a >= b+10){
          c1 = (a+a+b)/3; c2 = (a+b+b)/3;
          tmp1 = p*dp[i+c1] + (1-p)*dp[i-c1];
          tmp2 = p*dp[i+c2] + (1-p)*dp[i-c2];
          if(tmp1 > tmp2) b=c2; else a=c1;
        }
        opt=0;
        REP(k,a,b+1){
          tmp = p*dp[i+k] + (1-p)*dp[i-k];
          if(opt < tmp) opt = tmp;
        }
        next[i]=opt;
      }
      
      rep(i,node) dp[i]=next[i];
    }
    per = (double) target / (node - 1); sum = 0;
    rep(i,node-1){
      sum += per;
      if( (double) s < sum - EPS) break;
    }
    res = dp[i];
    printf("Case #%d: %0.8lf\n",++count,res);
  }

  return 0;
}
