#include<stdio.h>
#include<stdlib.h>

#define MAX(x,y) (((x)>(y))?(x):(y))

const unsigned long long modnum=1E9+7;
unsigned long long invdiv(unsigned long long p);

int main(void){
  unsigned long long H,W,A,B;
  unsigned long long *up,*down;
  unsigned long long maxnum;
  unsigned long long ans,tmp;
  int i,j,k;

  scanf("%llu%llu%llu%llu",&H,&W,&A,&B);
  maxnum=H+W;
  up=(unsigned long long *)calloc(maxnum+1,sizeof(unsigned long long));
  down=(unsigned long long *)calloc(maxnum+1,sizeof(unsigned long long));
  up[0]=up[1]=down[0]=down[1]=1;

  for(i=2;i<maxnum;i++){
    up[i]=(up[i-1]*i)%modnum;
    down[i]=(down[i-1]*invdiv(i))%modnum;
  }

  ans=0;
  for(i=0;i<H-A;i++){
    ans+=up[i+B-1]*down[i]%modnum*up[W-1-B+H-1-i]%modnum*down[H-1-i]%modnum;
    ans%=modnum;
  }
  ans*=down[B-1];
  ans%=modnum;
  ans*=down[W-1-B];
  ans%=modnum;
  printf("%llu\n",ans);
  return 0;
}

unsigned long long invdiv(unsigned long long p) {
	unsigned long long r[3], q;
	unsigned long long x[3];
	div_t clc;

	r[0] = p;
	r[1] = modnum;

	x[0] = 1;
	x[1] = 0;

	do {
		clc = div(r[0], r[1]);
		q = clc.quot;
		r[2] = clc.rem;
		while(x[0] < q * x[1]) x[0] += modnum;
		x[2] = (x[0] - q * x[1]) % modnum;

		r[0] = r[1];
		r[1] = r[2];

		x[0] = x[1];
		x[1] = x[2];
	} while(r[2] > 1);
	return x[2];
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%llu%llu%llu%llu",&H,&W,&A,&B);
   ^