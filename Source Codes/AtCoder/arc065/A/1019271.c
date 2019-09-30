#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() {
	char S[1000000];
	
	scanf("%s", S);
	int i;
	for(i = 0; i < strlen(S); i++) {
		if (S[i] == 'd') {
			if(S[++i] != 'r') {
				printf("NO");
				return 0;
			}
			if(S[++i] != 'e') {
				printf("NO");
				return 0;
			}
			if(S[++i] != 'a') {
				printf("NO");
				return 0;
			}
			if(S[++i] != 'm') {
				printf("NO");
				return 0;
			}
			if(S[i+1] == 'e') {
				if(S[i+2] == 'r') {
					if(S[i+3] != 'a') {
						i += 2;
					}
				}
			}
		} else if (S[i] == 'e') {
			if(S[++i] != 'r') {
				printf("NO");
				return 0;
			}
			if(S[++i] != 'a') {
				printf("NO");
				return 0;
			}
			if(S[++i] != 's') {
				printf("NO");
				return 0;
			}
			if(S[++i] != 'e') {
				printf("NO");
				return 0;
			}
			if(S[i + 1] == 'r')
					i++;
		} else {
			printf("NO");
			return 0;
		}
	}
	printf("YES");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^