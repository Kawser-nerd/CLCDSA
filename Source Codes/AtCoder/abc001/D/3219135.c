#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int main(){
  int i,j,k;
  int n;
  int x,y;
  int l=0;

  scanf("%d",&n);

  int s[n];
  int e[n];

  for(i=0; i<=n-1; i++){
    scanf("%d-%d",&s[i],&e[i]);
  }

  for(i=0; i<=n-1; i++){
    if(s[i]%5!=0){
      s[i] = s[i] - (s[i]%5);
    }
    if(e[i]%5!=0){
      e[i] = e[i] - (e[i]%5) + 5;
      if((e[i]-60)%100==0){
        e[i] = e[i] + 40;
      }
    }
  }
  for(i=0; i<=n-1; i++){
    for(j=i+1; j<=n-1; j++){
      if(s[i]>s[j]){
        x = s[i];
        s[i] = s[j];
        s[j] = x;
        y = e[i];
        e[i] = e[j];
        e[j] = y;
      }
    }
  }
  for(i=0; i<=n-1; i++){
    //printf("%04d-%04d\n",s[i],e[i]);
  }

  for(i=0; i<=n-l-1; i++){
    if(e[i]>=s[i+1]){
      k = i;
      l++;
      if(e[k+1]>=e[k]){
        e[k] = e[k+1];
      }
      for(j=k+1; j<=n-1; j++){
        e[j] = e[j+1];
      }
      for(j=k+1; j<=n-1; j++){
        s[j] = s[j+1];
      }
      i=-1;
    }
    if(i==n-l-2){
      break;
    }
  }
  for(i=0; i<=n-l-1; i++){
    printf("%04d-%04d\n",s[i],e[i]);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d-%d",&s[i],&e[i]);
     ^