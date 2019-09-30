#include <stdio.h>
int z[9999],r[9999];
int f(int a,int b){
	printf("? %d %d\n",a,b);
	fflush(stdout);
	char c[2];
	scanf("%s",c);
	return *c=='Y';
}
int main(){
	int a,b,c=0,h,i=0;
	scanf("%d%d",&a,&b);
	if(a<=b){puts("Impossible");return 0;}
	for(a+=b;i<a;i++)if(!c||f(i,z[c-1]))z[c++]=i;else c--;
	h=z[0];
	for(i=0;i<a;i++)r[i]=h==i||f(h,i);
	printf("! ");
	for(i=0;i<a;i++)printf("%d",r[i]);
	puts("");
} ./Main.c: In function ‘f’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",c);
  ^
./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^