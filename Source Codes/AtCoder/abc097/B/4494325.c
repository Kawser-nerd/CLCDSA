#include <stdio.h>
#include <math.h>

int main(void)
{
	int x;
	int max=-1;
	int result=0;
	
	scanf("%d",&x);
	
	if(x==1){
		max=1;
	}else{
		int i=2;
		while(i<=x){
			int j=2;
			while(j<=x){
				result=pow(i,j);
				if(result<=x&&result>max){
					max=result;
				}
				j++;
			}
			i++;
		}
	}
	
	printf("%d\n",max);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&x);
  ^