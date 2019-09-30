#include<stdio.h>
#define g getchar()
inline void r(int *x){
	*x=0;
	char c=g;
	while(c<'0')c=g;
	while(c>='0'){*x=*x*10+c-48;c=g;}
}
static int x[100000];
int main(){
	int n,a,b;r(&n);r(&a);r(&b);long d=0;r(&x[0]);
	for(int i=1;i<n;i++){
		r(&x[i]);
		d+=(long)a*(x[i]-x[i-1])>b?b:(long)a*(x[i]-x[i-1]);
	}
	printf("%ld\n",d);
}