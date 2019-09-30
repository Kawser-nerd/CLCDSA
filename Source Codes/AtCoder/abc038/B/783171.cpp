#include <stdio.h>

int main(void){
	
	int w1,h1,w2,h2;
	
	scanf("%d %d",&w1,&h1);
	scanf("%d %d",&w2,&h2);
	
	if( w1 == w2 || w1 == h2 || h1 == w2 || h1 == h2 )
		printf("YES\n");
	else
		printf("NO\n");
	
	return 0;
}