#include <stdio.h>
#include <string.h>

char s[32];

char *adjust(char *s, int len)
{
	int i, k;
	for(i = 0; i < len - 1; i++){
		if(s[i] > s[i + 1]){
			s[i]--;
			for(k = i + 1; k < len; k++){
				s[k] = '9';
			}
			i = -1;
		}
	}
	for(i = 0; i < len; i++){
		if(s[i] != '0') break;
	}
	return &s[i];
}

int main(int argc, char *argv[])
{
	int T, i, k;
	scanf("%d", &T);
	for(i = 0; i < T; i++){
		scanf("%s", s);
		printf("Case #%d: %s\n", i + 1, adjust(s, strlen(s)));
	}
	return 0;
}
