#include<stdio.h>

int min(int a,int b){if(a<b){return a;}return b;}

int n;

char s[1024];

char cl[8]="ABYX";

int calc(int a,int b,int c,int d){
  int r=0,i=0;
  while(i<n){
    r++;
    if(s[i]==cl[a]&&s[i+1]==cl[b]){i+=2;}
    else if(s[i]==cl[c]&&s[i+1]==cl[d]){i+=2;}
    else{i++;}
  }
  return r;
}

int main(){
  int r=114514,i,j,k,l;
  scanf("%d%s",&n,s);
  for(i=0;i<4;i++){
    for(j=0;j<4;j++){
      for(k=0;k<4;k++){
        for(l=0;l<4;l++){
          r=min(r,calc(i,j,k,l));
        }
      }
    }
  }
  printf("%d\n",r);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:24:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%s",&n,s);
   ^