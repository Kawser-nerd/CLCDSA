#include <stdio.h>
#include <stdlib.h>
typedef struct{
	int	P;
	int	Y;
	int	NUM;
	int ID1;
	int ID2;
}City;

int cmp_Y( const void *p, const void *q ) {
    return ((City*)p)->Y - ((City*)q)->Y;
}
int cmp_NUM( const void *p, const void *q ) {
    return ((City*)p)->NUM - ((City*)q)->NUM;
}

int main(void){
	int N,M;
	int i,j;
	int Numberofoccurrences[100001]={};
	scanf("%d %d",&N,&M);
	City city[M];
	for(i=0;i<M;i++){
		scanf("%d %d",&city[i].P,&city[i].Y);
		city[i].NUM=i+1;
	}
	int n = sizeof city / sizeof( City );
	qsort( city, n, sizeof(City), cmp_Y );
	/*
	for(i=0;i<M;i++){
		printf("%d %d %d\n",city[i].P,city[i].Y,city[i].NUM);
	} 
	*/
	/*
	Y[i]????????????????????
	NUM[i]?????????????????OK
	*/
	for(i=0;i<M;i++){
		Numberofoccurrences[city[i].P]++;
		city[i].ID1 = city[i].P;
		city[i].ID2 = Numberofoccurrences[city[i].P];
	}
	qsort( city, n, sizeof(City), cmp_NUM );
	
	for(i=0;i<M;i++){
		printf("%06d",city[i].ID1);
		printf("%06d",city[i].ID2);
		printf("\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&N,&M);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&city[i].P,&city[i].Y);
   ^