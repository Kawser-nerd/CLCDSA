#include <stdio.h>

int  main(void)
{
	int x,y,z,ans;
	
	scanf("%d%d%d",&x,&y,&z);
	
	int i=0;
	
	for(int i=0;y*i+z*(i+1)<=x;i++){
		
		ans=i;
		
	}
	
	printf("%d\n",ans);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&x,&y,&z);
  ^