#include <stdio.h>
#include <stdlib.h>

int main(void){
	char **hand;
	int no[3], turn = 0;
	hand = malloc(sizeof(char*) * 3);
	for(int i = 0; i < 3; i++){
		no[i] = 0;
		hand[i] = malloc(sizeof(char) * 100);
		scanf("%s", hand[i]);
	}
	while(1){
		if(hand[turn][no[turn]] == '\0'){
			printf("%c\n", 'A' + turn);
			break;
		}
		turn = hand[turn][no[turn]++] - 'a';
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", hand[i]);
   ^