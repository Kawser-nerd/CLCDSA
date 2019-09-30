#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  char *s=(char *)malloc(sizeof(char)*(100000+1));
  char *t=(char *)malloc(sizeof(char)*(100000+1));
  scanf("%s",s);
  scanf("%s",t);
  int slen=0;
  while(s[slen]!='\0') slen++;
  int tlen=0;
  while(t[tlen]!='\0') tlen++;
  int *scnt=(int *)malloc(sizeof(int)*(slen+1));
  int *tcnt=(int *)malloc(sizeof(int)*(tlen+1));
  scnt[0]=0;
  int i;
  for(i=0;i<slen;i++){
    scnt[i+1]=(scnt[i]+(s[i]=='A'?1:-1)+3)%3;
  }
  tcnt[0]=0;
  for(i=0;i<tlen;i++){
    tcnt[i+1]=(tcnt[i]+(t[i]=='A'?1:-1)+3)%3;
  }
  int q;
  scanf("%d",&q);
  while(q--){
    int a,b,c,d;
    scanf("%d%d%d%d",&a,&b,&c,&d);
    int ans=(scnt[b]-scnt[a-1]+3)%3==(tcnt[d]-tcnt[c-1]+3)%3;
    printf("%s\n",ans?"YES":"NO");
  }
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",t);
   ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&q);
   ^
./Main.c:35:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&a,&b,&c,&d);
     ^