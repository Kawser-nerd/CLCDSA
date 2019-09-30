#include <stdio.h>

int main(void)
{
	int H,W;
	int i,j,num=0;
	char a;

	scanf("%d %d",&H,&W);

	for(i=0;i<H;i++)
		for(j=0;j<W;j++){
			scanf(" %c",&a);
			if(a=='#'){
				num++;
			}
		}

	printf("%s\n",num==H+W-1 ? "Possible":"Impossible");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&H,&W);
  ^
./Main.c:13:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf(" %c",&a);
    ^