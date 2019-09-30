#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

void run(void){
  char s[27];
  scanf("%s",s);
  int len=0;
  while(s[len]!='\0') len++;
  if(len<26){
    char c='a';
    while(1){
      int i;
      for(i=0;i<len;i++){
	if(c==s[i]) break;
      }
      if(i==len){
	s[len]=c;
	s[len+1]='\0';
	printf("%s",s);
	return;
      }
      c++;
    }
  } else {
    int f[26];
    int i;
    for(i=0;i<26;i++) f[i]=0;
    for(i=len-1;i>=0;i--){
      int j;
      for(j=s[i]-'a'+1;j<26;j++){
	if(f[j]){
	  s[i]='a'+j;
	  printf("%s\n",s);
	  return;
	}
      }
      f[s[i]-'a']=1;
      s[i]='\0';
    }
  }
  printf("-1\n");
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^