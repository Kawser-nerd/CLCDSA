#include<stdio.h>
int main(void){
	
	int i,N,X,m[100];
	scanf("%d%d",&N,&X);
	
	for(i=0;i<N;i++){
		scanf("%d",&m[i]);
	}
	
	for(i=0;i<N;i++){
		X=X-m[i];
	}
	
	int m_min=m[0];
	
	for(i=1;i<N;i++){
		if(m_min>m[i]){
			m_min=m[i];
		}
	}
	
	int m_min_tuikakosuu=1;
	
	
	if(X>=m_min_tuikakosuu*m_min){
	while(X>=m_min_tuikakosuu*m_min){
		m_min_tuikakosuu++;
	}
	
	printf("\n%d\n\n",N+m_min_tuikakosuu-1);
	}else {
		printf("\n%d\n\n",N);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&N,&X);
  ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&m[i]);
   ^