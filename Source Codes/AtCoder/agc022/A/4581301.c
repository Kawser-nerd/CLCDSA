#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void run(void){
  char s[27];
  scanf("%s",s);
  int n=strlen(s);
  if(n<26){
    int used[26]={0};
    int i;
    for(i=0;i<n;i++) used[s[i]-'a']=1;
    for(i=0;used[i];i++);
    s[n]='a'+i;
    s[n+1]='\0';
    puts(s);
    return;
  }
  int can[26]={0};
  for(int i=n-1;i>=0;i--){
    int k=s[i]-'a';
    can[k]=1;
    int j;
    for(j=k+1;j<26 && !can[j];j++);
    if(j<26){
      s[i]='a'+j;
      s[i+1]='\0';
      puts(s);
      return;
    }
  }
  puts("-1");
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^