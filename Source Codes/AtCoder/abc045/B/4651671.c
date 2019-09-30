#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define TLong long long 

int main(int argc, char const *argv[]){
	int player = 0,turn[3] = {0,-1,-1};
	char card[3][120];
	scanf("%s %s %s",card[0],card[1],card[2]);
	for (int i = 0; i < strlen(card[0]) + strlen(card[1]) + strlen(card[2]); ++i){
		switch(card[player][turn[player]]){
			case 'a':
				player = 0;
				break;
			case 'b':
				player = 1;
				break;
			case 'c':
				player = 2;
				break;
		}
		if(++turn[player] > strlen(card[player])){
			printf("%c\n", (player + 0x41));
			return 0;
		}
	}
	printf("%c\n", (player + 0x41));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %s %s",card[0],card[1],card[2]);
  ^