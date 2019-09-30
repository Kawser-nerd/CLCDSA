#include <stdio.h>

static int N;
static int B[100];

int search(int i, int *data) {
  if(i == 0) {
    return 1;
  }

  for(int j = (i-1); j >= 0; j--) {
    if(data[j] == (j+1)) {
      int newdata[100];
      int dst = 0;
      int OK =1;
      for(int k = 0; k < i; k++) {
	if(k != j) {
	  newdata[dst++] = data[k];
	  if(data[k] >= i) {
	    OK = 0;
	    break;
	  }
	}
      }
      if(OK == 0) continue;
      int ret = search(i-1, newdata);
      if(ret == 1) {
	printf("%d\n", (j+1));
	return 1;
      }
    }
  }
  return 0;
}

int main(void) {
  scanf("%d", &N);

  int OK = 1;
  for(int i = 0; i < N; i++) {
    scanf("%d", &B[i]);
    if(B[i] > (i+1)) {
      OK = 0;
    }
  }
  if(OK == 0) {
    printf("-1\n");
  } else if(search(N, B) == 0) {
    printf("-1\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:37:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:41:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &B[i]);
     ^