#include <stdio.h>

void Qsort(int x[], int left, int right);
void swap(int x[],int i,int j);

int main(void){
	int n;
	scanf("%d",&n);
	int a[n];
	int i;
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++){
		while(a[i]%2==0){
			a[i]=a[i]/2;
		}
	}
	Qsort(a,0,n-1);
	int sum=1;
	int now=a[0];
	for(i=1;i<n;i++){
		if(now!=a[i]){
			sum++;
		}
		now=a[i];
	}
	printf("%d\n",sum);
}


	
void Qsort(int x[], int left, int right){
	int i,j;
	int pivot;
	i=left;
	j=right;
	pivot=x[(left+right)/2];
	while(1){
		while(x[i]<pivot)
			i++;
		while(pivot<x[j])
			j--;
		if(i>=j)
			break;
		swap(x,i,j);
		i++;
		j--;
	}
	if(left<i-1)
		Qsort(x,left,i-1);
	if(j+1<right)
		Qsort(x,j+1,right);
}

void swap(int x[],int i,int j){
	int temp;
	temp=x[i];
	x[i]=x[j];
	x[j]=temp;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&a[i]);
   ^