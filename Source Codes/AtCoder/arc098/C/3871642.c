#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
  return *(int *)a-*(int *)b;
}

void run(void){
  int n,k,q;
  scanf("%d%d%d",&n,&k,&q);
  int *a=(int *)calloc(n,sizeof(int));
  int i;
  for(i=0;i<n;i++) scanf("%d",a+i);
  int *tmp=(int *)calloc(n,sizeof(int));
  int *pop=(int *)calloc(n,sizeof(int));
  int ans=1000000000;
  for(i=0;i<n;i++){
    int plen=0;
    int j=0;
    while(j<n){
      int tlen=0;
      while(j<n && a[j]>0) tmp[tlen++]=a[j++];
      if(tlen>=k){
	qsort(tmp,tlen,sizeof(int),cmp);
	for(int p=0;p<tlen-k+1;p++) pop[plen++]=tmp[p];
      }
      j++;
    }
    if(plen<q) break;
    qsort(pop,plen,sizeof(int),cmp);
    int t=pop[q-1]-pop[0];
    if(ans>t) ans=t;
    for(j=0;a[j]==0;j++);
    int min=j;
    for(j++;j<n;j++) if(a[j]>0 && a[j]<a[min]) min=j;
    a[min]=0;
  }
  printf("%d\n",ans);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&n,&k,&q);
   ^
./Main.c:13:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(i=0;i<n;i++) scanf("%d",a+i);
                    ^