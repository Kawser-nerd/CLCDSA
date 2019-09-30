#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  char *s=(char *)malloc(sizeof(char)*(100000+1));
  scanf("%s",s);
  int n=0;
  while(s[n]!='\0') n++;
  int cnt[26]={0};
  int i;
  for(i=0;i<n;i++) cnt[s[i]-'a']++;
  int m=0;
  int l=0;
  for(i=0;i<26;i++){
    m+=cnt[i]/2;
    l+=cnt[i]%2;
  }
  if(l==0){
    printf("%d\n",2*m);
  } else {
    int ans=m/l*2+1;
    printf("%d\n",ans);
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^