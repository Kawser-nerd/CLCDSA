#include<cstdio>
#include<cstring>

char S[51];

int main() {
	scanf("%s", S);
	char ch = S[strlen(S)-1];
	if(ch == 'T') {
		printf("YES\n");
	} else {
		printf("NO\n");
	}
	return 0;
}