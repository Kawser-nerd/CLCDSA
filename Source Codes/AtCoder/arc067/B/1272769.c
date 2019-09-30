#include<stdio.h>
#define g getchar()
inline void r(int *x){
	char c=g;
	while(c<'0')c=g;
	while(c>='0'){*x=*x*10+c-48;c=g;}
}
int x[100000];
int n,a,b;
long d;
int main(){
	r(&n);r(&a);r(&b);r(&x[0]);
	for(int i=1;i<n;i++){
		r(&x[i]);
		long e=(long)a*(x[i]-x[i-1]);
		d+=e>b?b:e;
	}
	printf("%ld\n",d);
}