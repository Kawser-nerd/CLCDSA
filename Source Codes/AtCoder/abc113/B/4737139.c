#include<stdio.h>
#include<math.h>
int main(void){
	
	int N,i;
	double T,H[1000],A,aveT[1000];
	
	scanf("%d",&N);
	scanf("%lf%lf",&T,&A);
	for(i=0;i<N;i++){
		scanf("%lf",&H[i]);
	}
	
	for(i=0;i<N;i++){
		aveT[i]=T-H[i]*0.006;
	}
	
	int bangou=0;
	double sub=fabs(A-aveT[0]);
	
	for(i=1;i<N;i++){
		if(fabs(A-aveT[i])<sub){
			sub=fabs(A-aveT[i]);
			bangou=i;
		}
	}	
		
	printf("\n%d\n\n",bangou+1);	
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&N);
  ^
./Main.c:9:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lf%lf",&T,&A);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lf",&H[i]);
   ^