#include<stdio.h>

int a[50][50]={},w,h,box[2500][2],rear=-1,front=0;

int bfs(int i,int j){
  int b;
  rear++;
  if(i==h-1&&j==w-1)
    return a[i][j];
  if(i>0&&a[i-1][j]==0){
    box[front][0]=i-1;
    box[front++][1]=j;
    a[i-1][j]=a[i][j]+1;
  }
  if(j>0&&a[i][j-1]==0){
    box[front][0]=i;
    box[front++][1]=j-1;
    a[i][j-1]=a[i][j]+1;
  }
  if(i<h-1&&a[i+1][j]==0){
    box[front][0]=i+1;
    box[front++][1]=j;
    a[i+1][j]=a[i][j]+1;
  }
  if(j<w-1&&a[i][j+1]==0){
    box[front][0]=i;
    box[front++][1]=j+1;
    a[i][j+1]=a[i][j]+1;
  }
  if(front>rear)
    b=bfs(box[rear][0],box[rear][1]);
  else return -1;
  return b;
}

int main(){
  int i,j,cnt=0,b;
  char s[50];
  scanf("%d %d",&h,&w);
  for(i=0;i<h;i++){
    scanf("%s",s);
    for(j=0;j<w;j++){
      if(s[j]=='#'){
        a[i][j]=-1;
        cnt++;
      }
    }
  }
  a[0][0]=1;
  b=bfs(0,0);
  if(b!=-1)
    printf("%d\n",w*h-b-cnt);
  else printf("-1\n");
} ./Main.c: In function ‘main’:
./Main.c:39:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&h,&w);
   ^
./Main.c:41:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",s);
     ^