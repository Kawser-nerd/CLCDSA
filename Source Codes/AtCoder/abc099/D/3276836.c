#include<stdio.h>
#include<stdlib.h>

#define POS(i,j) ((i)*c+(j))

void run(void){
  int n,c;
  scanf("%d%d",&n,&c);
  int *d=(int *)malloc(sizeof(int)*c*c);
  int i,j;
  for(i=0;i<c*c;i++) scanf("%d",d+i);
  int *cnt=(int *)calloc(3*c,sizeof(int));
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      int m;
      scanf("%d",&m);
      m--;
      cnt[POS((i+j)%3,m)]++;
    }
  }
  int min=1000*n*n;
  int x,y,z;
  for(x=0;x<c;x++){
    for(y=0;y<c;y++){
      for(z=0;z<c;z++){
	if(x==y || y==z || z==x) continue;
	int sum=0;
	for(i=0;i<c;i++){
	  sum+=cnt[POS(0,i)]*d[POS(i,x)];
	  sum+=cnt[POS(1,i)]*d[POS(i,y)];
	  sum+=cnt[POS(2,i)]*d[POS(i,z)];
	}
	if(min>sum) min=sum;
      }
    }
  }
  printf("%d\n",min);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&c);
   ^
./Main.c:11:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<c*c;i++) scanf("%d",d+i);
                      ^
./Main.c:16:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&m);
       ^