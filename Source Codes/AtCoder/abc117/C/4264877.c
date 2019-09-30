#include <stdio.h>

int main(){

	int N;
	int M;	
	int ary[100000]={0};
	int bucket_1[200001]={0};
	int margin[99999]={0};
	int bucket_2[200000]={0};  
	int i,j,k;
	int notpass=0;
	
	
	scanf("%d %d",&N,&M);
	for(i=0;i<M;i++)
		scanf("%d",&ary[i]);
	
	
	if(M<=N){
	   printf("%d\n",0);
	   return 0;
	}
	
	
	///////// BucketSort_1 //////////
	for(i=0;i<M;i++)
		bucket_1[ary[i]+100000]=1;
	for(j=0,i=0;i<M;j++)
		if(bucket_1[j]!=0){
			ary[i]=j-100000;
			i++;
		}
	
	
	for(i=0;i<M-1;i++)
	    margin[i]=ary[i+1]-ary[i];
	
		
	///////// BucketSort_2 //////////
	for(i=0;i<M-1;i++)
		bucket_2[margin[i]-1]+=1;	
	for(i=0,j=0;i<M-1;j++)
		if(bucket_2[j]!=0){
			for(k=0;k<bucket_2[j];k++){
				margin[i]=j+1;
				i++;
			}
		}
	
		
	
	for(i=M-2;M-N-1<i;i--)
	   notpass+=margin[i];
	
	
	printf("%d\n",ary[M-1]-ary[0]-notpass);
	
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&ary[i]);
   ^