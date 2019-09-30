#include<stdio.h>
int main(void)
{
	float a,b,c,d;
	scanf("%d %d %d %d",&a,&b,&c,&d);
	if(b/a==d/c){
		printf("DRAW\n");
	}
	else if(b/a<=d/c){
		printf("AOKI\n");
	}
	else{
		printf("TAKAHASHI\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 2 has type ‘float *’ [-Wformat=]
  scanf("%d %d %d %d",&a,&b,&c,&d);
        ^
./Main.c:5:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 3 has type ‘float *’ [-Wformat=]
./Main.c:5:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 4 has type ‘float *’ [-Wformat=]
./Main.c:5:8: warning: format ‘%d’ expects argument of type ‘int *’, but argument 5 has type ‘float *’ [-Wformat=]
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&a,&b,&c,&d);
  ^