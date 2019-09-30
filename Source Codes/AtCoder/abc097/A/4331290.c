#include <stdio.h>

int main(void)
{
	int a,b,c,d,max,min,center;
	
	max=0;
	min=101;
	center=0;
	
	scanf("%d %d %d %d",&a,&b,&c,&d);
	
	
	int array[3]={a,b,c};
	
	if((a>c&&a-c<=d)||(a<c&&c-a<=d)){
		printf("Yes\n");
	}else{
		for(int i=0;i<3;i++){
		if(array[i]>max){
			max=array[i];
		}
		if(array[i]<min){
			min=array[i];
			}
		}
	
		for(int i=0;i<3;i++){
			if((array[i]!=max&&array[i]!=min)||(a==b&&a==c)){
				center=array[i];
			}
		}
		if(max-center<=d&&center-min<=d){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d %d",&a,&b,&c,&d);
  ^