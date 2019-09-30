#include"stdio.h"
#include"stdlib.h"
#include"string.h"

int main(){

	char str[1000];
	int count,half,i,flag=0;

	scanf("%s", str);
	//printf("%s\n", str);
	
	count = strlen(str);
	half = count / 2;

	for (i = 0; half > i; i++){
		if ((str[i] == str[count - 1 - i]) || (str[i] == '*') || str[count - 1 - i] == '*'){
			flag = 0;
		}
		else{
			flag = 1;
			break;
		}
	}
	//printf("%d\n", flag);
	
	if (flag == 0){
		printf("YES\n");
	}
	else{
		printf("NO\n");
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", str);
  ^