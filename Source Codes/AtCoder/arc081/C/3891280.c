#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void run(void){
  char *a=(char *)malloc(sizeof(char)*(200000+1));
  scanf("%s",a);
  const int n=strlen(a);
  int *stack=(int *)calloc(n/26+2,sizeof(int));
  int top=0;
  stack[top++]=n;
  int i,j;
  i=n-1;
  while(i>=0){
    int elem[26]={0};
    int cnt=0;
    j=i;
    while(j>=0 && cnt<26){
      int k=a[j]-'a';
      if(!elem[k]) cnt++;
      elem[k]=1;
      j--;
    }
    if(cnt<26) break;
    stack[top++]=j+1;
    i=j;
  }
  char *ans=(char *)calloc(top+1,sizeof(char));
  int len=0;
  int from=0;
  while(top>0){
    int up=stack[--top];
    int elem[26]={0};
    for(i=from;i<up;i++) elem[a[i]-'a']=1;
    for(i=0;elem[i];i++);
    ans[len++]='a'+i;
    for(from=up;from<n && a[from]!=ans[len-1];from++);
    from++;
  }
  printf("%s\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",a);
   ^