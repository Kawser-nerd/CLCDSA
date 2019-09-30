#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
 
#define sl(x) scanf("%ld", &x)
#define ss(x) scanf("%s", x)
#define pl(x) printf("%ld\n", x)
#define ps(x) printf("%s\n", x)
 
#define INF 100000000000
#define MOD 1000000007
 
#define min(a,b) (((a)<(b))?(a):(b))
#define max(a,b) (((a)>(b))?(a):(b))
 
int main() {
	char S[100010];
	long i, j;
	long ans = 0;
	long state = 1;
	long len;
	
	ss(S);
	len = strlen(S);
	S[len] = S[len+1] = S[len+2] = S[len+3] = S[len+4] = 'z';
	S[len+5] = '\0';
	i = 0;
	while(i < len) {
		//printf("%ld: %ld (%c)->", state, i, S[i]);
		switch(state) {
		  case 1:
			if(S[i] == 'd' && S[i+1] == 'r' && S[i+2] == 'e' && S[i+3] == 'a' && S[i+4] == 'm') {
				state = 3;
				i += 5;
			} else if(S[i] == 'e' && S[i+1] == 'r') {
				state = 2;
				i += 2;
			} else {
				ps("NO");
				return 0;
			}
			break;
		  case 2:
			if(S[i] == 'a' && S[i+1] == 's' && S[i+2] == 'e' && S[i+3] == 'r') {
				state = 1;
				i += 4;
			} else if(S[i] == 'a' && S[i+1] == 's' && S[i+2] == 'e') {
				state = 3;
				i += 3;
			} else {
				ps("NO");
				return 0;
			}
			break;
		  case 3:
			if(S[i] == 'd' && S[i+1] == 'r' && S[i+2] == 'e' && S[i+3] == 'a' && S[i+4] == 'm') {
				state = 3;
				i += 5;
			} else if(S[i] == 'e' && S[i+1] == 'r' && S[i+2] == 'a') {
				state = 2;
				i += 2;
			} else if(S[i] == 'e' && S[i+1] == 'r') {
				state = 1;
				i += 2;
			} else {
				ps("NO");
				return 0;
			}
			break;
		}
		//printf("%ld: %ld\n", state, i);
	}
	
	if(state == 1 || state == 3) {
		ps("YES");
	} else {
		ps("NO");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:15: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 #define ss(x) scanf("%s", x)
               ^
./Main.c:24:2: note: in expansion of macro ‘ss’
  ss(S);
  ^