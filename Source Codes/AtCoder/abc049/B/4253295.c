#include<stdio.h>
#include<string.h>

int main(){
	int H,W;
	char a[101][101];
	scanf("%d%d",&H,&W);
	getchar();
	for(int i=0;i<H;i++){
		scanf("%s",&a[i]);
		getchar();
	}
	for(int i=0;i<H;i++){
		printf("%s\n",a[i]);
		printf("%s\n",a[i]);
	}
} ./Main.c: In function ‘main’:
./Main.c:10:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[101]’ [-Wformat=]
   scanf("%s",&a[i]);
         ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&H,&W);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&a[i]);
   ^