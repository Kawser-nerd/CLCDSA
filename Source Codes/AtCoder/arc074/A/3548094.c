#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void)
{
	//?????
	long int h,w;
	int i,j,k;
	long int ans;
	long int max,min;
	
	//????????
	scanf("%ld %ld",&h,&w);
	
	
	
//	printf("n?%d??\n", n);
//	printf("??????????\n");
	//?????
	
	if(h%3==0||w%3==0){
		printf("0");
		return 0;
	}else if(h<w){
		ans=h;
	}else{
		ans=w;
	}
	
	for(i=1;i<h;i++){
		max=i*w;
		min=i*w;
		if((w/2)*(h-i)>max) max=(w/2)*(h-i);
		if((w/2)*(h-i)<min) min=(w/2)*(h-i);
		if(((w+1)/2)*(h-i)>max) max=((w+1)/2)*(h-i);
		if(((w+1)/2)*(h-i)<min) min=((w+1)/2)*(h-i);
		
		if(max-min<ans) ans=max-min;
	}
	
	for(i=1;i<w;i++){
		max=i*h;
		min=i*h;
		if((h/2)*(w-i)>max) max=(h/2)*(w-i);
		if((h/2)*(w-i)<min) min=(h/2)*(w-i);
		if(((h+1)/2)*(w-i)>max) max=((h+1)/2)*(w-i);
		if(((h+1)/2)*(w-i)<min) min=((h+1)/2)*(w-i);
		
		if(max-min<ans) ans=max-min;
	}
	
	
//	printf("??????\n");
	
	//??
	printf("%ld",ans);
	
//	printf("???????\n");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld %ld",&h,&w);
  ^