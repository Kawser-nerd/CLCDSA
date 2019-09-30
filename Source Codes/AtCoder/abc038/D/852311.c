#include <stdio.h>
#include <stdlib.h>
int n,n_;
typedef struct{
  int w;
  int h;
}BOX;

int dp[500000];
BOX box[100000];
BOX temp[100000];
int min(int a,int b){
  return a<b ? a:b;
}
int max(int a,int b){
  return b<a ?a:b;
}
void init(int x){
  n_=1;
  while(n_<x)n_*=2;
  n_*=2;
}
void update(int i,int x){
  i+=n_;
  while(i>0){
    dp[i]=max(dp[i],x);
    i >>=1;
  }
}
int query(int a,int b,int i,int l,int r){
  int res=0;
  int c;
  
  if(a<=l && r<=b)return dp[i];
  c=(l+r)/2;
  if(a<c)res=max(res,query(a,b,i*2,l,c));
  if(c<b)res=max(res,query(a,b,i*2+1,c,r));
  return res;
}
int compare_int(const void *a,const void *b){
  BOX test1 = *(BOX *)a;
  BOX test2 = *(BOX *)b;

  int tmp1 = test1.h;   
  int tmp2 = test2.h;

  return tmp1 - tmp2;

}

int comp2(const void *a,const void *b){
  BOX test1 = *(BOX *)a;
  BOX test2 = *(BOX *)b;

  int tmp1 = test1.w;   
  int tmp2 = test2.w;

  return tmp2 - tmp1;
}
void print(){
  int i;
  for(i=0;i<16;i++)printf("%d ",dp[i]);
  printf("\n");
}
int main(){
  int i,j,k;
  int x;
  scanf("%d",&n);
  for(i=0;i<n;i++){
    scanf("%d %d",&box[i].w,&box[i].h);
  }
  qsort(box,n,sizeof(BOX),compare_int);
  i=0;j=0;
  while(i<n){
    while(box[i].h==box[j].h && j<n)j++;
    for(k=0;k<j-i;k++){
      temp[k]=box[i+k];
    }
    qsort(temp,j-i,sizeof(BOX),comp2);
    for(k=0;k<j-i;k++){
      box[i+k]=temp[k];
    }
    i=j;
  }
  // printf("\n");
  //for(i=0;i<n;i++)printf("%d %d\n",box[i].w,box[i].h);
  init(100000);
  int ans=0,now;
  for(i=0;i<n;i++){
    x=box[i].w;
    now=query(0,x,1,0,n_)+1;
    ans=max(ans,now);
    update(x,now);
  }
  
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:68:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&n);
   ^
./Main.c:70:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&box[i].w,&box[i].h);
     ^