#include <stdio.h>

int main(void)
{
	char c,a,e,i,o,u;
	
	int x=0;
	
	scanf("%c",&c);
	
	char vowel[]={'a','e','i','o','u'};
	
	for(int i=0;i<5;i++){
		if(vowel[i]==c){
			x++;
		}
	}
	
	if(x!=0){
		printf("vowel\n");
	}else{
		printf("consonant\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&c);
  ^