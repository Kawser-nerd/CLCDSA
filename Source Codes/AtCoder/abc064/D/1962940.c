#include<stdio.h>
int main (void){
 char s[201]="\0";
 int n,i,w=0,m=0,h=0;
 scanf("%d",&n);
 scanf("%s",s);
 for(i=0;i<n;i++){
  if(w){
   if(s[i]=='('){
    h++;
   }else{
    h--;
    if(!h)
     w--;
   }
  }else{
   if(s[i]=='('){
    w++;
    h++;
   }else{
    m++;
   }
  }
 }
 if(m){
  n+=m;
  for(i=n-1;i>=m;i--)
   s[i]=s[i-m];
  for(i=0;i<m;i++)
   s[i]='(';
 }
 if(h){
  for(i=n;i<n+h;i++)
   s[i]=')';
 }
 s[n+h]='\0';
 printf("%s\n",s);
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^