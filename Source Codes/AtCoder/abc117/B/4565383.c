#include<stdio.h>
#include<stdlib.h>

int cmp(const void *,const void *);

int
main()
{
  	int N;
  	scanf("%d",&N);
  	int L[N];
  	int i;
  	for (i=0;i<N;i++){
      	scanf("%d",&L[i]);
    }
  
  	qsort(L,sizeof(L)/sizeof(int),sizeof(int),cmp);
  	
  	int goukei=0;
  	for (i=1;i<N;i++){
      	goukei += L[i];
    }
  	
  	if(L[0]<goukei){
      	printf("Yes");
    }else{
      	printf("No");
    }
  
  	return 0;
 
}

int
cmp(const void *a,const void *b){
	return *(int *)b- *(int *)a;
} ./Main.c: In function ‘main’:
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d",&N);
    ^
./Main.c:14:8: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
        scanf("%d",&L[i]);
        ^