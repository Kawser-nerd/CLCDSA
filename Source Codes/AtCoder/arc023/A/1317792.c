#include <stdio.h>
#include <string.h>


int main(void)
{
	int y,m,d,sum,a,b,c,e;
	scanf("%d %d %d",&y,&m,&d);
	
	if(m==1){
		y--;
		m=13;
	} else if(m==2){
		y--;
		m=14;
	}
	
	a=y/4;
	b=y/100;
	c=y/400;
	e=306*(m+1)/10;
		
	sum=365*y+a-b+c+e+d-429;
	
	printf("%d\n",735369-sum);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&y,&m,&d);
  ^