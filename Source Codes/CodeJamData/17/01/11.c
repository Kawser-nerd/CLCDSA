#include <stdio.h>
#include <string.h>

char buf[100][1024];
int bufLen[100];
int K[100];
char pat[1024];

int check(char *s, int len, int K)
{
	int i, k, count = 0;
	for(i = 0; i < len; i++){
		pat[i] = 0;
	}
	for(i = 0; i < len - K + 1; i++){
		if(pat[i] == s[i]){
			for(k = 0; k < K; k++){
				if(i + k >= len) return -1;
				pat[i + k] ^= 1;
			}
			count++;
		}
	}
	for(; i < len; i++){
		if(pat[i] == s[i]) return -1;
	}
	return count;
}

int main(int argc, char *argv[])
{
	int T, i, k;
	scanf("%d", &T);
	for(i = 0; i < T; i++){
		scanf("%s %d", buf[i], &K[i]);
		bufLen[i] = strlen(buf[i]);
		for(k = 0; k < bufLen[i]; k++){
			buf[i][k] = (buf[i][k] == '+') ? 1 : 0;
		}
	}
	for(i = 0; i < T; i++){
		k = check(buf[i], bufLen[i], K[i]);
		if(k == -1){
			printf("Case #%d: IMPOSSIBLE\n", i + 1);
		} else{
			printf("Case #%d: %d\n", i + 1, check(buf[i], bufLen[i], K[i]));
		}
	}
	
	return 0;
}
