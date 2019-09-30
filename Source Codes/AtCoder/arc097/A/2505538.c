#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int k;
char s[125252];
char sar[5*125252][10];

int comp(const void *a, const void *b){
  return strcmp(a,b);
}

int main(){
  scanf("%s%d",s,&k);
  int n = strlen(s);
  int it = 0;
  int i,len;  // c90
  for(i=0;i<n;i++){
    for(len=1;len<=5;len++)if(i+len<=n){
      strncpy(sar[it], s+i, len);
      sar[it][len] = '\0';
      it++;
    }
  }
  qsort(sar, it, sizeof(*sar), comp);
  int cnt = 0;
  for(i=0;i<it;i++){
    if(i==0 || strcmp(sar[i], sar[i-1])!=0){
      cnt++;
    }
    if(cnt == k){
      puts(sar[i]);
      break;
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%d",s,&k);
   ^