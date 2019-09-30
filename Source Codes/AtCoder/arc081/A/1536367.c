#include <stdio.h>
#include <stdlib.h>

int compare( const int *v1, const int *v2 ){
	return *v1 - *v2;
}

int main(){
	
	int n, i;
	int a[100000];
	
	scanf( "%d", &n );
	for( i = 0; i < n; i++ ){
		scanf( "%d", &(a[i]) );
	}
	qsort( a, n, sizeof(int), 
		(int (*)(const void *, const void *))compare );

	long long int edge1 = -1;
	long long int edge2 = -1;
	i = n-1;
	while( i > 0 ){
		if( a[i] == a[i-1] ){
			if( edge1 == -1 ){
				edge1 = (long long int)a[i];
				i = i - 2;
				
			}else{
				edge2 = (long long int)a[i];
				i = 0;
			}
		}else{
			i = i - 1;
		}
	}
	
	if( edge2 == -1 ){
		printf("0");
		
	}else{
		printf("%lld", edge1 * edge2 );
		
	}
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf( "%d", &n );
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf( "%d", &(a[i]) );
   ^