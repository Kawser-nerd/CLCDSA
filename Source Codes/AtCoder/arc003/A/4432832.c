#include <stdio.h>

int main(void)

{
	int n;
	char r[110];
	double sum=0.0;
	
	scanf("%d%s",&n,r);
	
	int i=0;
	
	while(i<n){
		if(r[i]=='A'){
			sum=sum+4.0;
		}else if(r[i]=='B'){
			sum=sum+3.0;
		}else if(r[i]=='C'){
			sum=sum+2.0;
		}else if(r[i]=='D'){
			sum=sum+1.0;
		}
		
		i++;
	}
	
	printf("%.14f\n",sum/(double)n);
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%s",&n,r);
  ^