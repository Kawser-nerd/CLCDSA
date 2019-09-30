#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
  int n,idx,num,max=0,total=0;
  char s[100001];
  char ans_s[100001];
  scanf("%d",&n);
  for(int i=0; i<n; i++) {
    scanf("%s%d",s,&num);
    if(num>max) {
      idx=i;
      max=num;
      strcpy(ans_s,s);
    }
    total+=num;
  }
  if(max*2>total) printf("%s\n",ans_s);
  else printf("atcoder\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%d",s,&num);
     ^