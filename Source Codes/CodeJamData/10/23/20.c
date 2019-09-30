#include<stdio.h>
#include<stdlib.h>

int matrix_c[500][500];
int matrix_f[500][500];

int comb(int n,int k){
	if(n==0 && k!=0) return 0;
	else if(n==0 && k==0) return 1;
	else if(n==k || k==0) return 1;
	else if(matrix_c[n][k] != 0) return matrix_c[n][k];
	else{
		int val =  (comb(n-1,k) + comb(n-1,k-1))%100003;
		matrix_c[n][k]=val;
		return val;
	}
}

int calc(int n, int c){
	
	// n denotes the number and c denotes the cardinality AND rank
	
	if(c==1) return 1;
	else if(matrix_f[n][c] != 0) return matrix_f[n][c];
	else{
		int k, val=0;
		for(k=1;k<=c-1;k++) 
			 val+=(calc(c,k)*comb(n-c-1, c-k-1))%100003;
		matrix_f[n][c]=val;
		return val;
	}
}

int main(){
	int case1, i, c, n, val;
	scanf("%d",&case1);
	for(i=0;i<case1;i++){
		scanf("%d",&n);
		val=0;
		for(c=1;c<=n-1;c++){
			val=(val+calc(n,c))%100003;
		}
		printf("Case #%d: %d\n",i+1, val);
	}
	return 0;
}
