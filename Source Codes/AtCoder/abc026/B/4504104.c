#include <stdio.h>
void InsertionSort(double r[],int n){
	int i,j,v;
	for(i=1;i<=n;i++){
		v=r[i];
		j=i;
		while(r[j-1]<v && j>=1){
			r[j]=r[j-1];
			j--;
		}
		r[j]=v;
	}
}

int main(void){
	int n,i;
	double r[1001],v=0,pi=3.1415926535;
	scanf("%lld",&n);
	for(i=0;i<n;i++){
		scanf("%lf",&r[i]);
	}
	InsertionSort(r,n);
	for(i=0;i<n;i++){
		if(i%2==0) v+=r[i]*r[i]*pi;
		else v-=r[i]*r[i]*pi;
	}
	printf("%f\n",v);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:8: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘int *’ [-Wformat=]
  scanf("%lld",&n);
        ^
./Main.c:18:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf",&r[i]);
   ^