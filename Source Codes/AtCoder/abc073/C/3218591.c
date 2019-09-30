#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
	int *A = (int *)a;
	int *B = (int *)b;
	if (*A > *B) return 1;
	if (*A < *B) return -1;
	return 0;
}
int main(){
	int N;
	scanf("%d",&N);
	int A[N];
	for(int i=0;i<N;i++)scanf("%d",&A[i]);
	qsort(A,N,sizeof(int),compare);
	int ans=0;
	int c=1;
	for(int i=0;i<N-1;i++){
		if(A[i]==A[i+1])c++;
		else{
			if(c%2==1)ans++;
			c=1;
		}
	}
	if(c%2==1)ans++;
	printf("%d\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:15:22: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(int i=0;i<N;i++)scanf("%d",&A[i]);
                      ^