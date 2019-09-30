#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void run(void){
  int n,m,k;
  scanf("%d%d%d",&n,&m,&k);
  int a[10],b[10];
  int i;
  for(i=0;i<m;i++) scanf("%d%d",a+i,b+i);
  const int trial=1000000;
  int cnt=0;
  srand((unsigned)time(NULL));
  for(i=0;i<trial;i++){
    int id[11];
    int j;
    for(j=0;j<n;j++) id[j]=j;
    for(j=0;j<k;j++){
      int p=rand()%n;
      int q=(rand()%(n-1)+p+1)%n;
      int swap=id[p];
      id[p]=id[q];
      id[q]=swap;
    }
    for(j=0;j<m;j++){
      int l;
      for(l=0;l<n;l++){
	if(id[l]!=a[j]) continue;
	if(id[(l+1)%n]==b[j] || id[(l+n-1)%n]==b[j]) break;
      }
      if(l<n) break;
    }
    if(j>=m) cnt++;
  }
  printf("%.9f\n",(double)cnt/trial);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&m,&k);
   ^
./Main.c:10:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<m;i++) scanf("%d%d",a+i,b+i);
                    ^