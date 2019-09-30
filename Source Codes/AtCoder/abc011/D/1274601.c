#include<stdio.h>
#include<stdlib.h>
double f(int a,int b,int c,int d,int n){
	double s=1;
	int i;
	for(i=1;i<=n;i++){
		s*=i;
		if     (i<=a    )s/=i;
		else if(i<=a+b  )s/=i-a;
		else if(i<=a+b+c)s/=i-a-b;
		else             s/=i-a-b-c;
		s/=4;
	}
	return s;
}
int main(){
	int n,m,a,b,i,j;
	double s=0,d;
	scanf("%d %d %d %d",&n,&m,&a,&b);
	if(a%m+b%m||(n-a/m+b/m)%2){
		printf("0\n");
		return 0;
	}
	a=abs(a/m);
	b=abs(b/m);
	m=n-a-b;//printf("%d %d %d\n",a,b,m);
	for(i=0;i<=m;i+=2){
		s+=f(i/2,i/2+a,(m-i)/2,(m-i)/2+b,n);
	}
	printf("%.14lf\n",s);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:19:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&n,&m,&a,&b);
  ^