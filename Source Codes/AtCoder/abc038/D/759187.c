#include <stdio.h>
#include <stdlib.h>
typedef struct{
  int w;
  int h;
}box;

int cmp( const void *p, const void *q ) {
  if((((box*)q)->w - ((box*)p)->w)!=0){
    return ((box*)q)->w - ((box*)p)->w;
  }else{
    return ((box*)p)->h - ((box*)q)->h;
  }
}

int main(void){
  int n;
  scanf("%d",&n);
  int i;
  box lst[n];
  for(i=0;i<n;i++){
    scanf("%d %d",&lst[i].w,&lst[i].h);
  }
  qsort(lst,n,sizeof(box),cmp);
  /*for(i=0;i<n;i++){
    printf("%d %d\n",lst[i].w,lst[i].h);
  }*/
  int dp[100010]={0};
  int max=0;
  dp[0]=lst[0].h;
  for(i=1;i<n;i++){
    int start=0,goal=max,k;
    while(goal-start>1){
      k=(start+goal)/2;
      if(dp[k]>lst[i].h){
        start=k;
      }else if(dp[k]<lst[i].h){
        goal=k;
      }else{
        break;
      }
    }
    if(dp[start]>lst[i].h){
      if(dp[start+1]<lst[i].h){
        if(start==max){max+=1;}
        dp[start+1]=lst[i].h;
      }else if(dp[start+1]>lst[i].h){
        if(dp[start+2]<lst[i].h){
          if(start+1==max){max+=1;}
          dp[start+2]=lst[i].h;
        }
      }
    }else if(start==0){
      dp[0]=lst[i].h;
    }
  }
  printf("%d\n",max+1);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:22:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&lst[i].w,&lst[i].h);
     ^