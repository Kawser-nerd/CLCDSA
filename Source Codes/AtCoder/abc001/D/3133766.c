#include<stdio.h>
#include<stdlib.h>

void itos(int a,char*s){
  s[3]='0'+a%10;
  s[2]='0'+(a/10)%10;
  s[1]='0'+(a/100)%10;
  s[0]='0'+a/1000;
  s[4]='\0';
}

int main(void){
  int i,j,k,n;
  char s[5],e[5];
  scanf("%d",&n);
  int*S=malloc(sizeof(int)*n);
  int*E=malloc(sizeof(int)*n);
  for(i=0;i<n;i++){
    scanf("%d-%d",&S[i],&E[i]);
    S[i]-=S[i]%5;
    if(E[i]%5)E[i]+=5-E[i]%5;
    if(E[i]%100==60)E[i]+=40;
  }
  int t[2401]={};
  for(i=0;i<n;i++)
    for(j=S[i];j<=E[i];j+=1)
      t[j]=1;
  for(i=0;i<=2400;i+=5)
    if(t[i]){
      itos(i,s);
      while(i<=2400&&t[++i]);
      i--;
      itos(i,e);
      printf("%s-%s\n",s,e);
    }
} ./Main.c: In function ‘main’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d-%d",&S[i],&E[i]);
     ^