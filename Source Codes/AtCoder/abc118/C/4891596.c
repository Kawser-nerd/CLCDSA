#include <stdio.h>
#include <stdlib.h>
int compare_int(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}
int main(void){
	int N;
	scanf("%d",&N);    
	int A[N];
	int i,min;
	for(i=0;i<N;i++){
		scanf("%d",&A[i]);
	}
	//??A[]??????
	qsort(A,N,sizeof(int),compare_int);
	int check(){
		int flag = 0;
		for(i=0;i<N;i++){
			if(A[i]>0){
				flag++;
			}
			if(flag>1){
				return 1;
			}
		}
		return 0;
	}
	//0?????????????????????????
	while(check() >0){
		i=0;
		while(A[i]<=0 && i<N){
			i++;
		}
		min = i;
		for(i=i+1;i<N;i++){
			A[i]=A[i]%A[min];
		}
		qsort(A,N,sizeof(int),compare_int);
	}
	int ans = A[N-1];
	printf("%d",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);    
  ^
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&A[i]);
   ^