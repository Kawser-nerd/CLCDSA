#include <stdio.h>

int main(void){
	char s[11];
	scanf("%s",s);
	int year = (s[0]-'0')*1000 + (s[1]-'0')*100 + (s[2]-'0')*10 + (s[3]-'0');
	int month= (s[5]-'0')*10 + (s[6]-'0');
	int day = (s[8]-'0')*10 + (s[9]-'0');
	if( year > 2019){
		printf("TBD");
		return 0;
	}else if(month>4){
		printf("TBD");
		return 0;
	}else if(day>30){
		printf("TBD");
		return 0;
	}
	printf("Heisei");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^