#include <stdio.h>

int main(void){
  int n;
  scanf("%d",&n);
  int count = 0;
  int tmp,i;
  char city[21];
  int max = 0;
  char tmp2[21];
  for(i = 0;i<n;i++){
    scanf("%s %d",tmp2,&tmp);
    count += tmp;
    if(max < tmp){
      memset(city,'\0',sizeof(char) * 21);
      max = tmp;
      memcpy(city,tmp2,sizeof(char) * 21);
    }
  }
  if(count / 2 < max){
    printf("%s\n",city);
  }else{
    printf("atcoder\n");
  }
} ./Main.c: In function ‘main’:
./Main.c:15:7: warning: implicit declaration of function ‘memset’ [-Wimplicit-function-declaration]
       memset(city,'\0',sizeof(char) * 21);
       ^
./Main.c:15:7: warning: incompatible implicit declaration of built-in function ‘memset’
./Main.c:15:7: note: include ‘<string.h>’ or provide a declaration of ‘memset’
./Main.c:17:7: warning: implicit declaration of function ‘memcpy’ [-Wimplicit-function-declaration]
       memcpy(city,tmp2,sizeof(char) * 21);
       ^
./Main.c:17:7: warning: incompatible implicit declaration of built-in function ‘memcpy’
./Main.c:17:7: note: include ‘<string.h>’ or provide a declaration of ‘memcpy’
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:12:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %d",tmp2,&tmp);
     ^