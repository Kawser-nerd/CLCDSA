#include <stdio.h>

int main(void)
{
	int n,max,min;
	int count_1=0;
	int count_2=0;
	int count_3=0;
	int count_4=0;
	
	char c[200];
	
	scanf("%d\n%s",&n,c);
	
	for(int i=0;i<n;i++){
		if(c[i]=='1'){
			count_1++;
		}
		if(c[i]=='2'){
			count_2++;
		}
		if(c[i]=='3'){
			count_3++;
		}
		if(c[i]=='4'){
			count_4++;
		}
	}
	
	if(count_1>count_2&&count_1>count_3&&count_1>count_4){
		max=count_1;
	}else if(count_2>count_3&&count_2>count_4){
		max=count_2;
	}else if(count_3>count_4){
		max=count_3;
	}else{
		max=count_4;
	}
		
		if(count_1<count_2&&count_1<count_3&&count_1<count_4){
			min=count_1;
		}else if(count_2<count_3&&count_2<count_4){
			min=count_2;
		}else if(count_3<count_4){
			min=count_3;
		}else{
			min=count_4;
		}
		
		printf("%d %d\n",max,min);
		
		
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n%s",&n,c);
  ^