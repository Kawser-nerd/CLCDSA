#include<stdio.h>
#include<string.h>
 
int main(void){
	char str[100];
	scanf("%s",str);
	int b_letter[26];
	int dif[26];
	int i = 0;
	for(i = 0;i < 26;i++){
		b_letter[i] = -1;
		dif[i] = -1;
	}
	for(i = 0;i < strlen(str);i++){
		int temp = (int)(str[i] - 'a');
		if( i - b_letter[temp] -1 > dif[temp]){
			dif[temp] = i - b_letter[temp]-1;
		}
		b_letter[temp] = i;
		//printf("%d\n",temp);
	}
	int min = 100;
	for(i = 0;i < 26;i++){
		if(strlen(str) - b_letter[i] -1> dif[i])dif[i] = strlen(str) - b_letter[i]-1;
		//printf("%d \n",(dif[i]));
		if(dif[i] != -1 && min > dif[i])min = dif[i];
	}
	if(min > (strlen(str) + 1)/2){min = (strlen(str) + 1)/2;}
	printf("%d",min);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",str);
  ^