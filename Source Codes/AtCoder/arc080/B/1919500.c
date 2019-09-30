#include<stdio.h>
int main(){
	int A[110][110],i,j,a,b,B[10010],n,k=1;
	scanf("%d%d",&a,&b);
	scanf("%d",&n);
	for(i=1;i<=n;i++) scanf("%d",&B[i]);
	for(i=1;i<=a;i++){
		if(i%2!=0){
			for(j=1;j<=b;j++){
				A[i][j]=k;
				B[k]--;
				if(B[k]==0) k++;
			}
		}
		else{
			for(j=b;j>=1;j--){
				A[i][j]=k;
				B[k]--;
				if(B[k]==0) k++;
			}
		}
	}
	for(i=1;i<=a;i++){
		for(j=1;j<b;j++){
			printf("%d ",A[i][j]);
		}
		printf("%d\n",A[i][b]);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:6:20: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  for(i=1;i<=n;i++) scanf("%d",&B[i]);
                    ^