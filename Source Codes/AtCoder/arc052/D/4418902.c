#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*k+(j)%k)

int digitSum(int64 n){
  int sum=0;
  while(n>0){
    sum+=n%10;
    n/=10;
  }
  return sum;
}

void run(void){
  int64 k,m;
  scanf("%lld%lld",&k,&m);
  if(k>10000){
    int cnt=0;
    for(int sum=1;sum<=90;sum++){
      for(int64 d=sum;d<=m;d+=k){
	if(digitSum(d)==sum){
	  cnt++;
	}
      }
    }
    printf("%d\n",cnt);
  } else {
    int digit[11];
    int len=0;
    int64 t=m;
    while(t>0){
      digit[len++]=t%10;
      t/=10;
    }
    int64 *now=(int64 *)calloc(k*91,sizeof(int64));
    int64 *next=(int64 *)calloc(k*91,sizeof(int64));
    int supMod=0;
    int supSum=0;
    int i;
    for(i=len-1;i>=0;i--){
      memset(next,0,sizeof(int64)*k*91);
      int j,l;
      for(j=0;j<91;j++){
	for(l=0;l<k;l++){
	  for(int d=0;d<10;d++){
	    if(j+d>=91) continue;
	    next[POS(j+d,10*l+d)]+=now[POS(j,l)];
	  }
	}
      }
      for(j=0;j<digit[i];j++){
	next[POS(supSum+j,supMod*10+j)]++;
      }
      supMod=(10*supMod+digit[i])%k;
      supSum+=digit[i];
      int64 *swap=now;
      now=next;
      next=swap;
    }
    int64 ans=(supMod==supSum%k?1:0);
    for(i=1;i<91;i++) ans+=now[POS(i,i)];
    printf("%lld\n",ans);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld",&k,&m);
   ^