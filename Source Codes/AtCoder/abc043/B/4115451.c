#include <stdio.h>

int main(void){
	char str[15];
	int i = 0;
	while((str[i] = getchar()) != '\n'){
		if(str[i] == 'B' && i != 0){
			i--;
			str[i] = '\0';
			continue;
		}else if(str[i] == 'B')continue;
		i++;
	}
	str[i] = '\0';
	printf("%s\n", str);
	return 0;
}