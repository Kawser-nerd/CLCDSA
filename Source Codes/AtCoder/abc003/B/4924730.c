#include <stdio.h>
#include<string.h>

int main()
{
	char S[10];
	char W[10];
	int count;
	scanf("%s", S);
	scanf("%s", W);

	for (int i = 0; i < strlen(S); i++) {
		if (S[i] == W[i]) {
			count++;
		}else if (S[i] == '@') {
			if ((W[i] == 'a') || (W[i] == 't') || (W[i] == 'c') || (W[i] == 'o') || (W[i] == 'd') || (W[i] == 'e') || (W[i] == 'r')){
				count++;
			}
		}else if(W[i]=='@'){
			if ((S[i] == 'a') || (S[i] == 't') || (S[i] == 'c') || (S[i] == 'o') || (S[i] == 'd') || (S[i] == 'e') || (S[i] == 'r')) {
				count++;
			}
		}
	}

	if (strlen(S) == count) {
		printf("You can win\n");
	}
	else {
		printf("You will lose\n");
	}


	return 0;

} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", S);
  ^
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s", W);
  ^