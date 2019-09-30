#include<stdio.h>
char *P[]={"No", "Yes"};
char s[100][11], l[100], c;
short n, i, j;
int main(){
  register char k, r, f;
  scanf("%hd\n", &n);
  while((c=getchar())!=10){s[0][l[0]++]=c;}
  f=1;
  for(i=1; i<n; i++){
    while((c=getchar())!=10){s[i][l[i]++]=c;}
    if(s[i][0]!=s[i-1][l[i-1]-1]){f=0; break;}
    r=l[i];
    for(j=0; j<i; j++){
      if(l[j]!=r){continue;}
      f=0;
      for(k=0; k<r; k++){
        if(s[i][k]!=s[j][k]){f=1; break;}
      }
      if(!f){break;}
    }
    if(!f){break;}
  }
  puts(P[f]);
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%hd\n", &n);
   ^