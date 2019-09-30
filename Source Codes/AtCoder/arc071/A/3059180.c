#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define M 26

void run(void){
  int n;
  scanf("%d",&n);
  int min[M];
  int i;
  for(i=0;i<M;i++) min[i]=50;
  while(n--){
    char s[51];
    scanf("%s",s);
    int cnt[M]={0};
    for(i=0;s[i]!='\0';i++) cnt[s[i]-'a']++;
    for(i=0;i<M;i++) min[i]=MIN(min[i],cnt[i]);
  }
  for(i=0;i<M;i++){
    while(min[i]--) putchar('a'+i);
  }
  printf("\n");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^