#include<stdio.h>
int main()
{
	int a[17],b=0,i;
	for(i=0;i!=16;i++)
		scanf("%d",&a[i]);
	for(i=0;i!=15;i++){
		if(i==3 || i==7 || i==11)
			i++;
		if(a[i]==a[i+1])
			b=1;
	}
		
	for(i=0;i!=12;i++)
		if(a[i]==a[i+4])
			b=1;
	if(b==1)
		printf("CONTINUE\n");
	  else printf("GAMEOVER\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^