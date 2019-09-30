#include <stdio.h>
#include <stdlib.h>
int main(void){
	int i;
	int N,x;
	if(scanf("%d %d", &N, &x)<2){
		exit(1);
	}
	int a[N];
	for (i=0; i<N; i++){
		if(scanf("%d",&a[i])<1){
			exit(1);
		}
	}
	long count;
	count = 0;
	if(a[0]+a[1]>x){
		count += (a[0]+a[1]-x);
		if(a[0]<=x){
			a[1]= x-a[0];
		}
		else{
			a[1]=0;
			a[0]=x;
		}
	}			
	for (i=1; i<N-1; i++){
		if (a[i]+a[i+1]>x){
			count += (a[i]+a[i+1]-x);
			a[i+1]=x-a[i];

		}
	}
	printf("%ld",count);
	
	
}