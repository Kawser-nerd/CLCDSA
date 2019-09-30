#include <stdio.h>

int main(void)
{
	int n,count_1,count_2,count_3,count_4;;
	count_1=count_2=count_3=count_4=0;
	int max=-1;
	int min=200;
	
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
	
	if(count_1>max){
		max=count_1;
	}
	if(count_2>max){
		max=count_2;
	}
	if(count_3>max){
		max=count_3;
	}
	if(count_4>max){
			max=count_4;
	}
		
	if(count_1<min){
			min=count_1;
	}
	if(count_2<min){
			min=count_2;
	}
	if(count_3<min){
			min=count_3;
	}
	if(count_4<min){
			min=count_4;
	}
		
		printf("%d %d\n",max,min);
		
		
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n%s",&n,c);
  ^