#include<stdio.h>
char *P[]={"No","Yes"};
char f;

char s[101], t[201], c;
int n, i, j;
int main(){
  while((c=getchar())!=10){s[n++]=c;}
  while((c=getchar())!=10){t[i]=c;t[n+i++]=c;}
  for(i=0; i<n; i++){
    f=1;
    for(j=0; j<n; j++){
      if(s[j]!=t[i+j]){f=0; break;}
    }
    if(f){break;}
  }
  puts(P[f]);
}