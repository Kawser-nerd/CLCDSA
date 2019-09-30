#include <stdio.h>

int main(void)
{
	int x,y;
	int a=0;
	int c=0;
	
	scanf("%d %d",&x,&y);
	
	int b[]={4,6,9,11};
	
	for(int i=0;i<4;i++){
		if(x==b[i]){
			a++;
			break;
		}
	}
	for(int i=0;i<4;i++){
		if(y==b[i]){
			c++;
			break;
		}
	}
	
	if(x==2||y==2){
		printf("No\n");
	}else if((a!=0&&c==0)||(a==0&&c!=0)){
		printf("No\n");
	}else{
		printf("Yes\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&x,&y);
  ^