#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*31+(j))

int diff(char *a,char *b,int n){
  int cnt=0;
  int i;
  for(i=0;i<n;i++) if(a[i]!=b[i]) cnt++;
  return cnt;
}

void print(int index,int *dp,char *s,int size,int len){
  if(index!=0){
    int i;
    for(i=0;i<size;i++){
      if(dp[i]+1==dp[index] && diff(s+POS(i,0),s+POS(index,0),len)==1){
	print(i,dp,s,size,len);
	break;
      }
    }
  }
  printf("%s\n",s+POS(index,0));
  return;
}

void run(void){
  char first[31];
  char last[31];
  scanf("%s%s",first,last);
  int len=0;
  while(first[len]!='\0') len++;
  int n;
  scanf("%d",&n);
  char *s=(char *)malloc(sizeof(char)*(n+2)*31);
  int i;
  for(i=1;i<=n;i++) scanf("%s",s+POS(i,0));
  for(i=0;i<len;i++){
    s[POS(0,i)]=first[i];
    s[POS(n+1,i)]=last[i];
  }
  if(diff(s,s+POS(n+1,0),len)==0){
    printf("0\n");
    printf("%s\n",first);
    printf("%s\n",last);
    return;
  }
  int size=n+2;
  int *dp=(int *)malloc(sizeof(int)*size);
  int *q=(int *)malloc(sizeof(int)*size);
  for(i=0;i<size;i++) dp[i]=-1;
  dp[0]=0;
  q[0]=0;
  int l=0;
  int r=1;
  while(dp[size-1]==-1 && l<r){
    int v=q[l++];
    for(i=0;i<size;i++){
      if(dp[i]==-1 && diff(s+POS(v,0),s+POS(i,0),len)==1){
	dp[i]=dp[v]+1;
	q[r++]=i;
      }
    }
  }
  if(dp[size-1]==-1){
    printf("-1\n");
    return;
  }
  printf("%d\n",dp[size-1]-1);
  print(size-1,dp,s,size,len);
  return;
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:30:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s%s",first,last);
   ^
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:37:21: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=1;i<=n;i++) scanf("%s",s+POS(i,0));
                     ^