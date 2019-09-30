#include <stdio.h>


int main(){
	int h,m;
	int hour,min;
	hour = 17;
	min = 60;
	scanf("%d %d\n",&h,&m);
	hour -=h;
	min -=m;
	if(m==60){
		min=0;
		hour++;
	}
	printf("%d\n",hour*60+min);
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d\n",&h,&m);
  ^