#include <stdio.h>
#include <string.h>
int main(){
  char s[101] = {0};
  char cmp[101] = {0};
  int num[101] = {0};

  scanf("%s", s);

  //  printf("strlen = %lu\n", strlen(s));
  for(int cnt = 0; cnt < strlen(s); cnt++){
    if(cnt == 0){
      cmp[0] = s[0];
    }
    //    printf("? cnt = %d\n", cnt);
    for(int n = 0; n < strlen(cmp); n++){
      //      printf("cmp[%d] = %c, s[%d] = %c\n", n, cmp[n], cnt, s[cnt]);
      if(cmp[n] == s[cnt]){
	num[n]++;
	//	printf("match\n");
	break;
      }
      else if(n == strlen(cmp) - 1){
	cmp[n + 1] = s[cnt];
	//	printf("cmp[n] = %c  %lu no same\n", cmp[n], strlen(cmp));
	num[n+1]++;
	break;
      }
    }
  }

  for(int cnt = 0; cnt < strlen(cmp); cnt++){
    //    printf("cmp[%d] = %c, num[%d] = %d\n", cnt, cmp[cnt], cnt, num[cnt]);
    if(num[cnt] % 2 == 0){
      if(cnt == strlen(cmp)-1){
	printf("Yes");
      }
    }else{
      printf("No");
      break;
    }
  }
  
  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^