#include<stdio.h>

long long llmax(long long a,long long b){if(a>b){return a;}return b;}
long long llmin(long long a,long long b){if(a<b){return a;}return b;}

int main(void){
	long long int q,i,o,t,j,l,s,z,r1=0,r2=0;
	scanf("%lld%lld%lld%lld%lld%lld%lld",&i,&o,&t,&j,&l,&s,&z);
	r1+=(o+(i/2)*2+(j/2)*2+(l/2)*2);
	if(i%2==1 && j%2==1 && l%2==1){r1+=3;}
	if(i!=0 && j!=0 && l!=0){i--;j--;l--;r2+=3;}
	r2+=(o+(i/2)*2+(j/2)*2+(l/2)*2);
	printf("%lld\n",llmax(r1,r2));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld%lld%lld%lld%lld",&i,&o,&t,&j,&l,&s,&z);
  ^