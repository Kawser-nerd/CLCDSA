#include<stdio.h>
short max(short a, short b){return a<b?b:a;}
short n, m, ans, now, i, j;
char S[100][11], T[100][11], c;
char s[100], t[100];
char done[100];
int main(){
  scanf("%hd\n", &n);
  for(i=0; i<n; i++){
    while((c=getchar())!=10){S[i][s[i]++]=c;}
  }
  scanf("%hd\n", &m);
  for(i=0; i<m; i++){
    while((c=getchar())!=10){T[i][t[i]++]=c;}
  }
  register char f, r, k;
  for(i=0; i<n; i++){
    if(done[i]){continue;}
    now = 0;
    r=s[i];
    for(j=0; j<n; j++){
      if(s[j]!=r){continue;}
      f=1;
      for(k=0; k<r; k++){
        if(S[i][k]!=S[j][k]){f=0; break;}
      }
      if(f){done[j]=1; now++;}
    }
    for(j=0; j<m; j++){
      if(t[j]!=r){continue;}
      f=1;
      for(k=0; k<r; k++){
        if(S[i][k]!=T[j][k]){f=0; break;}
      }
      if(f){now--;}
    }
    ans=max(ans, now);
  }
  printf("%d\n", max(ans, 0));
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%hd\n", &n);
   ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%hd\n", &m);
   ^