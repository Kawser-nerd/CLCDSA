#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{	
	long i,fmax,y;
	int answer=0;
	double num;
	double snum=0.0;
	scanf("%lf",&num);

	snum=sqrt(num);

	for(i=1;i<=snum;i++){
		if((long)num%i == 0){
			y=i;
		}
	}

	fmax=(long)num/y;

	while(fmax!=0){
		fmax=fmax/10;
		answer++;
	}

	printf("%d\n",answer);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf",&num);
  ^