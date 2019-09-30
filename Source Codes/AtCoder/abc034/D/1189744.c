#include<stdio.h>

int sortfnc(const void *a,const void *b){
    if(*(double*)a == *(double*)b){return 0;}
    if(*(double*)a > *(double*)b){return -1;}
    return 1;
}

int main(void){
	int i,k,n,c,t;
	double w[1024],p[1024],mem[1024],sum;
	double s,f,jud;
	scanf("%d%d",&k,&n);
	if(k > n){t = k;k = n;n = t;}
	for(i = 1;i <= n;i++){scanf("%lf%lf",&w[i],&p[i]);}
	s = 0.00f;f = 100.00f;
	for(c = 1;c <= 1000;c++){
		jud = (s+f)/2;
		for(i = 1;i <= n;i++){mem[i-1] = w[i]*p[i]-w[i]*jud;}
		qsort(mem,n,sizeof(double),sortfnc);
		sum = 0.00f;
		for(i = 0;i < k;i++){sum+=mem[i];}
		if(sum >= 0){s = jud;}else{f = jud;}
		if(s >= f){break;}
	}
	printf("%.12lf\n",(s+f)/2);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: implicit declaration of function ‘qsort’ [-Wimplicit-function-declaration]
   qsort(mem,n,sizeof(double),sortfnc);
   ^
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&k,&n);
  ^
./Main.c:15:24: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i = 1;i <= n;i++){scanf("%lf%lf",&w[i],&p[i]);}
                        ^