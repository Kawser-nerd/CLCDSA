#include <stdio.h>
#include <string.h>

int main(void) {
  char S[11];
  char T[11];
  scanf("%s", S);
  scanf("%s", T);
  char A[] = {'@', 'a', 't', 'c', 'o', 'd', 'e', 'r'};
  int len = strlen(S);
  for(int i = 0; i < len; i++) {
    int ok = 0;
    if(S[i] == T[i]) {
      ok = 1;
    } else if (S[i] == '@') {
      for(int j = 0; j < 8; j++) {
	if(T[i] == A[j]) {
	  ok = 1;
	  break;
	}
      }
    } else if (T[i] == '@') {
      for(int j = 0; j < 8; j++) {
	if(S[i] == A[j]) {
	  ok = 1;
	  break;
	}
      }
    }

    if(ok == 0) {
      printf("You will lose\n");
      return 0;
    }
  }

  printf("You can win\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", T);
   ^