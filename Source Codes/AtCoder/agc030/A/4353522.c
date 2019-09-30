#include <stdio.h>

int main(void)
{
	int a,b,c;
	int count_1=0;
	int count_2=0;
	
	scanf("%d %d %d",&a,&b,&c);
	if(b>=c){
		printf("%d\n",b+c);
	}else{
		while(b!=0&&c!=0){
			b--;
			c--;
			count_1++;
		}
		
		if(b!=0){
			printf("%d\n",count_1*2);
		}else{
			while(a!=0&&c!=0){
				a--;
				c--;
				count_2++;
			}
			
			if(a>=c){
				printf("%d\n",count_1*2+count_2);
			}else{
				printf("%d\n",count_1*2+count_2+1);
			}
		}
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^