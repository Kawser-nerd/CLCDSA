#include <stdio.h>

int main(void){
  char w[101] = { '\0' };
  scanf("%s", w);
  char temp;
  int i,j;
  int n = 1;
  int flag = 1;
  while(w[n] != '\0') n++;
  for(i = 0; i < n; i++){
    for(j = i + 1; j < n; j++){
      if(w[i] < w[j]){
	temp = w[i];
	w[i] = w[j];
	w[j] = temp;
      }
    }
  }
  i = 0;
  while(w[i] != '\0'){
    if(w[i] == w[i + 1]) i += 2;
    else{
      flag = 0;
      break;
    }
  }
  if(flag) printf("Yes\n");
  else printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", w);
   ^