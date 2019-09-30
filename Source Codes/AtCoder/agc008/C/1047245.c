#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(void){
	unsigned long i,o,t,j,l,s,z;
	unsigned long k=0;
	
	scanf("%lu %lu %lu %lu %lu %lu %lu",&i,&o,&t,&j,&l,&s,&z);
	
	k+=o;
	unsigned long wa=i+j+l;
	
	if((i%2==1 && j%2==1 && l%2==1) || (i%2==0 && j%2==0 && l%2==0)){
		k+=wa;
	}
	else if(wa!=2){
		k+=(wa-1);
	}
	
	printf("%lu\n",k);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lu %lu %lu %lu %lu %lu %lu",&i,&o,&t,&j,&l,&s,&z);
  ^