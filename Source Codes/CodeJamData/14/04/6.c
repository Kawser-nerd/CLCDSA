#include<stdio.h>
#include<stdlib.h>

int comp(const void *p1,const void *p2);


int main(void){
  int t,n,i,j,k,pDW,pW,count;
  double *blockN,*blockK;

  scanf("%d",&t);
  for(k=1;k<=t;k++){
    count=pDW=pW=0;
    scanf("%d",&n);
    blockN=(double *)calloc(n,sizeof(double));
    blockK=(double *)calloc(n,sizeof(double));
    for(i=0;i<n;i++) scanf("%lf",&blockN[i]);
    for(i=0;i<n;i++) scanf("%lf",&blockK[i]);

    qsort(blockN,n,sizeof(double),comp);
    qsort(blockK,n,sizeof(double),comp);
    /*
    for(i=0;i<n;i++) printf("%f%c",blockN[i],(i==n-1)?'\n':' ');
    for(i=0;i<n;i++) printf("%f%c",blockK[i],(i==n-1)?'\n':' ');
    //*/
    for(i=0;i<n;i++)
      if(blockN[count]<blockK[i]) count++;
    pW=n-count;

    pDW=n;
    i=j=0;
    while(i<n){
      if(blockN[i]<blockK[0]){
	pDW--;
      }else{
	if(blockN[i]<blockK[j]){
	  pDW--;
	}else{
	  j++;
	}
      }
      i++;
    }	
  
    printf("Case #%d: %d %d\n",k,pDW,pW);
    free(blockN);
    free(blockK);
  }
  return 0;
}
      
int comp(const void *p1,const void *p2){
  double d1,d2;
  d1=(*(const double *)p1);
  d2=(*(const double *)p2);
  if(d1-d2<0) return -1;
  else return 1;
}


    
