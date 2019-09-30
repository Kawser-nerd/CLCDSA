#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void run(void){
  int n,m;
  scanf("%d%d",&n,&m);
  int *a=(int *)calloc(n*m,sizeof(int));
  int i,j,k;
  for(i=0;i<n*m;i++){
    scanf("%d",a+i);
    a[i]--;
  }
  int *cnt=(int *)calloc(m,sizeof(int));
  int min=n;
  for(i=0;i<m;i++){
    memset(cnt,0,sizeof(int)*m);
    for(j=0;j<n;j++){
      for(k=0;k<m;k++){
	if(a[j*m+k]>=0){
	  cnt[a[j*m+k]]++;
	  break;
	}
      }
    }
    int max=0;
    for(j=1;j<m;j++) if(cnt[max]<cnt[j]) max=j;
    if(min>cnt[max]) min=cnt[max];
    for(j=0;j<n*m;j++) if(a[j]==max) a[j]=-1;
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&m);
   ^
./Main.c:11:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",a+i);
     ^