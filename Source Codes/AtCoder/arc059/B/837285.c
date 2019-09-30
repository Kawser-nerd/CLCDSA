#include<stdio.h>
#include<string.h>

int main(void){
  int i,j,k,l;
  char str[100001];
  scanf("%s",str);
  l=strlen(str);

  if(l==2){
    puts(str[0]==str[1]?"1 2":"-1 -1");
    return 0;
  }

  for(i=0;i<l-2;i++){
    if(str[i]==str[i+1] || str[i]==str[i+2] || str[i+1]==str[i+2]){
      printf("%d %d\n",i+1,i+3);
      return 0;
    }
  }
  puts("-1 -1");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",str);
   ^