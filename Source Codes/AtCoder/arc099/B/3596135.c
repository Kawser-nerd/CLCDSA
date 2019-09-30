#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{
	//?????
	int n;
	int k,s;
	long long int temp;
	long long int temp1;
	long long int temp2;
	int i,j;
	double sunuke1,sunuke2;
	int count;
	
	//????????
	scanf("%d",&n);
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	count=0;
	k=1;
	s=1;
	while(count<9){
		count++;
		printf("%d\n",count);
		if(count==n) return 0;
	}
	while(1){
		if(k%10!=0){
			k=k+1;
			temp=k;
			for(i=0;i<s;i++){
				temp=temp*10;
			}
			printf("%lld\n",temp-1);
		}else{
			temp=k+1;
			for(i=0;i<s;i++){
				temp=temp*10;
			}
			temp=temp-1;
			temp1=temp;
			j=0;
			while(temp>0){
				j=j+temp%10;
				temp=temp/10;
			}
			sunuke1=(double)temp1/j;
			
			temp=k/10+1;
			for(i=0;i<s+1;i++){
				temp=temp*10;
			}
			temp=temp-1;
			temp2=temp;
			j=0;
			while(temp>0){
				j=j+temp%10;
				temp=temp/10;
			}
			sunuke2=(double)temp2/j;
			
//			printf("temp1=%lld,sunuke1=%lf,temp2=%lld,sunuke2=%lf\n",temp1,sunuke1,temp2,sunuke2);
			
			if(sunuke1<=sunuke2){
				k=k+1;
				printf("%lld\n",temp1);
			}else{
				k=k/10+1;
				s=s+1;
				printf("%lld\n",temp2);
			}
		}
		count++;
		if(count==n) return 0;
	}
	
	
//	printf("??????\n");
	
	//??
	
//	printf("???????\n");
	
} ./Main.c: In function ‘main’:
./Main.c:20:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^