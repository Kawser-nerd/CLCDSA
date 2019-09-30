#include<stdio.h>
#include<string.h>
int c[20]={1};
char sa[100010],sb[100010],d[20][10]={"0"};
int f(int a,int b){//printf("%2d %2d %c %s\n",a,b,sa[a],sb+b);
  if(sa[a]+sb[b]==0)return 1;
  if(sa[a]*sb[b]==0)return 0;
  int i,j,n=sa[a]-'0';
  if(c[n]){//printf("!!%d\n",n);
    for(i=0;d[n][i];i++){
      if(d[n][i]-sb[b+i])return 0;
    }
    c[n]++;
    if(f(a+1,b+i))return 1;
    c[n]--;
    return 0;
  }
  for(i=1;i<4;i++){
    for(j=0;j<i;j++)d[n][j]=sb[b+j];
    d[n][j]=0;
    c[n]++;
    if(f(a+1,b+i))return 1;
    c[n]--;
  }
  return 0;
}      
int main(){
  int n,m,i;
  char a[10010],b[10010];
  sa[0]=sb[0]=0;
  scanf("%d %d",&n,&m);
  for(i=0;i<m;i++){
    scanf("%s %s",a,b);
    strcat(sa,a);
    strcat(sa,"0");
    strcat(sb,b);
    strcat(sb,"0");
  }
  //printf("%s\n%s\n",sa,sb);printf("%s\n",d[0]);
  //printf("%d\n",f(0,0));;
  f(0,0);
  for(i=0;i<n;i++)printf("%s\n",d[i+1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:31:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&m);
   ^
./Main.c:33:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s %s",a,b);
     ^