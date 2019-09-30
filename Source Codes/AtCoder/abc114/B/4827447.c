#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int main(void){
	char s[11];
	scanf("%s",s);
	int i;
	int min = 999999;
	int n = strlen(s);
	for(i=0;i<n-2;i++){
		int temp = (s[i]-'0')*100 + (s[i+1]-'0')*10 + (s[i+2]-'0')*1;
		int difference = abs(753 - temp);
		if( min > difference){
			min = difference;
		}	
	}
	printf("%d",min);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^