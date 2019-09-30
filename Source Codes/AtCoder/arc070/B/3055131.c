#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef long long int int64;

#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define ABS(a) ((a)>(0)?(a):-(a))

#define POS(i,j) ((i)*k+(j))

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *a=(int *)malloc(sizeof(int)*n);
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);

  char *front=(char *)calloc(k*(n+1),sizeof(char));
  front[POS(0,0)]=1;
  for(i=0;i<n;i++){
    int j;
    for(j=0;j<k;j++) front[POS(i+1,j)]=front[POS(i,j)];
    for(j=k-1;j>=a[i];j--){
      if(front[POS(i,j-a[i])]==0) continue;
      front[POS(i+1,j)]=1;
    }
  }
  char *back=(char *)calloc(k*(n+1),sizeof(char));
  back[POS(n,0)]=1;
  for(i=n-1;i>=0;i--){
    int j;
    for(j=0;j<k;j++) back[POS(i,j)]=back[POS(i+1,j)];
    for(j=k-1;j>=a[i];j--){
      if(back[POS(i+1,j-a[i])]==0) continue;
      back[POS(i,j)]=1;
    }
  }
  int ans=n;
  for(i=0;i<n;i++){
    int l,r;
    l=0;
    r=k-1;
    while(l<k && r>=0){
      while(l<k && front[POS(i,l)]==0) l++;
      while(r>=0 && back[POS(i+1,r)]==0) r--;
      if(l<k && r>=0 && l+r<k && l+r+a[i]>=k){
	ans--;
	break;
      } else if(l+r>=k){
	r--;
      } else {
	l++;
      }
    }
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:18:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^