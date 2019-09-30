/*
 * main.c
 *
 *  Created on: 2019/03/09
 *      Author: family
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char S[200001] = {0};
char T[200001] = {0};

void change(char a, char b)
{
	int len = 0;
	int i = 0;
	len = strlen(S);
	for(i = 0; i < len; i++) {
		if(S[i] == a) {
			S[i] = b;
		} else if (S[i] == b) {
			S[i] = a;
		}
	}
}

int alp[256] = {0};
int alp2[256] = {0};

int main()
{
	int len = 0;
	int diff = 0;
	scanf("%s", S);
	scanf("%s", T);
	len = strlen(S);
	len -= 1;
	do {
		if (alp[(int)S[len]] == 0) {
			if (alp2[(int)T[len]] == 1) {
				diff++;
//				printf("len=%d, %c %c\n", len, T[len], S[len]);
			}
			alp[(int)S[len]] = T[len];
			alp2[(int)T[len]] = 1;
		} else {
			if (alp[(int)S[len]] == T[len]) {
				//
			} else {
				diff++;
//				printf("len=%d, %c %c\n", len, T[len], S[len]);
			}
		}
		//if (S[len] != T[len]) {
		//	change(S[len],T[len]);
		//}
		len--;
	} while (len >= 0);

	//diff = strncmp(S,T,len);
	if(diff == 0) {
		printf("Yes\n");
	} else {
		printf("No\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:38:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
./Main.c:39:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", T);
  ^