#include <stdio.h>
#include <string.h>

int check(char *string, int spos, int len) {
	int i;
	
	for (i = spos+1; i <= len; i++)
		if (string[i] == '/' || i == len)
			return i;

	return 0;
}

int main() {

char string[1000][1000];
char temp[1000];
int T, t;
int n, N;
int m, M;
int k, leng, l;
int found;
long long result;

scanf("%d", &T);
for (t = 1; t <= T; t++) {
	result = 0LL;
	scanf("%d%d", &N, &M);
	for (n = 0; n < N; n++)
		scanf("%s", string[n]);
	
	for (m = 0; m < M; m++) {
		scanf("%s", temp);
		

		leng = strlen(temp);	
		for (k = 1; k < leng; k++) {
		//	printf("%d %d\n",k ,check(temp, k, leng));
			k = check(temp,k,leng);
			found = 0;
			for (l = 0; l < N; l++)
				if (strncmp(temp,string[l],k) == 0 && (string[l][k] == '/' || string[l][k] == '\0'))
					found = 1;
			if (found == 0) {
				result++;
			}
			
		}
				strncpy(string[N],temp,k);
				N++;
			
						
	}	
	printf("Case #%d: %lld\n", t, result);
}


return 0;
}
