#include <stdio.h>

int main(){
  int H,W;
  scanf("%d%d",&H,&W);
  int a[H+1][W+1];
  int i,j;
  for(i=1;i<=H;i++){
    for(j=1;j<=W;j++){
      scanf("%d", &a[i][j]);
      a[i][j]=a[i][j]%2;
    }
  }
  int ans[H*W][4];
  int k=0;
 
  for(i=1;i<=H;i++){
    if(i%2==1){
      for(j=1;j<=W;j++){
	if(a[i][j]==1){
	  if(j==W && i!=H){
	    a[i+1][W]=(a[i+1][W]+1)%2;
	    ans[k][0]=i;ans[k][1]=W;ans[k][2]=i+1;ans[k][3]=W;
	    k=k+1;
	  }
	  if(j!=W){
	    a[i][j+1]=(a[i][j+1]+1)%2;
	    ans[k][0]=i;ans[k][1]=j;ans[k][2]=i;ans[k][3]=j+1;
	    k=k+1;
	  }
	}
      }
    }
    if(i%2==0){
      for(j=W;1<=j;j--){
        if(a[i][j]==1){
          if(j==1 && i!=H){
            a[i+1][1]=(a[i+1][1]+1)%2;
            ans[k][0]=i;ans[k][1]=1;ans[k][2]=i+1;ans[k][3]=1;
            k=k+1;
          }
	  if(j!=1){
	    a[i][j-1]=(a[i][j-1]+1)%2;
	    ans[k][0]=i;ans[k][1]=j;ans[k][2]=i;ans[k][3]=j-1;
            k=k+1;
          }
        }
      }
    }
  }

  printf("%d\n",k);
  for(i=0;i<k;i++){
    printf("%d %d %d %d\n",ans[i][0], ans[i][1],ans[i][2],ans[i][3]);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&H,&W);
   ^
./Main.c:10:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d", &a[i][j]);
       ^