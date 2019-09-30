#include <stdio.h>

int main(int argc, char *argv[])
{
  int s;
  scanf("%d", &s);

  int a[1000000];
  int i = 1;
  a[0] = s;

  while(i < 1000000){
    if(a[i - 1] % 2 == 0){
      a[i] = a[i - 1] / 2;
    }
    else{
      a[i] = 3 * a[i - 1] + 1;
    }
    i++;
  }

  int j = 2;

  while(j != -1){
    for(int k = j - 1; k >= 0; k--){
      if(a[j] == a[k]){
	printf("%d\n", j + 1);
	j = -1;
	break;
      }
      else if(k == 0){
	j++;
      }
    }
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &s);
   ^