#include <stdio.h>
#include <stdlib.h>
int count(int *a,int N);
int med3(int x, int y,int z);
void quicksort(int a[], int left, int right);
int main()
{
	int N,K,*a,i,j,var,sum=0;
	scanf("%d %d",&N,&K);
	a=(int *)malloc(sizeof(int)*N);
	if(a==NULL) {
		fprintf(stderr,"Cannot allocation\n");
		return 1;
	}
	for(i=0;i<N;i++) a[i]=0;
	for(i=0;i<N;i++) {
		scanf("%d",&j);
		a[j-1]++;
	}
	if((var=count(a,N))<=K) {
		printf("0\n");
		return 0;
	} else {
		quicksort(a,0,N-1);
 		for(i=N-1,j=0;j<K;i--,j++) {
			sum+=a[i];
		}
		printf("%d\n",N-sum);
	}
	free(a);
	return 0;
}
int count(int *a,int N)
{
	int i,j=0;
	for(i=0;i<N;i++) {
		if(a[i]!=0) j++;
	}
	return j;
}

int med3(int x, int y,int z) {
    if (x < y) {
        if (y < z) return y; else if (z < x) return x; else return z;
    } else {
        if (z < y) return y; else if (x < z) return x; else return z;
    }
}

void quicksort(int a[], int left, int right) {
    if (left<right) {
        int i=left,j=right;
        int tmp,pivot=med3(a[i], a[i + (j - i) / 2], a[j]); 
        while(1) { 
            while (a[i]<pivot) i++; 
            while (pivot<a[j]) j--; 
            if (i>=j) break;
            tmp=a[i];a[i]=a[j];a[j]=tmp; 
            i++;j--;
        }
        quicksort(a, left, i - 1);
        quicksort(a, j + 1, right);
    }
} ./Main.c: In function ‘main’:
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&K);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&j);
   ^