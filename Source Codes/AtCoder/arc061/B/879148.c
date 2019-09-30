#include<stdio.h>
#define M 100000
long long H,W,A[10],q;
int p[M];
struct{int a,b,n,q;}d[900001];

void f(int a,int b){
	int h,t,i;
	if(1<a&&a<H&&1<b&&b<W){
		i=p[h=(a/M+a+b/M+b)%M];
		if(i){
			for(;;){
				if(d[i].a==a&&d[i].b==b){
					break;
				}else if(d[i].q){
					i=d[i].q;
				}else{
					d[i=d[i].q=++q].a=a;
					d[i].b=b;
					break;
				}
			}
		}else{
			d[i=p[h]=++q].a=a;
			d[i].b=b;
		}
		--A[t=d[i].n++];
		++A[t+1];
	}
}
int main(){
	int a,b,i,j;
	scanf("%lld%lld%d",&H,&W,&i);
	A[0]=(H-2)*(W-2);
	for(;~scanf("%d%d",&a,&b);)
		for(i=-1;i<=1;++i)
			for(j=-1;j<=1;++j)
				f(a+i,b+j);
	for(i=0;i<=9;++i)printf("%lld\n",A[i]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:33:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%d",&H,&W,&i);
  ^