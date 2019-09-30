#include<stdio.h>
int main(){
  long long i,c=1,M=1e9+7,d[100010][3]={};
  char s[100010];
  scanf("%s",s);
  for(i=0;s[i];i++){
    d[i+1][0]=d[i][0];
    d[i+1][1]=d[i][1];
    d[i+1][2]=d[i][2];
    if(s[i]=='A')d[i+1][0]=(d[i+1][0]+c      )%M;
    if(s[i]=='B')d[i+1][1]=(d[i+1][1]+d[i][0])%M;
    if(s[i]=='C')d[i+1][2]=(d[i+1][2]+d[i][1])%M;
    if(s[i]=='?'){
      d[i+1][0]=(d[i+1][0]*3+c      )%M;
      d[i+1][1]=(d[i+1][1]*3+d[i][0])%M;
      d[i+1][2]=(d[i+1][2]*3+d[i][1])%M;
      c=(c*3)%M;
    }

      
    //if(s[i]=='A'||s[i]=='?')d[i+1][0]+=(+1      )%M;
    //if(s[i]=='B'||s[i]=='?')d[i+1][1]+=(d[i][0]+d[i][1]*3)%M;
    //if(s[i]=='C'||s[i]=='?')d[i+1][2]+=(d[i][1]+d[i][2]*3)%M;
  }
  printf("%lld\n",d[i][2]);
  //for(i=1;s[i-1];i++)printf("%lld %lld %lld\n",d[i][0],d[i][1],d[i][2]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^