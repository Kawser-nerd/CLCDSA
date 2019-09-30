#include<stdio.h>

char c[100010];
int cnt[256],i,odd,sum;

int main(){
  fgets(c,100010,stdin);
  for(i=0;;i++){
    if(c[i]=='\0')break;
    cnt[c[i]]++;
  }

  for(i='a';i<='z';++i){
    if(cnt[i]&1) odd++;
    sum += cnt[i]>>1;
  }
  if(odd){
    printf("%d\n", ((sum/odd)<<1) + 1);
  }else{
    printf("%d\n", sum<<1);
  }
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(c,100010,stdin);
   ^