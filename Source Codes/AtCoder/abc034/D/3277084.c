#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
  double p=*(double *)a;
  double q=*(double *)b;
  return p==q?0:p<q?-1:1;
}

void run(void){
  int n,k;
  scanf("%d%d",&n,&k);
  int *w=(int *)malloc(sizeof(int)*n);
  double *p=(double *)malloc(sizeof(double)*n);
  int i;
  for(i=0;i<n;i++){
    int pp;
    scanf("%d%d",w+i,&pp);
    p[i]=(double)pp/100;
  }
  double *a=(double *)malloc(sizeof(double)*n);
  double l=0;
  double r=1;
  for(i=0;i<60;i++){
    double m=(l+r)*0.5;
    int j;
    for(j=0;j<n;j++) a[j]=(p[j]-m)*w[j];
    qsort(a,n,sizeof(double),cmp);
    double sum=0;
    for(j=0;j<k;j++) sum+=a[n-1-j];
    if(sum>=0){
      l=m;
    } else {
      r=m;
    }
  }
  printf("%.9f\n",100*l);
}

int main(void){
  run();
  return 0;
} ./Main.c: In function ‘run’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&n,&k);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d",w+i,&pp);
     ^