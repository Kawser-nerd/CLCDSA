#include<stdio.h>

int main(){
  int n,i,flag=0,j;
  char b;
  char s[100001];
  char a[4][100002];
  scanf("%d",&n);
  scanf("%s",s);
  a[0][0]=a[0][1]=a[1][0]=a[2][1]='S';
  a[1][1]=a[2][0]=a[3][0]=a[3][1]='W';
  for(i=0;i<4;i++){
    if((a[i][0]=='S'&&a[i][1]=='S'&&s[0]=='o')||(a[i][0]=='W'&&a[i][1]=='S'&&s[0]=='x')||(a[i][0]=='S'&&a[i][1]=='W'&&s[0]=='x')||(a[i][0]=='W'&&a[i][1]=='W'&&s[0]=='o'))
        b='S';
      else
        b='W';
    for(j=1;j<n;j++){
      if((a[i][j-1]=='S'&&a[i][j]=='S'&&s[j]=='o')||(a[i][j-1]=='W'&&a[i][j]=='S'&&s[j]=='x')||(a[i][j-1]=='S'&&a[i][j]=='W'&&s[j]=='x')||(a[i][j-1]=='W'&&a[i][j]=='W'&&s[j]=='o'))
        a[i][j+1]='S';
      else
        a[i][j+1]='W';
    }
    if(a[i][0]==a[i][n]&&b==a[i][n-1]){
      a[i][n]='\0';
      printf("%s\n",a[i]);
      return 0;
    }
  }
  printf("-1\n");
} ./Main.c: In function ‘main’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^