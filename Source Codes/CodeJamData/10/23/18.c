#include<stdio.h>
#include<stdlib.h>

int C_MAT[500][500];
int F_MAT[500][500];

int C(int n,int k){
	if(n==0 && k!=0) return 0;
	else if(n==0 && k==0) return 1;
	else if(n==k || k==0) return 1;
	else if(C_MAT[n][k] != 0) return C_MAT[n][k];
	else{
		int val =  (C(n-1,k) + C(n-1,k-1))%100003;
		C_MAT[n][k]=val;
		return val;
	}
}

int F(int n, int c){
	
	// n denotes the number and c denotes the cardinality AND rank
	
	if(c==1) return 1;
	else if(F_MAT[n][c] != 0) return F_MAT[n][c];
	else{
		int k, val=0;
		for(k=1;k<=c-1;k++) 
			 val+=(F(c,k)*C(n-c-1, c-k-1))%100003;
		F_MAT[n][c]=val;
		return val;
	}
}

int main(){
	int cases, i, c, n, val;
	scanf("%d",&cases);
	for(i=0;i<cases;i++){
		scanf("%d",&n);
		val=0;
		for(c=1;c<=n-1;c++){
			val=(val+F(n,c))%100003;
		}
		printf("Case #%d: %d\n",i+1, val);
	}
	return 0;
}
