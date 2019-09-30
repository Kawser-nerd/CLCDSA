#include <stdio.h>

int main(void)
{
	int a,b,c,count_5,count_7;
	scanf("%d %d %d",&a,&b,&c);
	int s[]={a,b,c};
	
	for(int i=0;i<3;i++){
		if(s[i]==5){
			count_5++;
		}
		if(s[i]==7){
			count_7++;
		}
	}
	
	if(count_5==2&&count_7==1){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
		
	return 0;
		
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^