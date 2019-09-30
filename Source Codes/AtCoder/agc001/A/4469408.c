#include <stdio.h>
void InsertionSort(int a[],int k);
int main(void){
	int n,l[210],i,gu=0;
	scanf("%d",&n);
	for(i=0;i<(2*n);i++){
		scanf("%d",&l[i]);
	}
	InsertionSort(l,(n*2));
	for(i=0;i<(n*2);i+=2){
		gu+=(l[i]<=l[i+1])?l[i]:l[i+1];
	}
	printf("%d",gu);
	return 0;
}
void InsertionSort(int a[],int k){
	int i,j,v;
	for(i=1;i<=k-1;i++){
		v=a[i];
		j=i;
		while(a[j-1]>v && j>=1){
			a[j]=a[j-1];
			j--;
		}
		a[j]=v;
	}
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&l[i]);
   ^