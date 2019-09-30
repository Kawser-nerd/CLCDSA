#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define ABS(x) (((x)<0)?(-(x)):(x))

int main(void){
  char str[2][100001]={"",""};
  int num[2][100001][2]={{{0}}};
  int i,j,k,q,a[2],b[2],t,l;
  int snum[2];

  for(i=0;i<2;i++){
    scanf("%s%*c",str[i]);
    num[i][0][0]=(str[i][0]=='A');
    num[i][0][1]=(str[i][0]=='B');
    l=strlen(str[i]);
    for(j=1;j<l;j++){
      for(k=0;k<2;k++)
	num[i][j][k]=num[i][j-1][k]+(str[i][j]==('A'+k));
    }
  }
  scanf("%d",&t);
  while(t--){
    scanf("%d%d%d%d",&a[0],&b[0],&a[1],&b[1]);
    for(i=0;i<2;i++){
      a[i]--;
      b[i]--;
      snum[i]=(num[i][b[i]][0]-num[i][a[i]][0]+(str[i][a[i]]=='A'))-(num[i][b[i]][1]-num[i][a[i]][1]+(str[i][a[i]]=='B'));
      //printf("snum=%d,a=%d,b=%d\n",snum[i],num[i][b[i]][0]-num[i][a[i]][0]+(str[0][a[i]]=='A'),num[i][b[i]][1]-num[i][a[i]][1]+(str[0][a[i]]=='B'));
      if(snum[i]>=0) snum[i]%=3;
      else{
	snum[i]+=(ABS(snum[i])+3)/3*3;
	snum[i]%=3;
      }
    }
    puts(snum[0]==snum[1]?"YES":"NO");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%*c",str[i]);
     ^
./Main.c:23:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^
./Main.c:25:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d%d%d",&a[0],&b[0],&a[1],&b[1]);
     ^