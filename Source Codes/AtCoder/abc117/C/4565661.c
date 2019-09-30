#include<stdio.h>
#include<stdlib.h>

int cmp1(const void *,const void *);
int cmp2(const void *,const void *);

int
main()
{
  	int n,m;
  	scanf("%d %d",&n,&m);
  	int x[m];
  	int i;
  	int goukei=0;
	int margin[m-1];
 	
  	if(m==1){
      	goukei=0;
        goto NEXT;
    }
  
  	for(i=0;i<m;i++){
      	scanf("%d",&x[i]);
    }
  	qsort(x,sizeof(x)/sizeof(int),sizeof(int),cmp1);
  
  	for(i=0;i<m-1;i++){
      	margin[i]=x[i+1]-x[i];
    }

  
  	qsort(margin,sizeof(margin)/sizeof(int),sizeof(int),cmp2);

  	
  	for(i=n-1;i<m-1;i++){
      	goukei += margin[i];
    }
  
  NEXT:
  	printf("%d",goukei);
  
  	return 0;
  
}

int
cmp1(const void *a,const void *b){
	return *(int *)a-*(int *)b;
}

int
cmp2(const void *a,const void *b){
	return *(int *)b-*(int *)a;
} ./Main.c: In function ‘main’:
./Main.c:11:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d %d",&n,&m);
    ^
./Main.c:23:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%d",&x[i]);
        ^