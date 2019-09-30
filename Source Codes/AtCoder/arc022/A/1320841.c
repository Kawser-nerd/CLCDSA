#include <stdio.h>
#include<string.h>


int main(void)
{
	int i,a=0,b=0,c=0,lon;
	char s[101];
	scanf("%s",s);
	
	lon=strlen(s);
	
	for(i=0;i<lon;i++){
		if(s[i]=='i' || s[i]=='I'){
			a=i;
			break;
		}
	}
	
	for(i=a;i<lon;i++){
		if(s[i]=='c' ||s[i]=='C'){
			b=i;
			break;
		}
	}
	
	for(i=b;i<lon;i++){
		if(s[i]=='t' || s[i]=='T'){
			c=i;
			break;
		}
	}
	
	
	if(a<b && b<c){
		printf("YES\n");
	} else{
		printf("NO\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^