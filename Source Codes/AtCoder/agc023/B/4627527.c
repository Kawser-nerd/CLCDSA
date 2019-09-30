#include<stdio.h>
#include<stdlib.h>

int isSymmetric(char *s,int n){
  int i,j;
  for(i=0;i<n;i++){
    for(j=i+1;j<n;j++){
      if(s[i*n+j]!=s[j*n+i]) return 0;
    }
  }
  return 1;
}

void run(void){
  int n;
  scanf("%d",&n);
  char *s=(char *)calloc(n*n+1,sizeof(char));
  int i,j,k;
  for(i=0;i<n;i++) scanf("%s",s+i*n);
  int ans=0;
  for(i=0;i<n;i++){
    if(isSymmetric(s,n)){
      ans+=n;
    }
    for(j=0;j<n;j++){
      char c=s[j*n];
      for(k=1;k<n;k++) s[j*n+k-1]=s[j*n+k];
      s[j*n+n-1]=c;
    }
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:19:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%s",s+i*n);
                    ^