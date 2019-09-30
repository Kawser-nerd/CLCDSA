#include<stdio.h>
int N, R[1000], ans, i, j;
double answer;

med3(int x, int y, int z);
void quickSort(int a[], int left, int right);
void sort(int a[], int size);

int main(){
	scanf("%d", &N);
	for(i=0; i<N; i++){
		scanf("%d", R+i);
	}
	sort(R, N);
	j=1;
	for(i=0; i<N; i++){
		ans += R[i]*R[i]*j;
		j *= -1;
	}
	answer = 3.14159265358979323;
	answer *= ans;
	printf("%.20f\n", answer);
}

int med3(int x, int y, int z){
	if(x < y){
		if (y < z){return y;}else if(z < x){return x;}else{return z;}
	} else {
		if (z < y){return y;}else if(x < z){return x;}else{return z;}
	}
}

void quickSort(int a[], int left, int right){
	if(left >= right){return;}
	int pivot = med3(a[left], a[left+(right-left)/2], a[right]);
	int l=left, r=right;
	while(1){
		while (a[l] > pivot){l++;}
		while (pivot > a[r]){r--;}
		if(l>=r){break;}
		int t=a[l]; a[l]=a[r]; a[r]=t;
		l++; r--;
	}
	quickSort(a, left, l-1);
	quickSort(a, r+1, right);
}

void sort(int a[], int size){
	quickSort(a, 0, size-1);
} ./Main.c:5:1: warning: data definition has no type or storage class
 med3(int x, int y, int z);
 ^
./Main.c:5:1: warning: type defaults to ‘int’ in declaration of ‘med3’ [-Wimplicit-int]
./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", R+i);
   ^