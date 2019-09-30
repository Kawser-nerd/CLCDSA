#include<stdio.h>
#include<stdint.h>
#include<string.h>
#include<math.h>
int main(){
  int i,j,k,N,s[26],t[26],l;
  char c[50];
  int8_t *p;
  for(j=0;j<26;++j)s[j]=10000;
  
  scanf("%d\n",&N);
  //  printf("%d\n",N);
  for(i=N;i;--i){
    p=c;
    gets(c);
    //    puts(c);
    l=strlen(c);
    for(j=0;j<26;++j)t[j]=0;
    for(j=0;j<l;++j){
      ++t[*p++-97];
    }
    //    for(j=0;j<26;++j)printf("%d",t[j]);
    //    puts("");

    for(j=0;j<26;++j){
      //      if(t[j])if(s[j]>t[j])s[j]=t[j];
      //if(!t[j])t[j]=10000;
      if(s[j]>t[j])s[j]=t[j];
    }
    //    for(i=0;i<26;++i)
    //printf("%d %d\n",i+97,s[i]);

    //    puts("");
  }
  //  puts("");
  //  for(j=0;j<26;++j)printf("%d",t[j]);
      
  for(i=0;i<26;++i)
    if(s[i]!=0)
      for(j=0;j<s[i];++j)printf("%c",i+97);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:5: warning: implicit declaration of function ‘gets’ [-Wimplicit-function-declaration]
     gets(c);
     ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d\n",&N);
   ^
/tmp/ccPWitwF.o: In function `main':
Main.c:(.text.startup+0x76): warning: the `gets' function is dangerous and should not be used.