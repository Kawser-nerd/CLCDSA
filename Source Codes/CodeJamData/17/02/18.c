#include <stdio.h>
#include <stdlib.h>

int istidy(long long k){
	int fromlast;
	int last = k % 10;
	k = k / 10;
	while(k>0){
		fromlast = k % 10;
		if (fromlast > last)
			return 0;
		last = fromlast;
		k = k / 10;
	}
	return 1;
}

int count(long long i) {
	int ret=1;
	while (i/=10) ret++;
	return ret;
}

void print_array(int *arr,int size){
	printf("printing array\n");
	int i;
	for (i=0;i<size;i++){
		printf("%d" , arr[i]);
	}
	printf("\n");
}
long long reconstruct(int *arr,int i, int j,int size){
	if (arr[i] == 0)
		arr[i] = 9;
	else
		arr[i] = arr[i] - 1;
	int k;
	for(k=i+1;k<size;k++)
		arr[k] = 9;
	long long ret = 0;
	size--;
	k = 0;
	while (size>=0){
		ret = 10*ret + arr[k];
		size --;
		k++;
	}
	//printf("return value is %llu\n" , ret);
	return ret;
}

long long newlong(long long num){
	int dig=count(num);
	int size = dig;
	int arr[dig];
	while (dig--) {
		arr[dig]=num%10;
		num/=10;
	}
	//print_array(arr,size);
	int i,j;
	for(i=size - 1;i>=0;i--){
		int flag = 0;
		for(j=i-1;j>=0;j--){
			if (arr[i]<arr[j]){
				flag = 1;
				break;
			}
		}
		if (flag == 1)
			break;
	}
	//printf("chacking for i ,j %d %d\n", i , j);
	return reconstruct(arr,j,i,size);
}

int main(){
	int T,i;
	scanf("%d", &T);
	for (i=1;i<=T;i++){
		long long N;
		scanf("%llu", &N);
		long long j = N;
		//printf("just read %llu\n" , N);
		while(j>0){
			if (istidy(j))
				break;
			j = newlong(j);
			//printf("new check %llu\n" , j);
		}
		printf("Case #%d: %llu\n",i,j);
	}
	return 0;
}